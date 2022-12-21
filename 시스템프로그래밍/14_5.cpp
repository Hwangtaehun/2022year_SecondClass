#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

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

//int main(void)
//{
//	char ch;
//	
//	ofstream fout("test.txt");
//
//	while (cin.get(ch))
//	{
//		fout.put(ch);
//	}
//
//	fout.close();
//
//	//while (cin.get(ch))//버퍼링이 되어있어 모든 내용을 하나씩 보여 주는 것은 안 좋음 -> 처리 속도가 느려짐
//	//{
//	//	cout.put(ch);
//	//}
//
//	return 0;
//}

int main(int argc, char* argv[])
{
	ifstream fin;

	if (argc != 2)
	{
		cout << "Usage : SystemPrograming 파일명" << endl;
		return 0;
	}
	//argc == 2
	fin.open(argv[1]);
	
	if (!fin.is_open())
	{
		cout << "file" << argv[1] << "cannot be openned" << endl;
		return 0;
	}

	char ch;
	while (fin.get(ch))
	{
		cout.put(ch);
	}

	fin.close();

	return 0;
}