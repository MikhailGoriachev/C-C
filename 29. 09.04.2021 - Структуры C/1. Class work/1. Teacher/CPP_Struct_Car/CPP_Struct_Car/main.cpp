#include <iostream>
#include <conio.h>
using namespace std;

void PrintMenu()
{
	system("cls");
	cout << "Choose an option, please:" << endl;
	cout << "1 - Add a car" << endl;
	cout << "2 - Show all cars" << endl;
	cout << "3 - Delete a car" << endl;
	cout << "4 - View a car" << endl;
	cout << "5 - Exit" << endl;
	cout << endl;
}

struct Car
{
	unsigned int Id;
	char SerialNumber[20];
	char Brand[20];
	char Model[20];
	char Owner[40];
	unsigned int Year;
	double Price;
};

unsigned int AddCar(Car* cars, unsigned int size, const int MaxSize)
{
	cin.ignore();
	// если есть свободное место в массиве автомобилей
	if (size < MaxSize)
	{
		Car newCar;
		newCar.Id = size;

		cout << "Enter the serial number of the car:" << endl;
		cin >> newCar.SerialNumber;
		cout << "Enter the brand of the car:" << endl;
		cin >> newCar.Brand;
		cout << "Enter the model of the car:" << endl;
		cin >> newCar.Model;
		cout << "Enter the owner of the car:" << endl;
		cin >> newCar.Owner;
		cout << "Enter the year of the car:" << endl;
		cin >> newCar.Year;
		cout << "Enter the price of the car:" << endl;
		cin >> newCar.Price;

		cars[size] = newCar;
		size++;
	}
	else cout << "There is no enough space for adding a new car!" << endl;
	
	return size;
}

void PrintCars(Car* cars, const unsigned int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << "Id: " << cars[i].Id << endl;
		cout << "Serial number: " << cars[i].SerialNumber << endl;
		cout << "Brand:" << cars[i].Brand << endl;
		cout << "Model: " << cars[i].Model << endl;
		cout << "Owner:" << cars[i].Owner << endl;
		cout << "Year: " << cars[i].Year << endl;
		cout << "Price:" << cars[i].Price << endl;
		cout << endl;
	}
	cout << endl << "Press any key..." << endl;
	_getch();
}

unsigned int DeleteCar(Car* cars, unsigned int size, unsigned int id)
{
	int index = -1;
	for (size_t i = 0; i < size; i++)
	{
		if (cars[i].Id == id)
		{
			index = id;
			break;
		}
	}

	if (index != -1)
	{
		for (size_t i = index; i < size; i++)
		{
			cars[i] = cars[i + 1];
		}
		size--;
		return size;
	}
	else 
	{
		cout << "Wrong Id!" << endl;
		cout << endl << "Press any key..." << endl;
		_getch();
		return size;
	}
}

void ShowCar(Car* cars, const unsigned int size, const unsigned int id)
{
	int index = -1;
	for (size_t i = 0; i < size; i++)
	{
		if (cars[i].Id == id)
		{
			index = id;
			break;
		}
	}

	if (index != -1)
	{
		cout << "Id: " << cars[index].Id << endl;
		cout << "Serial number: " << cars[index].SerialNumber << endl;
		cout << "Brand:" << cars[index].Brand << endl;
		cout << "Model: " << cars[index].Model << endl;
		cout << "Owner:" << cars[index].Owner << endl;
		cout << "Year: " << cars[index].Year << endl;
		cout << "Price:" << cars[index].Price << endl;
		cout << endl;
		cout << endl << "Press any key..." << endl;
		_getch();
	}
	else
	{
		cout << "Wrong Id!" << endl;
		cout << endl << "Press any key..." << endl;
		_getch();
	}
}

void main()
{
	int size = 0;
	const int MaxSize = 40;
	Car* cars = new Car[MaxSize];

	while (true)
	{
		PrintMenu();
		char choice = _getch();
		unsigned int id = 0;

		switch (choice)
		{
			case '1':
				size = AddCar(cars, size, MaxSize);
				break;
			case '2':
				PrintCars(cars, size);
				break;
			case '3':
				cout << "Enter Id of the car to delete:" << endl;
				cin >> id;
				size = DeleteCar(cars, size, id);
				break;
			case '4':
				cout << "Enter Id of the car to show:" << endl;
				cin >> id;
				ShowCar(cars, size, id);
				break;
			case '5':
				delete[] cars;
				return;
		}
	}
}