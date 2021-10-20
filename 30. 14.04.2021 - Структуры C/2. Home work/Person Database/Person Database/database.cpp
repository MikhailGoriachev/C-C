#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>

#include "head.h"

using namespace std;

// загрузка базы данных людей по пути ./Person Database 1.0/Data/person.data
bool LoadingPersons(person_t** persons, int* countPersons, int* sizePerson, key_t* key, int* sizeKey)
{
	// загрузка файла person.data в режиме бинарного чтения
	FILE* file = fopen("./Data/person.data", "rb");

	// если файл успешно открыт
	if (file != nullptr)
	{
		// установка указателя в начало файла
		fseek(file, 0, SEEK_END);

		// длина файла
		size_t* sizeFile = new size_t;

		*sizeFile = ftell(file);

		// если содержимое файла делится без остатка на длину данных одного пользователя
		if (*sizeFile % *sizePerson == 0)
		{
			// количество людей в базе данных
			*countPersons = *sizeFile / *sizePerson;

			// установка указателя в конец файла
			fseek(file, 0, SEEK_SET);

			// массив структур по количеству пользователей
			*persons = new person_t[*countPersons];

			// чтение в структуру из файла
			for (person_t* person = *persons; person < *persons + *countPersons; person++)
			{
				fread(person, sizeof(person_t), *countPersons, file);

				CryptOrDecrypt((char*)person, *sizePerson, key, 2, *sizeKey);
			}

			// отчистка памяти
			delete sizeFile;

			return true;
		}

		cout << "ERROR! BROKEN FILE \"person.data\"" << endl;
		return false;
	}
	
	cout << "ERROR OPENING FILE \"person.data\"" << endl;

	return false;
}

// 1. LIST PERSON
void ListPerson(person_t** persons, int* countPersons, int* sizePerson, key_t* key, int* sizeKey)
{
	// если база данных пустая
	if (*countPersons == 0)
	{
		system("cls");

		outLine();

		cout << "LIST PERSON" << endl;

		outLine();

		cout << "THE DATABASE IS EMPTY" << endl;

		pressAnyKey();

		return;
	}

	char* c = new char;

	int* n = new int;

	*n = 1;

	for (person_t* person = *persons;; )
	{
		system("cls");

		outLine();

		cout << "LIST PERSON" << endl;

		outLine();

		// текущий пользователь/всего пользователей
		cout << "			" << *n << "/" << *countPersons << endl;

		// номер паспорта
		cout << "Passport: " << person->passport << endl;

		// идентификационный код
		cout << "ID: " << person->id << endl;

		// фамилия
		cout << "Surname: " << person->surname << endl;

		// имя
		cout << "Name: " << person->name << endl;

		// отчество
		cout << "Patronymic: " << person->patron << endl;

		// адрес прописки
		cout << "Adress: " << person->adress << endl;

		// место работы
		cout << "Job: " << person->job << endl;

		// зарплата 
		cout << "Salary: " << person->salary << endl;

		cout << "\n\n\n\n\nPRESS: LAST[1] NEXT[2] QUIT[ESC]" << endl;

		// ввод 
		while (true)
		{
			*c = _getch();

			// LAST[1]
			if (*c == '1')
			{
				// если это первая анкета
				if (person == *persons)
				{
					break;
				}

				person--;

				--* n;
				break;
			}

			// NEXT[2]
			if (*c == '2')
			{
				// если это последняя анкета
				if (person == *persons + *countPersons - 1)
				{
					break;
				}

				person++;

				++* n;
				break;
			}

			// QUIT[ESC]
			if (*c == (char)27)
			{
				delete n, c;

				return;
			}
		}
		
	}
}

