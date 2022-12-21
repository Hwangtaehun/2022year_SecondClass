#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Insa
{
	char name[20];
	int age;
	char address[20];
};


using std::string;

// trim from left 
inline std::string& ltrim(std::string& s, const char* t = " \t\n\r\f\v")
{
	s.erase(0, s.find_first_not_of(t));
	return s;
}
// trim from right 
inline std::string& rtrim(std::string& s, const char* t = " \t\n\r\f\v")
{
	s.erase(s.find_last_not_of(t) + 1);
	return s;
}
// trim from left & right 
inline std::string& trim(std::string& s, const char* t = " \t\n\r\f\v")
{
	return ltrim(rtrim(s, t), t);
}


int main(void) {
	//Insa male1{ "안녕", 20, "세종" };
	Insa male2;

	ofstream fout;
	ifstream fin;

	string str;

	//fout.open("insa.dat");
	//if (fout.is_open())
	//{
	//	//fout << male1.name << " " << male1.age << " " << male1.address << endl;
	//	fout << male1.name << "," << male1.age << "," << male1.address << endl;

	//	fout.close();
	//}

	fin.open("insa.dat");
	char data[256];

	if (fin.fail())
	{
		cout << "파일 오픈에 실패했습니다." << endl;
		return;

	}

	while (!fin.eof()) // \0나올때까지 반복
	{
		fin.getline(data, 256, ',');
		strcpy(male2.name, data);

		string source = male2.name;
		string result = trim(source);
		strcpy(male2.name, result.c_str());

		fin.getline(data, 256, ',');
		male2.age = atoi(data);

		fin.getline(data, 256);
		strcpy(male2.address, data);

		source = male2.address;
		result = trim(source);
		strcpy(male2.address, result.c_str());

		cout << male2.name << " " << male2.age << " " << male2.address << endl;
	}

	fin.close();

	//if (fin.is_open())
	//{
	//	while (!fin.eof()) // \0나올때까지 반복
	//	{
	//		fin.getline(data, 256, ',');
	//		strcpy(male2.name, data);

	//		string source = male2.name;
	//		string result = trim(source);
	//		strcpy(male2.name, result.c_str());

	//		fin.getline(data, 256, ',');
	//		male2.age = atoi(data);

	//		fin.getline(data, 256);
	//		strcpy(male2.address, data);

	//		source = male2.address;
	//		result = trim(source);
	//		strcpy(male2.address, result.c_str());

	//		cout << male2.name << " " << male2.age << " " << male2.address << endl;
	//	}

	//	/*fin >> male2.name >> male2.age >> male2.address;

	//	cout << male2.name << "," << male2.age << "," << male2.address << endl;*/

	//	fin.close();
	//}

	return 0;
}