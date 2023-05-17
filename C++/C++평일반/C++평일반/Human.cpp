#include "Human.h"

void Human::SetHumanInfo(const char* name, uint age, Gender gender, uint stature, uint weight)
{
	strcpy(this->name, name);
	this->age = age;
	this->gender = gender;
	this->stature = stature;
	this->weight = weight;
}

void Human::PrintHumanInfo() const
{
	cout << name << endl;
	cout << age << endl;
	cout << ((gender == Gender::Man) ? "남자" : "여자") << endl;
	cout << stature << endl;
	cout << weight << endl;
}
