#include <winsock2.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int input[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int g_count = 0;
CRITICAL_SECTION cs;

DWORD WINAPI MyThread1(LPVOID arg) {
	for (int i = 0; i < 3; i++)
	{
		EnterCriticalSection(&cs);
		g_count += input[i];
		LeaveCriticalSection(&cs);
	}
	cout << "입력 값(스레드1): " << input[0] << input[1] << input[2] << "\n" << endl;
	return 0;
}

DWORD WINAPI MyThread2(LPVOID arg) {
	for (int i = 3; i < 6; i++)
	{
		EnterCriticalSection(&cs);
		g_count += input[i];
		LeaveCriticalSection(&cs);
	}
	cout << "입력 값(스레드2): " << input[3] << input[4] << input[5] << "\n" << endl;
	return 0;
}

DWORD WINAPI MyThread3(LPVOID arg) {
	for (int i = 6; i < 10; i++)
	{
		EnterCriticalSection(&cs);
		g_count += input[i];
		LeaveCriticalSection(&cs);
	}
	cout << "입력 값(스레드3): " << input[6] << input[7] << input[8] << input[9] << "\n" << endl;
	return 0;
}

int main(int argc, char* argv[])
{
	InitializeCriticalSection(&cs);
	HANDLE hThread[3];
	hThread[0] = CreateThread(NULL, 0, MyThread1, NULL, 0, NULL);
	hThread[1] = CreateThread(NULL, 0, MyThread2, NULL, 0, NULL);
	hThread[2] = CreateThread(NULL, 0, MyThread3, NULL, 0, NULL);
	WaitForMultipleObjects(3, hThread, TRUE, INFINITE);
	DeleteCriticalSection(&cs);
	cout << "결과 값(합계) = " << g_count << endl;
	cout << "결과 값 평균 = " << (float)g_count/(sizeof(input)/sizeof(int)) << endl;
	system("pause");
	return 0;
}