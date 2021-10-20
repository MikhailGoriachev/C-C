#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>
#include <conio.h>

using namespace std;

void filesOper(unsigned long* count_files, char* path_s, char* path_d, bool* moving, unsigned long* size_min)
{
	// копия чистой директории назначения
	char* path_dest = new char[_MAX_PATH];

	// копирование пути назначения
	strcpy(path_dest, path_d);

	// добавка к пути ресурса '\\'
	strcat(path_s, "\\");

	// указатель на начало имени пути ресурса
	char* name_s = path_s + strlen(path_s);

	// указатель на начало имени пути назначения
	char* name_d = path_dest + strlen(path_d);

	// добавка к пути ресурса маски
	strcat(path_s, "*");

	// список файлов
	_finddata_t list;

	// указатель на список 
	long point = _findfirst(path_s, &list);

	// указатель на файл
	FILE* file = nullptr;

	// копирование/перемещение файлов из папки
	do
	{
		// если это папка "." или ".."
		if (!strcmp(list.name, ".") || !strcmp(list.name, ".."))
		{
			continue;
		}

		// создание пути файла 
		strcpy(name_s, list.name);

		// вывод имени
		cout << "> " << list.name << "     ";

		// если файл является папкой
		if (list.attrib & _A_SUBDIR)
		{
			// увеличение счётчика количества папок
			*count_files += 1;

			cout << "<DIR>" << endl << endl;

			// добавка к пути ресурса '\\'
			strcat(name_s, "\\");

			// рекурсивный вызов функции
			filesOper(count_files, path_s, path_d, moving, size_min);

			cout << endl << endl;
		}

		// если это обычный файл
		else
		{
			// если размер файла меньше минимального размера введённого пользователем
			if (*size_min > list.size)
			{
				cout << "SMALL SIZE!" << endl;
				
				// увеличение счётчика количетсва неподходящих по размеру файлов
				*(count_files + 7) += 1;

				// увеличение общего размера неподходящих по размеру файлов
				*(count_files + 8) += list.size;

				continue;
			}

			// увеличение счётчика количества файлов
			*(count_files + 1) += 1;

			// увеличение общего размера всех файлов
			*(count_files + 2) += list.size;

			// вывод размера файла
			cout << list.size << "     ";

			// открытие файла ресурса в режиме бинарного чтения
			file = fopen(path_s, "rb");

			// если файл открыт удачно
			if (file != nullptr)
			{
				// буфер для файла ресурса 
				char* buff = new char[list.size];

				// считывание файла ресурса в буфер
				fread(buff, sizeof(char), list.size, file);

				// закрытие файла ресурса
				fclose(file);

				// прибавление имени к пути назначения
				strcpy(name_d, list.name);

				// создание и открытие файла назначения в режиме бинарной записи
				file = fopen(path_dest, "wb");

				if (file != nullptr)
				{
					// запись в файл из буфера
					fwrite(buff, sizeof(char), list.size, file);

					// сравнение файлов по размеру
					if (ftell(file) != list.size)
					{
						cout << "ERROR WRITE DESTINATOIN FILE!" << endl;

						// увеличение счётчика неудач
						*(count_files + 3) += 1;

						// увеличение общего размера неудачных файлов
						*(count_files + 6) += list.size;

						continue;
					}

					// закрытие файла назначения
					fclose(file);

					// если выбрано перемещение 
					if (*moving)
					{
						// если файл ресурса неудачно удалён
						if (remove(path_s) == -1)
						{
							cout << "ERROR REMOVE SOURCE FILE!" << endl;

							*(count_files + 4) += 1;

							// увеличение общего размера неудачных файлов
							*(count_files + 6) += list.size;

							continue;
						}
					}

					// увеличение счётчика удачных файлов
					*(count_files + 3) += 1;

					// прибавлене размера файла к суммарному размеру удачных файлов
					*(count_files + 5) += list.size;

					cout << "SAVE" << endl;
				}
				// если файл назначения создан и открыт неудачно
				else
				{
					cout << "ERROR OPENING DESTINATION FILE!" << endl;

					// увеличене счётчика неудач
					*(count_files + 4) += 1;

					// увеличение общего размера неудачных файлов
					*(count_files + 6) += list.size;

					continue;
				}

				// отчистка памяти
				delete[] buff;

			}
			// если файл открыт неудачно
			else
			{
				cout << "ERROR OPENING SOURCE FILE!" << endl;

				// увеличение счётчика неудач
				*(count_files + 3) += 1;

				// увеличение общего размера неудачных файлов
				*(count_files + 6) += list.size;
			}
		}
	} while (!_findnext(point, &list));

	// удаление списка
	_findclose(point);
}