// 2. SEARCH PERSON
void SearchPerson(person_t** persons, int* countPersons, int* sizePerson, key_t* key, int* sizeKey)
{
	// символ ввода
	char* c = new char;

	// анкета посика 
	person_t* searchPerson = new person_t;

	// флаг выхода из цикла
	bool* flag = new bool;

	*flag = false;

	// выбор критерия поиска
	while (true)
	{
		// обнуление всех полей анкеты поиска
		strcpy(searchPerson->adress, "");
		strcpy(searchPerson->id, "");
		strcpy(searchPerson->job, "");
		strcpy(searchPerson->name, "");
		strcpy(searchPerson->passport, "");
		strcpy(searchPerson->patron, "");
		strcpy(searchPerson->surname, "");
		searchPerson->salary = 0;

		system("cls");

		outLine();

		cout << "SEARCH PERSON" << endl;

		outLine();

		cout << "SELECTION OF SEARCH CRITERIA\n" << endl;

		// номер паспорта
		cout << "1. PASSPORT" << endl;
		
		// ID
		cout << "2. ID" << endl;

		// фамилия
		cout << "3. SURNAME" << endl;

		// имя 
		cout << "4. NAME" << endl;

		// отчество 
		cout << "5. PATRONYCIM" << endl;

		// адрес
		cout << "6. ADRESS" << endl;

		// место работы
		cout << "7. JOB" << endl;

		// зарплата
		cout << "8. SALARY" << endl;

		cout << "\n\n\n\nPRESS: POINT[1-8] QUIT[ESC]" << endl;

		// ввод 
		while (true)
		{
			*c = _getch();

			// если это один из пунктов меню
			if (*c >= '0' && *c <= '9')
			{
				// 1. PASSPORT
				if (*c == '1')
				{
					system("cls");

					outLine();

					cout << "SEARCH PERSON" << endl;

					outLine();

					// ввод данных
					cout << "Enter passport: ";
					cin.getline(searchPerson->passport, 20);

					// поиск и вывод 
					if (OutSearchPerson(persons, countPersons, searchPerson, sizePerson, key, sizeKey))
					{
						delete flag, c, searchPerson;

						return;
					}
				}

				// 2. ID
				if (*c == '2')
				{
					system("cls");

					outLine();

					cout << "SEARCH PERSON" << endl;

					outLine();

					// ввод данных
					cout << "Enter ID: ";
					cin.getline(searchPerson->id, 20);

					// поиск и вывод 
					if (OutSearchPerson(persons, countPersons, searchPerson, sizePerson, key, sizeKey))
					{
						delete flag, c, searchPerson;

						return;
					}
				}

				// 3. SURNAME
				if (*c == '3')
				{
					system("cls");

					outLine();

					cout << "SEARCH PERSON" << endl;

					outLine();

					// ввод данных
					cout << "Enter surname: ";
					cin.getline(searchPerson->surname, 20);

					// поиск и вывод 
					if (OutSearchPerson(persons, countPersons, searchPerson, sizePerson, key, sizeKey))
					{
						delete flag, c, searchPerson;

						return;
					}
				}

				// 4. NAME
				if (*c == '4')
				{
					system("cls");

					outLine();

					cout << "SEARCH PERSON" << endl;

					outLine();

					// ввод данных
					cout << "Enter name: ";
					cin.getline(searchPerson->name, 20);

					// поиск и вывод 
					if (OutSearchPerson(persons, countPersons, searchPerson, sizePerson, key, sizeKey))
					{
						delete flag, c, searchPerson;

						return;
					}
				}

				// 5. PATRONYMIC
				if (*c == '5')
				{
					system("cls");

					outLine();

					cout << "SEARCH PERSON" << endl;

					outLine();

					// ввод данных
					cout << "Enter patronymic: ";
					cin.getline(searchPerson->patron, 20);

					// поиск и вывод 
					if (OutSearchPerson(persons, countPersons, searchPerson, sizePerson, key, sizeKey))
					{
						delete flag, c, searchPerson;

						return;
					}
				}

				// 6. ADRESS
				if (*c == '6')
				{
					system("cls");

					outLine();

					cout << "SEARCH PERSON" << endl;

					outLine();

					// ввод данных
					cout << "Enter adress: ";
					cin.getline(searchPerson->adress, 40);

					// поиск и вывод 
					if (OutSearchPerson(persons, countPersons, searchPerson, sizePerson, key, sizeKey))
					{
						delete flag, c, searchPerson;

						return;
					}
				}

				// 7. JOB
				if (*c == '7')
				{
					system("cls");

					outLine();

					cout << "SEARCH PERSON" << endl;

					outLine();

					// ввод данных
					cout << "Enter job: ";
					cin.getline(searchPerson->job, 40);

					// поиск и вывод 
					if (OutSearchPerson(persons, countPersons, searchPerson, sizePerson, key, sizeKey))
					{
						delete flag, c, searchPerson;

						return;
					}
				}

				// 8. SALARY
				if (*c == '8')
				{
					system("cls");

					outLine();

					cout << "SEARCH PERSON" << endl;

					outLine();

					// ввод данных
					cout << "Enter salary: ";
					cin >> searchPerson->salary;

					// поиск и вывод 
					if (OutSearchPerson(persons, countPersons, searchPerson, sizePerson, key, sizeKey))
					{
						delete flag, c, searchPerson;

						return;
					}
				}

				cout << "\n\n\n\nPRESS: RE-ENTER[R] QUIT[ESC]" << endl;

				// ввод 
				while (true)
				{
					*c = _getch();

					// RE-ENTER[R]
					if (*c == 'r' || *c == 'R')
					{
						*flag = true;

						break;
					}

					// QUIT[ESC]
					if (*c == 27)
					{
						return;
					}
				}

				if (*flag)
					break;
			}

			// QUIT[ESC]
			if (*c == 27)
			{
				delete flag, c, searchPerson;

				return;
			}
		}
	}
}

