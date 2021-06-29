/*
*	Example:
*	Source text: llllaaawwqw
*	Cpmpression text: l4a3w2qw
*/



#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <Windows.h>

using namespace std;

#define a1 num.find_last_not_of("-0123456789")
#define a2 num.find_last_of("-")

class CompressionAlgorith
{
private:
	ofstream Folder;
public:
	CompressionAlgorith(string newFileName);
	void Compression(string oldText);
	void DeCompression(string oldText);
	~CompressionAlgorith();
};

CompressionAlgorith::CompressionAlgorith(string newFileName)
{
	Folder.open(newFileName);
}

void CompressionAlgorith::Compression(string oldText)
{
	if (Folder.is_open())
	{
		// цикл считывающий каждый элемент текстовой переменной
		// цикл прекращается, когда доходит до конца строки
		for (int i = 0; i < oldText.length();)
		{
			//Создание переменной принимающее в себя текущее значение символа из текстовой переменной 
			char tempChar = oldText[i];
			// создание переменной для счетчика повторяющих символов
			int temp = 0;
			// цикл для проверки, является ли последующее значение похожим текущий символ
			// цикл прекращается, когда текущий символ не будет равным текущему миволу в цикле
			for (; tempChar == oldText[i];)
			{
				// если условие верно, то итератор переходит на следующий символ
				i++;
				// если условие верно, то переменная повторяющихся символов увиличивается
				temp++;
			}
			// Условие сравнивающее переменную повторяющихся символов с 1
			if (temp > 1)
			{
				// если условие верно, то в файл записывается текущий элемент и
				// переменнная повтооряющихся элементов 
				Folder << tempChar << to_string(temp);
			}
			else
			{
				// если условие неверно, то в файл записывается только текущий символ
				Folder << tempChar;
			}
		}
		Folder << endl;
	}
	else
	{
		// если условие не срабатывает, то выводится сообщение об ошибке
		cout << "Trabls" << endl;
	}
}

void CompressionAlgorith::DeCompression(string oldText)
{
	// Проверка открытия файла
	if (Folder.is_open())
	{
		// цикл считывающий каждый элемент текстовой переменной
		// цикл прекращается, когда доходит до конца строки
		for (int i = 0; i < oldText.length(); i++)
		{
			// Условие провкрки, является ли текущий элемент цифрой или нет
			if (oldText[i] > 47 && oldText[i] < 58)
			{
				// если условие верно, то текущий элемент является цифрой
				// ввод переменных счетчика цифр
				string numCount;
				// Переменная принимающая в себя предыдущий элемент, перед цифрой - символ
				char temp = oldText[i - 1];
				// цикл с уловием выхода: если екущий элемент данного цикла не будет являться цифрой
				for (; oldText[i] > 47 && oldText[i] < 58; i++)
					// Если элемент является цифрой, то он добавляется в конец текстовой переменной
					// если не является, то цикл прекращается
					numCount.push_back(oldText[i]);
				// цикл с условием выхода: пока не будет достигнута переведенная в числовое значение текстовая переменная счетчика цифр
				for (int j = 0; j < atoi(numCount.c_str()); j++)
					// в файл записывается текущий элемент
					Folder << temp;
			}
			else
				// если элемент не является цифрой, то он записывается в файл
				Folder << oldText[i];
		}
		Folder << endl;
	}
	else
	{
		// если условие не срабатывает, то выводится сообщение об ошибке
		cout << "Trabls" << endl;
	}

}

CompressionAlgorith::~CompressionAlgorith()
{
	Folder.close();
}




class OpenReadText
{
private:
	ifstream sourceFile;
public:
	OpenReadText(string nameFile);
	void stringTransfer(int choice);
	~OpenReadText();
};

OpenReadText::OpenReadText(string nameFile)
{
	sourceFile.open(nameFile);
}

void OpenReadText::stringTransfer(int choice)
{
	// Условие проверки отрытия файла
	if (sourceFile.is_open())
	{
		string newFileName;
		cout << "Input name for new file: ";
		cin >> newFileName;
		string transfer;
		// Создание объекта класса Алогритма компрессии	
		CompressionAlgorith temp(newFileName);
		if (choice == 1)
		{
			// Считывание строки в текстовую переменную transfer
			while (getline(sourceFile, transfer))
				// Вызов метода компрессии с агрументом текстовой строки
				temp.Compression(transfer);
		}
		else
		{
			// Считывание строки в текстовую переменную transfer
			while (getline(sourceFile, transfer))
				// Вызов метода декомпрессии с агрументом текстовой строки
				temp.DeCompression(transfer);
		}
	}
	else
	{
		// Если файл не открывается выдается сообщение говорящее об ошибке
		cout << "There is no file to read" << endl;
	}
}

OpenReadText::~OpenReadText()
{
	// Закрытие файла
	// Удаление памяти выделенной для использования класса
	if (sourceFile.is_open())
		sourceFile.close();
}


int check_input_int();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choice = 1;
	cout << "1 - Compression file" << endl;
	cout << "2 - Decompression file" << endl;
	cout << "3 - Exit" << endl;
	cout << "Make a choice: ";
	choice = check_input_int();

	if (choice < 2)
	{
		string fileName;
		cout << "Input file name: ";
		cin >> fileName;

		OpenReadText file(fileName);
		file.stringTransfer(choice);
	}
	else
	{
		cout << "Bye Bye" << endl;
	}
	return 0;
}

int check_input_int()
{
	string num;
	int n = 0;
	do
	{
		do
		{
			cout << " = ";
			getline(cin, num);
		} while ((a1 != -1) or (a2 != -1 and a2 != 0));
		n = atoi(num.c_str());
	} while (n < 1 && n > 3);
	return n;
}