#include <iostream>
#include <fstream>
#include <cctype>
#include <Windows.h>
#include <locale.h>

using namespace std;

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, NULL);

    if (argc != 2) {
        cout << "Usage: SystemProgramming 파일명" << endl;
        return 0;
    }

    ifstream fin(argv[1], ios::in | ios::binary);
    if (!fin) {
        cout << argv[1] << "를 찾지 못합니다" << endl;
        return 0;
    }
    const int nReads = 16;
    char data[nReads];
    char mem[256]; //출력할거랑 출력 안할거랑 구분
    char disMem[nReads + 1];

    memset(mem, '.', 256);
    for (int ch = 0; ch < 256; ch++)
    {
        if (isprint(ch))
            mem[ch] = ch;
    } //아스키코드 printable char 확인 

    size_t offset = 0;
    while (!fin.eof()) // '\0'가 나올때 까지
    {
        fin.read(data, nReads); //성공적으로 읽은 함수가 몇개 인가?
        auto len = fin.gcount();
        
        memset(disMem, ' ', nReads);

        printf("%08llX   ", offset);
        for (int i = 0; i < nReads; i++)
        {
            if (i < len)
                printf("%02X ", data[i] & 0xff);
            else
                printf("   ");

            disMem[i] = mem[data[i] & 0xff];
        }
        disMem[nReads] = NULL;
        cout << disMem << endl; //실제 내용을 보여줌
        offset += fin.gcount();
    }
    fin.close();
    
    return 0;
}