// поиск и вывод найденных людей; 1 - успешно, 0 - неуспешно;
int OutSearchPerson(person_t** persons, int* countPersons, person_t* searchPerson, int* sizePerson, key_t* key, int* sizeKey)
{
	// счётчик совпадений
	int* countSearch = new int;

	*countSearch = 0;

	// поиск по базе для подсчёта количества найденных людей
	for (person_t* person = *persons; person < *persons + *countPersons; person++)
	{
		// если есть совпадение 
		if (!strcmp(searchPerson->adress, person->adress) ||
			!strcmp(searchPerson->id, person->id) ||
			!strcmp(searchPerson->job, person->job) ||
			!strcmp(searchPerson->name, person->name) ||
			!strcmp(searchPerson->passport, person->passport) ||
			!strcmp(searchPerson->patron, person->patron) ||
			!strcmp(searchPerson->surname, person->surname) ||
			searchPerson->salary == person->salary)
		{
			// увеличение счётчика
			++* countSearch;
		}
	}

	// если человека с такими данными нет в базе
	if (*countSearch == 0)
	{
		cout << "NOT FOUND" << endl;

		delete countSearch;

		return 0;
	}

	// массив структур найденных людей
	person_t** searchPersons = new person_t*;

	*searchPersons = new person_t[*countSearch];

	// поиск по базе для подсчёта количества найденных людей
	for (person_t* person = *persons, *searchPerson_p = *searchPersons; person < *persons + *countPersons; person++)
	{
		// если есть совпадение 
		if (!strcmp(searchPerson->adress, person->adress) ||
			!strcmp(searchPerson->id, person->id) ||
			!strcmp(searchPerson->job, person->job) ||
			!strcmp(searchPerson->name, person->name) ||
			!strcmp(searchPerson->passport, person->passport) ||
			!strcmp(searchPerson->patron, person->patron) ||
			!strcmp(searchPerson->surname, person->surname) ||
			searchPerson->salary == person->salary)
		{
			// копирование 
			!strcpy(searchPerson_p->adress, person->adress);
			!strcpy(searchPerson_p->id, person->id);
			!strcpy(searchPerson_p->job, person->job);
			!strcpy(searchPerson_p->name, person->name);
			!strcpy(searchPerson_p->passport, person->passport);
			!strcpy(searchPerson_p->patron, person->patron);
			!strcpy(searchPerson_p->surname, person->surname);
			searchPerson_p->salary = person->salary;

			*searchPerson_p++;
		}
	}

	// вывод этих пользователей
	ListPerson(searchPersons, countSearch, sizePerson, key, sizeKey);

	delete[] * searchPersons;
	delete searchPersons, countSearch;

	return 1;
}

