#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <io.h>
#include <conio.h>

using namespace std;

// проверка расширения. 0 - не совпало; 1 - jpg, bmp, gif; 2 - txt;
int exprFile(char* name)
{
	char* expr = name + strlen(name) - 4;

	if (!strcmp(expr, ".jpg") || !strcmp(expr, ".bmp") || !strcmp(expr, ".gif"))
		return 1;
	if (!strcmp(expr, ".txt"))
		return 2;
	return 0;
}

void task2()
{
	// 2. Пользователь вводит путь к папке, программа сканирует
	// папку и копирует все картинки(jpg, bmp, gif) в папку
	// Images, а все текстовые файлы копируются в папку Txt

	// путь
	char* dir = new char[_MAX_PATH];

	// ввод пути к папке
	cout << "Enter path: ";
	cin.ignore();
	cin.getline(dir, _MAX_PATH);

	cout << endl;

	// путь к папке Images - для картинок
	char* images_path = new char[_MAX_PATH];

	// путь к папке по умолчанию
	strcpy(images_path, ".\\Images\\");

	// путь к папке Txt - для текстовых файлов
	char* txt_path = new char[_MAX_PATH];

	// путь к папке по умолчанию
	strcpy(txt_path, ".\\Txt\\");

	// выбор: вводить пути к папкам или нет
	bool* path = new bool;

	// выбор
	cout << "Enter the path to images and txt?(Y/N): ";

	// показатель для выбора
	char* ch = new char;

	// ввод выбора
	while (true)
	{
		*ch = _getch();

		// если да 
		if (*ch == 'Y' || *ch == 'y')
		{
			cout << "Y" << endl;

			*path = true;

			break;
		}

		// если нет
		if (*ch == 'N' || *ch == 'n')
		{
			cout << "N" << endl;

			*path = false;

			break;
		}
	}

	cout << endl;

	// если пользователь выбрал ввод новых путей к папкам Images и Txt
	if (*path)
	{
		// ввод нового пути к Images
		cout << "Enter path Images: ";
		cin.getline(images_path, _MAX_PATH);

		// добавелние к пути '\\'
		strcat(images_path, "\\");

		// ввод нового пути к Txt
		cout << "Enter path Txt: ";
		cin.getline(txt_path, _MAX_PATH);

		// добавелние к пути '\\'
		strcat(txt_path, "\\");

		cout << endl;
	}

	// выбор копировать или перемещать файлы
	cout << "Copy or moving (C/M): ";

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

	// добавление к пути '\'
	strcat(dir, "\\");

	// указатель на начало имени файла в пути
	char* name = dir + strlen(dir);

	// указатель на начало имени в пути к файлу в папке Images
	char* images = images_path + strlen(images_path);

	// указатель на начало имени в пути к фалйлу в папке Txt
	char* txt = txt_path + strlen(txt_path);

	// прибавка к путю файла маски 
	strcat(name, "*");

	// список 
	_finddata_t list;

	// указатель на список и создание списка
	long point = _findfirst(dir, &list);

	// отчистка консоли
	system("cls");

	// указатель на файл ресурса 
	FILE* file = nullptr;

	// массив счётчиков для файлов images; [0] - всего файлов, [1] - удачно, [3] - неудачно; [4] - общий размер;
	unsigned long* count_images = new unsigned long[4];

	*count_images = 0;
	*(count_images + 1) = 0;
	*(count_images + 2) = 0;
	*(count_images + 3) = 0;

	// массив счётчиков для файлов txt; [0] - всего файлов, [1] - удачно, [3] - неудачно; [4] - общий размер;
	unsigned long* count_txt = new unsigned long[4];

	*count_txt = 0;
	*(count_txt + 1) = 0;
	*(count_txt + 2) = 0;
	*(count_txt + 3) = 0;

	// вывод содержания всей папки
	do
	{
		// если файл не является папкой
		if (!(list.attrib & _A_SUBDIR))
		{
			// jpg, bmp, gif,
			if (exprFile(list.name) == 1)
			{
				// вывод имени файла и его размера
				cout << list.name << "     " << list.size << "     ";

				*count_images += 1;

				// ------- копирование 

				// добавление имени файла к пути
				strcpy(name, list.name);

				// открытие файла ресурса в режиме бинарного чтения
				file = fopen(dir, "rb");

				// если файл ресурса открыт успешно
				if (file != nullptr)
				{
					// буфер
					char* buff = new char[list.size];

					// считывание файла ресурса в буфер
					fread(buff, sizeof(char), list.size, file);

					// закрытие файла ресурса 
					fclose(file);

					// добавление имени к пути назначения
					strcpy(images, list.name);

					// создание и открытие файла назначения в режиме бинарной записи
					file = fopen(images_path, "wb");

					// если файл назначения открыт успешно
					if (file != nullptr)
					{
						// запись в файл назначения из буфера
						fwrite(buff, sizeof(char), list.size, file);

						// проверка записи по размеру
						if (ftell(file) != list.size)
						{
							cout << "ERROR WRITE" << endl;

							// закрытие файла 
							fclose(file);

							// удаление неудачно записанного файла
							remove(images_path);

							continue;
						}

						// закрытие файла ресурса 
						fclose(file);

						// удаление файла ресурса (если выбрано перемещение)
						if (moving)
						{
							// удаление исходного файла
							if (remove(dir) == -1)
							{
								cout << "ERROR DELETE SOURCE FILE!" << endl;

								// увеличение счётчика неудачно перемещённых файлов
								*(count_images + 2) += 1;

								// удаление копии файла
								remove(images_path);

								continue;
							}
						}

						// увеличение счётчика успешно записанных файлов
						*(count_images + 1) += 1;

						delete[] buff;

						cout << "SAVE" << endl;

						// увеличение суммарного размера 
						*(count_images + 3) += list.size;
					}
					// если открыт неудачно
					else
					{
						cout << "ERROR CREATE DESTINATION FILE!" << endl;
						*(count_images + 2) += 1;
					}
				}
				// если файл открыт неудачно 
				else
				{
					cout << "ERROR OPENING SOURCE FILE!" << endl;
					*(count_images + 2) += 1;
				}
			}

			// txt
			if (exprFile(list.name) == 2)
			{
				// вывод имени файла и его размера
				cout << list.name << "     " << list.size << "     ";

				*count_txt += 1;

				// ------- копирование 

				// добавление имени файла к пути
				strcpy(name, list.name);

				// открытие файла ресурса в режиме бинарного чтения
				file = fopen(dir, "rb");

				// если файл ресурса открыт успешно
				if (file != nullptr)
				{
					// буфер
					char* buff = new char[list.size];

					// считывание файла ресурса в буфер
					fread(buff, sizeof(char), list.size, file);

					// закрытие файла ресурса 
					fclose(file);

					// добавление имени к пути назначения
					strcpy(txt, list.name);

					// создание и открытие файла назначения в режиме бинарной записи
					file = fopen(txt_path, "wb");

					// если файл назначения открыт успешно
					if (file != nullptr)
					{
						// запись в файл назначения из буфера
						fwrite(buff, sizeof(char), list.size, file);

						// проверка записи по размеру
						if (ftell(file) != list.size)
						{
							cout << "ERROR WRITE" << endl;

							// закрытие файла 
							fclose(file);

							// удаление неудачно записанного файла
							remove(txt_path);

							continue;
						}

						// закрытие файла ресурса 
						fclose(file);

						// удаление файла ресурса (если выбрано перемещение)
						if (moving)
						{
							// удаление исходного файла
							if (remove(dir) == -1)
							{
								cout << "ERROR DELETE SOURCE FILE!" << endl;

								// увеличение счётчика неудачно перемещённых файлов
								*(count_txt + 2) += 1;

								// удаление копии файла
								remove(txt_path);

								continue;
							}
						}

						// увеличение счётчика успешно записанных файлов
						*(count_txt + 1) += 1;

						delete[] buff;

						cout << "SAVE" << endl;

						// увеличение суммарного размера 
						*(count_txt + 3) += list.size;
					}
					// если открыт неудачно
					else
					{
						cout << "ERROR CREATE DESTINATION FILE!" << endl;

						*(count_txt + 2) += 1;
					}
				}
				// если файл открыт неудачно 
				else
				{
					cout << "ERROR OPENING SOURCE FILE!" << endl;

					*(count_txt + 2) += 1;
				}
			}
		}
	} while (!_findnext(point, &list));

	cout << endl;

	// удаление списка
	_findclose(point);

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

	// всего файлов 
	cout << "All files: " << *count_images + *count_txt << endl;

	// всего удачно
	cout << "All successfully: " << *(count_images + 1) + *(count_txt + 1) << "     " << "Size: " << *(count_images + 3) + *(count_txt + 3) << endl;

	// всего неудчано
	cout << "All nosuccessfully: " << *(count_images + 2) + *(count_txt + 2) << endl;

	cout << endl;

	// отчёт по изображениям
	cout << "Images files: " << *count_images << endl;

	// удачно 
	cout << "Images successfully: " << *(count_images + 1) << "     " << "Size: " << *(count_images + 3) << endl;

	// неудачно 
	cout << "Images nosuccessfully: " << *(count_images + 2) << endl;

	cout << endl;

	// отчёт по текстовым файлам
	cout << "Text files: " << *count_txt << endl;

	// удычно 
	cout << "Text file successfully: " << *(count_txt + 1) << "     " << "Size: " << *(count_txt + 3) << endl;

	// неудачно
	cout << "Text file nosuccessfully: " << *(count_txt + 2) << endl;
}