#include <iostream>
#include <io.h>

// https://dropmefiles.com/6GKGE

using namespace std;

void main()
{
	/*unsigned int n = 3;
	unsigned int m = 5;
	cout << (n & m) << endl;*/

	//101
	// &
	//011
	//000

	// _A_NORMAL 0x00 // Normal file - No read/write restrictions		00000000
	// _A_RDONLY 0x01 // Read only file									00000001
	// _A_HIDDEN 0x02 // Hidden file									00000010
	// _A_SYSTEM 0x04 // System file									00000100
	// _A_SUBDIR 0x10 // Subdirectory									00001000
	// _A_ARCH   0x20 // Archive file									00010000

	//																	00011001
	//																	&
	//																	00001000
	// переменная, хранящая информацию об одном файле
	_finddata_t c_file;

	// адрес списка найденных файлов
    long hFile;

	// найти файлы по маске и вернуть адрес списка найденных файлов и информацию о первом файле
	hFile = _findfirst("c:\\temp\\*.*", &c_file);
	//
	//	11101
	//	&
	//	01000
	//	01000
	//
	// если файл является папкой
	if(c_file.attrib & _A_SUBDIR)
		cout << c_file.name << "   " << "<DIR>" << endl;
	else
		cout << c_file.name << "   " << c_file.size << endl;

	// цикл для получения информации об остальных найденных файлах
	while(_findnext( hFile, &c_file ) == 0)
	{
		if(c_file.attrib & _A_SUBDIR)
			cout << c_file.name << "   " << "<DIR>" << endl;
		else
			cout << c_file.name << "   " << c_file.size << endl;
	}

	// освободить память от списка найденных файлов
	_findclose(hFile);
}