// 3. ADD PERSON (ADMIN GROUP)
void AddPerson(person_t** persons, int* countPersons, int* sizePerson, key_t* key, int* sizeKey)
{
	// открытие файла person.data в режиме бинарного чтения/записи
	FILE* file = fopen("./Data/person.data", "rb+");

	// структура нового пользователя
	person_t* newPerson = new person_t;

	// заполнение полей стркуртуры случайными символами
	GenerationRandomCymbols((char*)newPerson, *sizePerson);

	// флаг уникальности данных
	bool* flag = new bool;

	*flag = false;

	// символ
	char* c = new char;

	// если файл успешно открыт 
	if (file != nullptr)
	{
		// ввод данных
		while (true)
		{
			system("cls");

			outLine();

			cout << "ADD PERSON" << endl;

			outLine();

			// номер паспорта
			cout << "Passport: ";
			cin.getline(newPerson->passport, 20);

			// ID
			cout << "ID: ";
			cin.getline(newPerson->id, 20);

			// проверка номера паспорта и ID по базе данных
			for (person_t* person = *persons; person < *persons + *countPersons; person++)
			{
				// проверка номера паспорта 
				if (!strcmp(person->passport, newPerson->passport))
				{
					cout << "PASSPORT IS NOT UNIQUE!" << endl;

					*flag = true;
				}

				if (!strcmp(person->id, newPerson->id))
				{
					cout << "ID IS NOT UNIQUE!" << endl;

					*flag = true;
				}
			}

			// если совпадений не найдено
			if (!*flag)
			{
				// фамилия
				cout << "Surname: ";
				cin.getline(newPerson->surname, 20);

				// имя 
				cout << "Name: ";
				cin.getline(newPerson->name, 20);

				// отчество 
				cout << "Partonymic: ";
				cin.getline(newPerson->patron, 20);

				// адрес
				cout << "Adress: ";
				cin.getline(newPerson->adress, 40);

				// место работы
				cout << "Job: ";
				cin.getline(newPerson->job, 40);

				// зарплата
				cout << "Salary: ";
				cin >> newPerson->salary;

				cout << "PRESS: ENTER[ENTER] RE-ENTER[R] QUIT[ESC]" << endl;
			}

			// если данные не уникальны
			if (*flag)
			{
				cout << "PRESS: RE-ENTER[R] QUIT[ESC]" << endl;
			}

			// ввод 
			while (true)
			{
				*c = _getch();

				// ENTER[ENTER]
				if (!*flag && *c == '\r')
				{
					// шифрование структуры
					CryptOrDecrypt((char*)newPerson, *sizePerson, key, 1, *sizeKey);

					// установка указателя в конец файла
					fseek(file, 0, SEEK_END);

					// запись структуры в конец файла
					fwrite(newPerson, sizeof(person_t), 1, file);

					// закрытие файла
					fclose(file);

					delete newPerson, flag, c;

					delete[] * persons;

					// перезагрузка базы 
					LoadingPersons(persons, countPersons, sizePerson, key, sizeKey);

					cin.ignore();

					return;
				}

				else if (*c == 27)
				{
					delete newPerson, flag, c;

					return;
				}

				else if (*c == 'R' || *c == 'r')
				{
					break;
				}
			}
		}
	}

	cout << "ERROR OPENING FILE \"person.data\"" << endl;
}

