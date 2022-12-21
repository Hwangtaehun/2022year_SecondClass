#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h> // == <cstdlib>
#include <string>
#include <fstream>

using namespace std;

struct Insa {
	string name;
	int age;
	string address;
};

class CInsa {
	char name[20];
	int age;
	char address[20];

public:
	CInsa(const char* name, int age, const char* address) :age(age)
	{
		strcpy(this->name, name);
		strcpy(this->address, address);
	}

	void print()
	{
		cout << name << " " << age << " " << address << endl;
	}
};

int main(int argc, char* argv[])
{
	ofstream fout("test.data", ios::out | ios::binary);
	if (!fout)
	{
		cout << "file cannot be created or opened" << endl;
	}

	Insa my = { "서범주djkgle gjkel ejkl woere", 20, "세종" };

	int count = 0;

	cout << "current position " << fout.tellp() << endl; //현재위치를 알려주는 함수
	char* buff = new char[my.name.size() + 1];
	strcpy(buff, my.name.data());
	fout.write(buff, strlen(buff) + 1);
	cout << "current position " << fout.tellp() << endl;
	delete[] buff;

	cout << "current position " << fout.tellp() << endl;
	fout.write((char*)&my.age, sizeof(int));
	
	buff = new char[my.address.size() + 1];
	strcpy(buff, my.address.c_str());
	cout << "current position " << fout.tellp() << endl;
	fout.write(buff, strlen(buff) + 1);
	delete[] buff;
	cout << "current position " << fout.tellp() << endl;

	fout.seekp(34, ios::beg);
	cout << "current position " << fout.tellp() << endl;;
	int age = 30;
	fout.write((char*)&my.age, sizeof(int));
	cout << "current position " << fout.tellp() << endl;;

	//fout.write((char*)&my, sizeof(Insa));

	fout.close();

	return 0;
}