void task3()
{
	// 3. Пользователь вводит 2 пути к папкам, программа копирует 
	// все файлы из первой папки во вторую, копируются только те файлы,
	// размер которых не превышает заранее введенный пользователем размер
	// (усложнение: копирование из папок и подпапок)

	// директория ресурса 
	char* source_path = new char[_MAX_PATH];

	// ввод пути ресурса
	cout << "Enter source path: ";
	cin.ignore();
	cin.getline(source_path, _MAX_PATH);

	// прибавление к пути '\\'
	// strcat(source_path, "\\");

	// директория назначения
	char* dest_path = new char[_MAX_PATH];

	// ввод пути назначения
	cout << "Enter destination path: ";
	cin.getline(dest_path, _MAX_PATH);

	// прибавление к пути '\\'
	strcat(dest_path, "\\");

	// выбор копировать или перемещать файлы
	cout << "Copy or moving (C/M): ";


	// показатель для выбора
	char* ch = new char;

	// перемещение
	bool* moving = new bool;

	// ввод выбора
	while (true)
	{
		*ch = _getch();

		// если да 
		if (*ch == 'M' || *ch == 'm')
		{
			cout << "M" << endl;

			*moving = true;

			break;
		}

		// если нет
		if (*ch == 'C' || *ch == 'c')
		{
			cout << "C" << endl;

			*moving = false;

			break;
		}
	}

	delete ch;

	// минимальный размер файла
	unsigned long* size_min = new unsigned long;

	// запрос у пользователя минимального размера файла
	cout << "Enter minimum size: ";
	cin >> *size_min;


	// счётчик файлов; [0] - количество папок; [1] - количетсво файлов; [2] - размер файлов; [3] - счётчик удач; [4] - счётчик неудач; 
	// [5] - размер всех удачных файлов; [6] - размер всех неудачных файлов; [7] - количество файлов меньше требуемого минимального размера;
	// [8] - общий размер неподходящих по размеру файлов;
	unsigned long* count_files = new unsigned long[8];

	// счётчик количества папок
	*count_files = 0;

	// счётчик количества файлов
	*(count_files + 1) = 0;

	// счётчик общего размера файлов
	*(count_files + 2) = 0;

	// счётчик удач 
	*(count_files + 3) = 0;

	// счётчик неудач
	*(count_files + 4) = 0;

	// размер всех удачных файлов
	*(count_files + 5) = 0;

	// размер всех неудачных файлов
	*(count_files + 6) = 0;

	// количество файлов меньше требуемого минимального размера
	*(count_files + 7) = 0;

	// общий размер неподходящих по размеру файлов
	*(count_files + 8) = 0;

	// отчистка консоли
	system("cls");

	// рекурсивная функция копирования/перемещения файлов
	filesOper(count_files, source_path, dest_path, moving, size_min);

	// программа завершает копирование/перемещение, сообщает об этом пользователю
	// и запрашивает нажатие клавиши "Enter", вывести отчёт о работе 
	if (!moving)
		cout << "----------------- MOVE COMPLITED -----------------" << endl;
	else cout << "----------------- COPY COMPLITED -----------------" << endl;

	cout << "Press [enter]" << endl;

	while (_getch() != '\r');

	// отчистка консоли
	system("cls");

	// вывод результата
	if (!moving)
		cout << "----------------- RESULT MOVING -----------------" << endl;
	else cout << "----------------- RESULT COPY -----------------" << endl;

	cout << endl;

	// отчёт о выполнении
	// общий размер
	cout << "All size: " << *(count_files + 5) << endl;
	// количество папок
	cout << "Count folders: " << *count_files << endl;
	// количество файлов
	cout << "Count files: " << *(count_files + 1) << endl;
	// количество удачных файлов
	cout << "Count successfully files: " << *(count_files + 3) << "     Size: " << *(count_files + 5) << endl;
	// количетсво неудачных файлов
	cout << "Count nosuccessfully files: " << *(count_files + 4) << "     Size: " << *(count_files + 6) << endl;
	// количество файлов неподходящих по размеру
	cout << "Count small size files: " << *(count_files + 7) << "     Size: " << *(count_files + 8) << endl;

	cout << endl;
}
