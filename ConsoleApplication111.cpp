#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

void main()
{
	setlocale(LC_ALL, "russian");

	int amount = 3,//количество смартфонов
		amount2 = 10,//количество характеристик    
	    answer = -1;
	string** Smartphone = new string * [amount];
	string* chosen = new string[amount2];

	for (int i = 0; i < amount; i++)
	{
		Smartphone[i] = new string[amount2];
	}

	int amount3 = 3,//количество телефонов
		amount4 = 10;//количество характеристик    
	string** Phone = new string * [amount];
	string* chosen1 = new string[amount4];

	for (int i = 0; i < amount3; i++)
	{
		Phone[i] = new string[amount4];
	}

	ifstream F1("Smartphones.txt");

	if (!F1)
	{
		cout << "Cannot open file.\n";
		return;
	}

	for (int i = 0; i < amount; i++)
	{
		for (int j = 0; j < amount2; j++)
		{
			F1 >> Smartphone[i][j];
		}
	}

	F1.close();

	ifstream F2("Phones.txt");

	if (!F2)
	{
		cout << "Cannot open file.\n";
		return;
	}

	for (int i = 0; i < amount3; i++)
	{
		for (int j = 0; j < amount4; j++)
		{
			F2 >> Phone[i][j];
		}
	}

	F2.close();

	cout << "Вам нужен телефон с сенсорным экраном?\n1)Да 2)Нет\n";
	int n, n1, t;
	cin >> n1;

	if (n1 == 1)
	{
		cout << "Введите номер характеристики\n";
		cout << "1 - Цена; 2 - Разрешение экрана; 3 - Модель процессора;\n4 - Объем оперативной памяти; 5 - Объем встроенной памяти; 6 - Количество мегапикселей основной камеры;\n7 - Модуль NFC; 8 - Разъем для наушников; 9 - Емкость аккумулятора;\n0 - 3акончить ввод;\n";

		for (int i = 0; i < amount2; i++)
		{
			cin >> t;

			if (t == 0)
			{
				break;
			}

			cout << "Введите нужное значение\n";

			for (int i = 0; i < amount; i++)
			{
				cout << i + 1 << " - " << Smartphone[i][t] << "; ";
			}

			cin >> n;

			chosen[t] = Smartphone[n - 1][t];

			cout << "Введите номер характеристики\n";
			cout << "1 - Цена; 2 - Разрешение экрана; 3 - Модель процессора;\n4 - Объем оперативной памяти; 5 - Объем встроенной памяти; 6 - Количество мегапикселей основной камеры;\n7 - Модуль NFC; 8 - Разъем для наушников; 9 - Емкость аккумулятора;\n0 - 3акончить ввод;\n";

		}

	}
	else if (n1 == 2)
	{
		cout << "Введите номер характеристики\n";
		cout << "1 - Цена; 2 - Тип корпуса;  3 - Доступ в интернет; 4 - Слот для карты памяти;\n5 - Kамера; 6- Bluetooth; 7  - Емкость аккумулятора;\n0 - 3акончить ввод;\n";

		for (int i = 0; i < amount4; i++)
		{
			cin >> t;

			if (t == 0)
			{
				break;
			}

			cout << "Введите нужное значение\n";

			for (int i = 0; i < amount3; i++)
			{
				cout << i + 1 << " - " << Phone[i][t] << "; ";
			}

			cin >> n;

			chosen1[t] = Phone[n - 1][t];

			cout << "Введите номер характеристики\n";
			cout << "1 - Цена; 2 - Тип корпуса;  3 - Доступ в интернет; 4 - Слот для карты памяти;\n5 - Kамера; 6- Bluetooth; 7  - Емкость аккумулятора;\n0 - 3акончить ввод;\n";

		}
	}
	else
	{
		cout << "Непонятное значение!";
	}

	int *count = new int[amount];
	int* count1 = new int[amount3];

	for (int i = 0; i < amount; i++)
	{
		count[i] = 0;
	}

	for (int i = 0; i < amount3; i++)
	{
		count1[i] = 0;
	}

	if (n1 == 1)
	{
		for (int i = 0; i < amount; i++)
		{
			for (int j = 0; j < amount2; j++)
			{
				if (chosen[j] == Smartphone[i][j])
				{
					count[i]++;
				}
			}
		}

		for (int i = 0; i < amount - 1; i++)
		{
			if (count[i] > count[i + 1])
			{
				answer = i;
			}
			else
			{
				answer = i + 1;
			}
		}

		cout << "Наиболее подходящий телефон:\n" << Smartphone[answer][0];
	}
	else if (n1 == 2)
	{
		for (int i = 0; i < amount3; i++)
		{
			for (int j = 0; j < amount4; j++)
			{
				if (chosen1[j] == Phone[i][j])
				{
					count1[i]++;
				}
			}
		}

		for (int i = 0; i < amount3 - 1; i++)
		{
			if (count1[i] > count1[i + 1])
			{
				answer = i;
			}
			else
			{
				answer = i + 1;
			}
		}

		cout << "Наиболее подходящий телефон:\n" << Phone[answer][0];
	}

}