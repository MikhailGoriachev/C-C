#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>

#include "head.h"

using namespace std;

// �������� ���� ������ ����� �� ���� ./Person Database 1.0/Data/person.data
bool LoadingPersons(person_t** persons, int* countPersons, int* sizePerson, key_t* key, int* sizeKey)
{
	// �������� ����� person.data � ������ ��������� ������
	FILE* file = fopen("./Data/person.data", "rb");

	// ���� ���� ������� ������
	if (file != nullptr)
	{
		// ��������� ��������� � ������ �����
		fseek(file, 0, SEEK_END);

		// ����� �����
		size_t* sizeFile = new size_t;

		*sizeFile = ftell(file);

		// ���� ���������� ����� ������� ��� ������� �� ����� ������ ������ ������������
		if (*sizeFile % *sizePerson == 0)
		{
			// ���������� ����� � ���� ������
			*countPersons = *sizeFile / *sizePerson;

			// ��������� ��������� � ����� �����
			fseek(file, 0, SEEK_SET);

			// ������ �������� �� ���������� �������������
			*persons = new person_t[*countPersons];

			// ������ � ��������� �� �����
			for (person_t* person = *persons; person < *persons + *countPersons; person++)
			{
				fread(person, sizeof(person_t), *countPersons, file);

				CryptOrDecrypt((char*)person, *sizePerson, key, 2, *sizeKey);
			}

			// �������� ������
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
	// ���� ���� ������ ������
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

		// ������� ������������/����� �������������
		cout << "			" << *n << "/" << *countPersons << endl;

		// ����� ��������
		cout << "Passport: " << person->passport << endl;

		// ����������������� ���
		cout << "ID: " << person->id << endl;

		// �������
		cout << "Surname: " << person->surname << endl;

		// ���
		cout << "Name: " << person->name << endl;

		// ��������
		cout << "Patronymic: " << person->patron << endl;

		// ����� ��������
		cout << "Adress: " << person->adress << endl;

		// ����� ������
		cout << "Job: " << person->job << endl;

		// �������� 
		cout << "Salary: " << person->salary << endl;

		cout << "\n\n\n\n\nPRESS: LAST[1] NEXT[2] QUIT[ESC]" << endl;

		// ���� 
		while (true)
		{
			*c = _getch();

			// LAST[1]
			if (*c == '1')
			{
				// ���� ��� ������ ������
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
				// ���� ��� ��������� ������
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
	// ������ �����
	char* c = new char;

	// ������ ������ 
	person_t* searchPerson = new person_t;

	// ���� ������ �� �����
	bool* flag = new bool;

	*flag = false;

	// ����� �������� ������
	while (true)
	{
		// ��������� ���� ����� ������ ������
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

		// ����� ��������
		cout << "1. PASSPORT" << endl;
		
		// ID
		cout << "2. ID" << endl;

		// �������
		cout << "3. SURNAME" << endl;

		// ��� 
		cout << "4. NAME" << endl;

		// �������� 
		cout << "5. PATRONYCIM" << endl;

		// �����
		cout << "6. ADRESS" << endl;

		// ����� ������
		cout << "7. JOB" << endl;

		// ��������
		cout << "8. SALARY" << endl;

		cout << "\n\n\n\nPRESS: POINT[1-8] QUIT[ESC]" << endl;

		// ���� 
		while (true)
		{
			*c = _getch();

			// ���� ��� ���� �� ������� ����
			if (*c >= '0' && *c <= '9')
			{
				// 1. PASSPORT
				if (*c == '1')
				{
					system("cls");

					outLine();

					cout << "SEARCH PERSON" << endl;

					outLine();

					// ���� ������
					cout << "Enter passport: ";
					cin.getline(searchPerson->passport, 20);

					// ����� � ����� 
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

					// ���� ������
					cout << "Enter ID: ";
					cin.getline(searchPerson->id, 20);

					// ����� � ����� 
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

					// ���� ������
					cout << "Enter surname: ";
					cin.getline(searchPerson->surname, 20);

					// ����� � ����� 
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

					// ���� ������
					cout << "Enter name: ";
					cin.getline(searchPerson->name, 20);

					// ����� � ����� 
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

					// ���� ������
					cout << "Enter patronymic: ";
					cin.getline(searchPerson->patron, 20);

					// ����� � ����� 
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

					// ���� ������
					cout << "Enter adress: ";
					cin.getline(searchPerson->adress, 40);

					// ����� � ����� 
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

					// ���� ������
					cout << "Enter job: ";
					cin.getline(searchPerson->job, 40);

					// ����� � ����� 
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

					// ���� ������
					cout << "Enter salary: ";
					cin >> searchPerson->salary;

					// ����� � ����� 
					if (OutSearchPerson(persons, countPersons, searchPerson, sizePerson, key, sizeKey))
					{
						delete flag, c, searchPerson;

						return;
					}
				}

				cout << "\n\n\n\nPRESS: RE-ENTER[R] QUIT[ESC]" << endl;

				// ���� 
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

// ����� � ����� ��������� �����; 1 - �������, 0 - ���������;
int OutSearchPerson(person_t** persons, int* countPersons, person_t* searchPerson, int* sizePerson, key_t* key, int* sizeKey)
{
	// ������� ����������
	int* countSearch = new int;

	*countSearch = 0;

	// ����� �� ���� ��� �������� ���������� ��������� �����
	for (person_t* person = *persons; person < *persons + *countPersons; person++)
	{
		// ���� ���� ���������� 
		if (!strcmp(searchPerson->adress, person->adress) ||
			!strcmp(searchPerson->id, person->id) ||
			!strcmp(searchPerson->job, person->job) ||
			!strcmp(searchPerson->name, person->name) ||
			!strcmp(searchPerson->passport, person->passport) ||
			!strcmp(searchPerson->patron, person->patron) ||
			!strcmp(searchPerson->surname, person->surname) ||
			searchPerson->salary == person->salary)
		{
			// ���������� ��������
			++* countSearch;
		}
	}

	// ���� �������� � ������ ������� ��� � ����
	if (*countSearch == 0)
	{
		cout << "NOT FOUND" << endl;

		delete countSearch;

		return 0;
	}

	// ������ �������� ��������� �����
	person_t** searchPersons = new person_t*;

	*searchPersons = new person_t[*countSearch];

	// ����� �� ���� ��� �������� ���������� ��������� �����
	for (person_t* person = *persons, *searchPerson_p = *searchPersons; person < *persons + *countPersons; person++)
	{
		// ���� ���� ���������� 
		if (!strcmp(searchPerson->adress, person->adress) ||
			!strcmp(searchPerson->id, person->id) ||
			!strcmp(searchPerson->job, person->job) ||
			!strcmp(searchPerson->name, person->name) ||
			!strcmp(searchPerson->passport, person->passport) ||
			!strcmp(searchPerson->patron, person->patron) ||
			!strcmp(searchPerson->surname, person->surname) ||
			searchPerson->salary == person->salary)
		{
			// ����������� 
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

	// ����� ���� �������������
	ListPerson(searchPersons, countSearch, sizePerson, key, sizeKey);

	delete[] * searchPersons;
	delete searchPersons, countSearch;

	return 1;
}

// 3. ADD PERSON (ADMIN GROUP)
void AddPerson(person_t** persons, int* countPersons, int* sizePerson, key_t* key, int* sizeKey)
{
	// �������� ����� person.data � ������ ��������� ������/������
	FILE* file = fopen("./Data/person.data", "rb+");

	// ��������� ������ ������������
	person_t* newPerson = new person_t;

	// ���������� ����� ���������� ���������� ���������
	GenerationRandomCymbols((char*)newPerson, *sizePerson);

	// ���� ������������ ������
	bool* flag = new bool;

	*flag = false;

	// ������
	char* c = new char;

	// ���� ���� ������� ������ 
	if (file != nullptr)
	{
		// ���� ������
		while (true)
		{
			system("cls");

			outLine();

			cout << "ADD PERSON" << endl;

			outLine();

			// ����� ��������
			cout << "Passport: ";
			cin.getline(newPerson->passport, 20);

			// ID
			cout << "ID: ";
			cin.getline(newPerson->id, 20);

			// �������� ������ �������� � ID �� ���� ������
			for (person_t* person = *persons; person < *persons + *countPersons; person++)
			{
				// �������� ������ �������� 
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

			// ���� ���������� �� �������
			if (!*flag)
			{
				// �������
				cout << "Surname: ";
				cin.getline(newPerson->surname, 20);

				// ��� 
				cout << "Name: ";
				cin.getline(newPerson->name, 20);

				// �������� 
				cout << "Partonymic: ";
				cin.getline(newPerson->patron, 20);

				// �����
				cout << "Adress: ";
				cin.getline(newPerson->adress, 40);

				// ����� ������
				cout << "Job: ";
				cin.getline(newPerson->job, 40);

				// ��������
				cout << "Salary: ";
				cin >> newPerson->salary;

				cout << "PRESS: ENTER[ENTER] RE-ENTER[R] QUIT[ESC]" << endl;
			}

			// ���� ������ �� ���������
			if (*flag)
			{
				cout << "PRESS: RE-ENTER[R] QUIT[ESC]" << endl;
			}

			// ���� 
			while (true)
			{
				*c = _getch();

				// ENTER[ENTER]
				if (!*flag && *c == '\r')
				{
					// ���������� ���������
					CryptOrDecrypt((char*)newPerson, *sizePerson, key, 1, *sizeKey);

					// ��������� ��������� � ����� �����
					fseek(file, 0, SEEK_END);

					// ������ ��������� � ����� �����
					fwrite(newPerson, sizeof(person_t), 1, file);

					// �������� �����
					fclose(file);

					delete newPerson, flag, c;

					delete[] * persons;

					// ������������ ���� 
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
	// ������ ��� ������ �������� ��� ID
	char* str = new char[20];

	// ���� ������� �������� � ����
	bool* flag = new bool;

	// ������ �����
	char* c = new char;

	// ��� ������: 0 - id; 1 - passport
	int* mode = new int;

	while (true)
	{
		*flag = false;

		system("cls");

		outLine();

		cout << "DELETE PERSON" << endl;

		outLine();

		// ���� ������ �������� ��� ID
		cout << "Enter passport or ID: ";
		cin.getline(str, 20);

		// ����� �� ����
		for (person_t* person = *persons; person < *persons + *countPersons; person++)
		{
			// ���� ������� ������
			if (!strcmp(person->id, str) || !strcmp(person->passport, str))
			{
				// ���� ��� ID
				if (!strcmp(person->id, str))
				{
					*mode = 0;
				}
				// ���� ��� passport
				else *mode = 1;

				// ���� ���� ��� ������ ������� � �������
				*flag = true;

				system("cls");

				outLine();

				cout << "DELETE PERSON" << endl;

				outLine();

				// ����� ��������
				cout << "Passport: " << person->passport << endl;

				// ����������������� ���
				cout << "ID: " << person->id << endl;

				// �������
				cout << "Surname: " << person->surname << endl;

				// ���
				cout << "Name: " << person->name << endl;

				// ��������
				cout << "Patronymic: " << person->patron << endl;

				// ����� ��������
				cout << "Adress: " << person->adress << endl;

				// ����� ������
				cout << "Job: " << person->job << endl;

				// �������� 
				cout << "Salary: " << person->salary << endl;


				cout << "\n\n\n\nPESS: RE-ENTER[R] DELETE[ENTER] QUIT[ESC]" << endl;

				// ���� 
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
						// �������� ������
						delete[] str;
						delete flag, c, mode;


						return;
					}

					// DELETE[ENTER]
					if (*c == 13)
					{
						// �������� ����� ������ ./Data/person.data � ������ ��������� ������/������
						FILE* file = fopen("./Data/person.data", "rb+");

						// ���� ���� ������� ������
						if (file != nullptr)
						{
							// ��������� ��������� � ����� �����
							fseek(file, 0, SEEK_END);

							// ������ ����� 
							size_t* sizeFile = new size_t;

							*sizeFile = ftell(file);

							// ��������� ��������� � ������ ����� 
							fseek(file, 0, SEEK_SET);

							// �����
							char* buffer = new char[*sizeFile];

							// ������ ����� � �����
							fread(buffer, sizeof(char), *sizeFile, file);

							// �������� �����

							// ����� �������� ������
							size_t* len = new size_t;

							*len = strlen(str);

							// ���������� �������� ������
							CryptOrDecrypt(str, *len, key, 1, *sizeKey);

							// ����� ����������� ������ 
							for (char* buf = buffer; buf < buffer + *sizeFile; buf++)
							{
								// ���� ���������� �������
								if (!strncmp(str, buf, *len))
								{
									// �������� ��������� � ������ 
									// ���� �������� ������ ID
									if (*mode == 0)
									{
										buf -= 84;
									}
									
									// ���� �������� ������ passport
									else if (*mode == 1)
									{
										buf -= 4;
									}

									short* n = new short;

									*n = *sizePerson;

									// �������� ������� �����
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

									// �������� ����� � ������ �������� ������
									file = fopen("./Data/person.data", "wb");

									// ������ � ���� �� ������ 
									fwrite(buffer, sizeof(char), *sizeFile, file);

									// �������� �����
									fclose(file);

									// �������� ������� ������ ���� �� ������
									delete[] * persons;

									// �������� ����� ������ ���� � ������
									LoadingPersons(persons, countPersons, sizePerson, key, sizeKey);

									// �������� ������
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

			// ���� 
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
					// �������� ������
					delete[] str;
					delete flag, c, mode;

					return;
				}
			}
		}
	}
}