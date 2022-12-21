#include <iostream>
#include <tchar.h>
#include <Windows.h>

using namespace std;

int main(int argc, char *argv[])
{
	wchar_t str[] = L"ABC";
	int size = sizeof(str);
	int len = wcslen(str);

	char compact[4];

	int value = 0x12345678;

	char* p = (char*)&value;

	printf("%c %x\n", p[0], p[0]);
	printf("%c %x\n", p[1], p[1]);
	printf("%c %x\n", p[2], p[2]);
	printf("%c %x\n", p[3], p[3]);

	compact[0] = (char)((char*)str)[0];
	compact[1] = (char)((char*)str)[2];
	compact[2] = (char)((char*)str)[4];
	compact[3] = '\0';

	wprintf(L"Array Size: %d\n", size);
	wprintf(L"String Length: %d\n", len);
	printf("String Length: %d %s\n", strlen(compact), compact);

	printf("argc = %d\n", argc);
	for (int i = 0; i < argc; i++)
	{
		printf("argv[%d] = %s\n", i, argv[i]);
	}

	return 0;
}

//UINT_PTR CalDistance(UINT_PTR a, UINT_PTR b);
//
//int _tmain(void)
//{
//	INT val1 = 10;
//	INT val2 = 20;
//	
//	_tprintf(_T("Position: %d %d\n"), (UINT_PTR)&val1, (UINT_PTR)&val2);
//	_tprintf(_T("Distance: %d\n"), CalDistance((UINT_PTR)&val1, (UINT_PTR)&val2));
//
//	return 0;
//}
//
//UINT_PTR CalDistance(UINT_PTR a, UINT_PTR b)
//{
//	return a - b;
//}