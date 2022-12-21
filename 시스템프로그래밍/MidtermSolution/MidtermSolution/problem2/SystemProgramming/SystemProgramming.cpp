#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include "Base64.h"

using namespace std;
using namespace macaron;

unsigned long long readLonglong(ifstream& fin)
{
    unsigned long long value = 0;
    fin.read((char *) &value, sizeof(size_t));
    return value;
} //64비트 기준


string readString(ifstream& fin, bool decode = false)
{
    size_t len = readLonglong(fin);
    char* buf = new char[len + 1];

    fin.read((char*)buf, sizeof(char) * len);
    buf[len] = NULL; //문자열 기본적인 부분을 충족 시킴

    string input = buf;
    delete[] buf;

    string output = input;
    if (decode) Base64::Decode(input, output);

    return output;
}


int main(int argc, char* argv[])
{
    setlocale(LC_ALL, NULL);

    if (argc != 2)
    {
        cout << "Usage: SystemProgramming 파일명" << endl;
        return 0;
    }
    ifstream fin(argv[1], ios::in | ios::binary);

    fin.seekg(0, ios::end); //파일크기를 알기 위해서 설정
    auto endPos = fin.tellg();
    fin.seekg(0, ios::beg);
    auto pos = fin.tellg();

    int nRecords = 0;
    while (pos < endPos)
    {
        auto url = readString(fin, true);
        auto phoneNum = readLonglong(fin);
        auto desc = readString(fin);

        cout << "Record[" << nRecords << "]" << endl;
        cout << "\turl: " << url << endl;
        cout << "\tphonenumber: " << phoneNum << endl;
        cout << "\tdesc:" << desc << endl << endl;
        nRecords++;

        pos = fin.tellg();
    }

    fin.close();

    return 0;
}
