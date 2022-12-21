#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Car
{
private: 
	char company[100];
	//char model[50];
	string model;
	char date[100];
	unsigned int price;

public:
	Car(const char* company, const char* model, const char* date, unsigned int price);
	~Car();
	void info();
	void changeModel(const char* newModel);
};

Car::Car(const char* company, const char* model, const char* date, unsigned int price) : price(price), model(model)
{
	strcpy(this->company, company);
	//strcpy(this->model, model);
	strcpy(this->date, date);
}

Car::~Car()
{

}

void Car::info()
{
	cout << "Company: " << company << endl
		<< "Model :" << model << endl
		<< "Manufacturing Date :" << date << endl
		<< "Price :" << price << endl;
}

void Car::changeModel(const char* newModel)
{
	//strcpy(model, newModel);
	model = newModel;
}

int main()
{
	Car sonata("hyundai", "EF Sonata", "2001/08/15", 1400);
	sonata.info();

	cout << endl;

	sonata.changeModel("NF Sonata");
	sonata.info();

	return 0;
}