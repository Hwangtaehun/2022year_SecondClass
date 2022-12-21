#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <time.h> //== <ctime>
using namespace std;

int main()
{
	//auto now = time(nullptr);
	/*time_t now = time(nullptr);
	struct tm* It = localtime(&now);

	printf("%d %d %d %d %d %d %d %d %d\n",
		It->tm_sec, It->tm_min, It->tm_hour, It->tm_mday, It->tm_mon, It->tm_year, It->tm_wday, It->tm_yday, It->tm_isdst);
	printf("%04d년 %d월 %d일 %d시 %d분 %d초\n",
		It->tm_year+1900, It->tm_mon, It->tm_mday, It->tm_hour, It->tm_min, It->tm_sec);

	cout << now << endl;

	now = 1;
	struct tm* epoch = localtime(&now);
	printf("%04d년 %d월 %d일 %d시 %d분 %d초\n",
		epoch->tm_year + 1900, epoch->tm_mon, epoch->tm_mday, epoch->tm_hour, epoch->tm_min, epoch->tm_sec);

	printf("%04d년 %d월 %d일 %d시 %d분 %d초\n",
		It->tm_year + 1900, It->tm_mon, It->tm_mday, It->tm_hour, It->tm_min, It->tm_sec);*/

	time_t now = time(nullptr);
	struct tm It;
	localtime_s(&It, &now);

	printf("%d %d %d %d %d %d %d %d %d\n",
		It.tm_sec, It.tm_min, It.tm_hour, It.tm_mday, It.tm_mon, It.tm_year, It.tm_wday, It.tm_yday, It.tm_isdst);
	printf("%04d년 %d월 %d일 %d시 %d분 %d초\n",
		It.tm_year + 1900, It.tm_mon, It.tm_mday, It.tm_hour, It.tm_min, It.tm_sec);

	cout << now << endl;

	now = 1;
	struct tm epoch;
	localtime_s(&epoch, &now);
	printf("%04d년 %d월 %d일 %d시 %d분 %d초\n",
		epoch.tm_year + 1900, epoch.tm_mon, epoch.tm_mday, epoch.tm_hour, epoch.tm_min, epoch.tm_sec);

	printf("%04d년 %d월 %d일 %d시 %d분 %d초\n",
		It.tm_year + 1900, It.tm_mon, It.tm_mday, It.tm_hour, It.tm_min, It.tm_sec);

	cout << asctime(&epoch) << endl;

	return 0;
}