#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class String
{
	char* data;
	int len;
	//int capacity; //동적할당 크기 얼마나 할당할건가?

public:
	//String() : data(nullptr), len(0) /*data((char *)malloc(sizeof(char)*100)), len(0), capacity(100)*/{
	//	data[0] = '\0';
	//}
	String(const char* str = nullptr): data(new char[strlen(str +1 )]), len(strlen(str)) //String() 
	{
		strcpy(data, str);

		//while (strlen(str) >= capacity)
		//{
		//	//delete data;
		//	data = (char*)realloc(data, sizeof(char)* capacity); //realloc은 매모리를 확보하는데 뒤에 메모리가 비어 있으면 뒤에 까지 확보
		//	capacity *= 2;
		//	strcpy(data, str);
		//	len = strlen(str);
		//}
	}

	String(const String& other):String((const char*)other.data)
	{

	}

	~String()
	{}
	int size() 
	{
		return len;
	}
	int length()
	{
		return len;
	}

	String& operator = (char in)
	{
		delete[] data;
		data = new char[2];
		len = 1;
		data[0] = in;
		data[1] = '\0';
	}

	String& operator = (const char* src)
	{
		delete[] data;
		data = new char[strlen(src) + 1];
		len = strlen(src);
		strcpy(data, src);

		return *this;
	}

	String& operator = (const string& src)
	{
		return operator = (src.c_str());
	}

	/*void operator = (const string src)
	{
		operator = (src.c_str());
	}*/

	/*int capacity()
	{
		return capacity;
	}*/
};

void string_information(const char* str);

int main()
{
	//const char* another_title = "Hongik victory";
	//string_information(another_title);
	///*char title[] = "Hongik victory";
	//string_information(title);
	//title[4] = '\0';
	//string_information(title);*/

	string str("sample string", 32);

	//cout << str[0] << ": " << str[1] << ": " << str[2] << endl;
	//str[1] = 'i';
	//cout << str << ": " << str.at(1) << endl;
	//cout << str.size() << ", " << str.length() << endl;
	//cout << str.max_size() << endl;
	//cout << str.capacity() << endl;

	//for (int i = 0; i < str.size(); i++)
	//{
	//	printf("str[%d] = %d %c\n", i, str.at(i), str.at(i));
	//	//cout << "str[" << i << "] = " << str[i] << endl;
	//}

	cout << "c string " << endl;
	//const char* p = str.c_str();
	const char* p = str.data();

	/*while (*p != '\0')
	{
		cout << *p++ << endl;
	}*/

	for (int i = 0; i < strlen(p); i++)
	{
		printf("str[%d] = %d %c\n", i, p[i], p[i]);
	}

	return 0;
}

void string_information(const char* str) 
{
	cout << str << endl;
	cout << "Length : ";
	cout << strlen(str) << endl;
}