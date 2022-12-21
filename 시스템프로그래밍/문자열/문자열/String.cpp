#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
	/*문자열 대입*/
	/*string str1;
	string str2;
	str1 = "string";
	str2 = str1;

	cout << str2 << endl;*/

	/*문자열 할당*/
	/*string str1("IT Cookbook");
	string str2("Hello");

	str2.assign(str1, 0, 5);

	cout << str2 << ", " << str2.size() << endl;*/

	/*문자열 추가*/
	/*string str1("Sample");
	string str2("Hello");

	str1 += " Program";

	cout << str1 << endl;*/

	/*문자열 삽입과 삭제*/
	//string src("World Programmer");
	//string dest("Best");

	////cout << dest << ", " << dest.length() << endl;
	////
	/////*dest.insert(1, src);
	////cout << dest << ", " << dest.length() << endl;*/
	////
	////dest.insert(3, src, 5, 8);
	////cout << dest << ", " << dest.length() << endl;

	//cout << src << ", " << src.length() << endl;

	//cout << src.erase(0, 6) << ", " << src.length() << endl;

	/*문자열의 치환*/
	/*string dest("You hate me");

	dest.replace(4, 4, "dislike");

	cout << dest << endl;*/
	
	/*문자열의 검색*/
	/*string dest("You hate hate me");

	int idx = dest.find("hate");
	int anotherIdx = dest.rfind("hate");

	cout << "find: " << idx << "\n" << "rfind: " << anotherIdx << endl;*/

	char buff[80];

	cout << "문자열 입력해주세요 ";
	cin.get(buff, 80);

	cout << buff << endl;

	return 0;
}