// 4. DELETE PERSON (ADMIN GROUP)
void DeletePerson(person_t** persons, int* countPersons, int* sizePerson, key_t* key, int* sizeKey)
{
	// строка для номера паспорта или ID
	char* str = new char[20];

	// флаг наличия человека в базе
	bool* flag = new bool;

	// символ ввода
	char* c = new char;

	// вид данных: 0 - id; 1 - passport
	int* mode = new int;

	while (true)
	{
		*flag = false;

		system("cls");

		outLine();

		cout << "DELETE PERSON" << endl;

		outLine();

		// ввод номера паспорта или ID
		cout << "Enter passport or ID: ";
		cin.getline(str, 20);

		// поиск по базе
		for (person_t* person = *persons; person < *persons + *countPersons; person++)
		{
			// если человек найден
			if (!strcmp(person->id, str) || !strcmp(person->passport, str))
			{
				// если это ID
				if (!strcmp(person->id, str))
				{
					*mode = 0;
				}
				// если это passport
				else *mode = 1;

				// флаг того что данные найдены в таблице
				*flag = true;

				system("cls");

				outLine();

				cout << "DELETE PERSON" << endl;

				outLine();

				// номер паспорта
				cout << "Passport: " << person->passport << endl;

				// идентификационный код
				cout << "ID: " << person->id << endl;

				// фамилия
				cout << "Surname: " << person->surname << endl;

				// имя
				cout << "Name: " << person->name << endl;

				// отчество
				cout << "Patronymic: " << person->patron << endl;

				// адрес прописки
				cout << "Adress: " << person->adress << endl;

				// место работы
				cout << "Job: " << person->job << endl;

				// зарплата 
				cout << "Salary: " << person->salary << endl;


				cout << "\n\n\n\nPESS: RE-ENTER[R] DELETE[ENTER] QUIT[ESC]" << endl;

				// ввод 
				while (true)
				{
					*c = _getch();

					// RE-ENTER[R]
					if (*c == 'r' || *c == 'R')
					{
						break;
					}

					// QUIT[ESC]
					if (*c == 27)
					{
						// отчистка памяти
						delete[] str;
						delete flag, c, mode;


						return;
					}

					// DELETE[ENTER]
					if (*c == 13)
					{
						// открытие файла данных ./Data/person.data в режиме бинарного чтения/записи
						FILE* file = fopen("./Data/person.data", "rb+");

						// если файл успешно открыт
						if (file != nullptr)
						{
							// установка указателя в конец файла
							fseek(file, 0, SEEK_END);

							// размер файла 
							size_t* sizeFile = new size_t;

							*sizeFile = ftell(file);

							// установка указателя в начало файла 
							fseek(file, 0, SEEK_SET);

							// буфер
							char* buffer = new char[*sizeFile];

							// чтение файла в буфер
							fread(buffer, sizeof(char), *sizeFile, file);

							// закрытие файла

							// длина введённых данных
							size_t* len = new size_t;

							*len = strlen(str);

							// шифрование введённых данных
							CryptOrDecrypt(str, *len, key, 1, *sizeKey);

							// поиск содержимого буфере 
							for (char* buf = buffer; buf < buffer + *sizeFile; buf++)
							{
								// если совпадение найдено
								if (!strncmp(str, buf, *len))
								{
									// смещение указателя в буфере 
									// если введённые данные ID
									if (*mode == 0)
									{
										buf -= 84;
									}
									
									// если введённые данные passport
									else if (*mode == 1)
									{
										buf -= 4;
									}

									short* n = new short;

									*n = *sizePerson;

									// смещение массива влево
									for (char* b = buf;; )
									{
										for (char* bb = b; bb < buffer + *sizeFile; bb++)
										{
											swap(*bb, *(bb + 1));

										}

										--* n;

										if (*n == 0)
											break;
									}

									*sizeFile -= *sizePerson;

									// открытие файла в режиме бинарной записи
									file = fopen("./Data/person.data", "wb");

									// запись в файл из буфера 
									fwrite(buffer, sizeof(char), *sizeFile, file);

									// закрытие файла
									fclose(file);

									// отчистка прошлой версии базы из памяти
									delete[] * persons;

									// загрузка новой версии базы в память
									LoadingPersons(persons, countPersons, sizePerson, key, sizeKey);

									// отчистка памяти
									delete[] str, buffer;
									delete flag, c, sizeFile, mode, len;

									system("cls");

									outLine();

									cout << "DELETE PERSON" << endl;

									outLine();

									cout << "DELETE COMPLETE!" << endl;

									pressAnyKey();
									
									return;
								}
							}
						}				
						
						cout << "ERROR OPENNING FILE \"./Data/person.data\"" << endl;

						return;
					}
				}
			}
		}
		
		if (!*flag)
		{
			system("cls");

			outLine();

			cout << "DELETE PERSON" << endl;

			outLine();

			cout << "PERSON NOT FOUND!" << endl;

			cout << "\n\n\n\nPESS: RE-ENTER[R] QUIT[ESC]" << endl;

			// ввод 
			while (true)
			{
				*c = _getch();

				// RE-ENTER[R]
				if (*c == 'r' || *c == 'R')
				{
					break;
				}

				// QUIT[ESC]
				if (*c == 27)
				{
					// отчистка памяти
					delete[] str;
					delete flag, c, mode;

					return;
				}
			}
		}
	}
}