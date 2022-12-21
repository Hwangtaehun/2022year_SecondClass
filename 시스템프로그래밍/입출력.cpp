#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <tchar.h>
#include <locale.h>
#include <Windows.h>

using namespace std;

struct Insa{
	char name[20];
	int age;
	char address[20];
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

int main(void)
{
	/*CInsa male{ "È²ÅÂÈÆ", 27, "Ã»ÁÖ" };
	male.print();*/

	Insa man{ "taehun", 27, "chungju" };

	ofstream fout;
	
	fout.open("insa.data", ios::out | ios::app | ios:: trunc);
	if (fout.is_open())
	{
		fout << man.name << " " << man.age << " " << man.address << endl;

		fout.close();
	}
	return 0;
}