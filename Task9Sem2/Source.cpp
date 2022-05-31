#include <iostream>

using namespace std;

class Property
{
public:
	Property(double w = 0) : worth(w) {}
	virtual double Tax() = 0;

protected:
	double worth;
};

class Apartment : public Property
{
public:
	Apartment(double w) : Property(w) {}
	double Tax() override { return worth / 1000.0; }
};

class Car : public Property
{
public:
	Car(double w) : Property(w) {}
	double Tax() override { return worth / 200.0; }
};

class CountryHouse : public Property
{
public:
	CountryHouse(double w) : Property(w) {}
	double Tax() override { return worth / 500.0; }
};

int main()
{
	setlocale(LC_ALL, "rus");

	Property* list[7];

	list[0] = new Apartment(12000000);
	list[1] = new Apartment(16580000);
	list[2] = new Apartment(24000000);
	list[3] = new Car(2300000);
	list[4] = new Car(7000000);
	list[5] = new CountryHouse(25500000);
	list[6] = new CountryHouse(37100000);

	for (int i = 0; i < 7; i++)
	{
		cout << "Налог составляет " << list[i]->Tax() << endl;
	}

	for (int i = 0; i < 7; i++)
	{
		delete list[i];
	}

	return 0;
}