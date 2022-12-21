#include <iostream>
#include <winsock.h>

using namespace std;

void print(unsigned char* data, int sz)
{
    for (int i = 0; i < sz; i++)
    {
        printf("%X ", data[i]);
    }
    cout << endl;
}

void print(long data, int sz)
{
    unsigned char* p = (unsigned char*)&data;
    print(p, sz);
}

long convert(long source)
{
    unsigned char* p = (unsigned char*)&source;
    long dest;
    unsigned char* pDest = (unsigned char*)&dest;

    for (int i = 0; i < sizeof(source); i++)
        pDest[i] = p[sizeof(source) - i - 1];

    return dest;
}

int main(int argc, char* argv[])
{
    long source = 0x76543210; //'int 크기 = long 크기'가 같다. -> 리틀엔디안

    print((unsigned char*)&source, sizeof(long)); //캐스팅 없이 전달하면 
    long result = convert(source);
    print((unsigned char*)&result, sizeof(long));

    result = htonl(source);
    cout << "htonl" << endl;
    print((unsigned char*)&result, sizeof(long));

    return 0;
}