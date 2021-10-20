#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

// объявление пользовательского типа данных Person
struct Person
{
	// имя
	char firstName[40];

	// фамилия
	char lastName[40];

	// возраст
	int age;

	// масса
	double weight;

	// высота
	double height;
};

// объявление и инициализация глобального динамического массива типа структура Person
// struct Person* people = new Person[200];

// ввод информации об одном человеке и добавление её в конец массива
int EnterPerson(Person* people, int size, const int MaxSize)
{
	if (size < MaxSize)
	{
		cout << "Enter first name: ";
		cin >> people[size].firstName;

		cout << "Enter last name: ";
		cin >> people[size].lastName;

		cout << "Enter age: ";
		cin >> people[size].age;

		cout << "Enter weight: ";
		cin >> people[size].weight;

		cout << "Enter height: ";
		cin >> people[size].height;

		cout << endl;

		return size + 1;
	}
	else return size;
}

// вывод списка людей на экран
void PrintPeople(Person* people, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << "First name: " << people[i].firstName << endl;
		cout << "Last name: " << people[i].lastName << endl;
		cout << "Age: " << people[i].age << endl;
		cout << "Weight: " << people[i].weight << endl;
		cout << "Height: " << people[i].height << endl;
		cout << endl;
	}
}

void main()
{
	// объявление одиночной переменной типа структура Person
	/*struct Person person = {"Alex", "Potapov", 12, 15.4, 120.5};

	person.age = 23;
	strcpy(person.firstName, "Ivan");
	strcpy(person.lastName, "Petrov");
	person.weight = 78.5;
	person.height = 170.2;

	cout << "First name: " << person.firstName << endl;
	cout << "Last name: " << person.lastName << endl;
	cout << "Age: " << person.age << endl;
	cout << "Weight: " << person.weight << endl;
	cout << "Height: " << person.height << endl;*/

	/*const int PeopleCount = 5;

	// объявление статического массива типа структура Person
	struct Person person[PeopleCount] = {
								{ "Alex", "Potapov", 12, 15.4, 120.5 },
								{ "Anna", "Karenina", 45, 15.4, 120.5 },
								{ "Ivan", "Bunin", 67, 15.4, 120.5 },
								{ "Big", "Lebowski", 56, 15.4, 120.5 },
							};

	person[4].age = 23;
	strcpy(person[4].firstName, "Ivan");
	strcpy(person[4].lastName, "Petrov");
	person[4].weight = 78.5;
	person[4].height = 170.2;

	for (size_t i = 0; i < PeopleCount; i++)
	{
		cout << "First name: " << person[i].firstName << endl;
		cout << "Last name: " << person[i].lastName << endl;
		cout << "Age: " << person[i].age << endl;
		cout << "Weight: " << person[i].weight << endl;
		cout << "Height: " << person[i].height << endl;
		cout << endl;
	}*/

	const int MaxPeopleCount = 10;

	// объявление и инициализация локального динамического массива типа структура Person
	struct Person* people = new Person[MaxPeopleCount];

	int currentSize = 0;

	for (size_t i = 0; i < 3; i++)
	{
		currentSize = EnterPerson(people, currentSize, MaxPeopleCount);
	}
	
	PrintPeople(people, currentSize);

	delete[] people;
}