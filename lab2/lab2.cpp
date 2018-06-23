#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <Windows.h>
#include "baggage.h"
#include "Search.h"
#include "HelpUtils.h"

//меню
int Menu()
{
	cout << endl;
	cout << "Выберете необходимое действие" << endl;
	cout << "1 - Добавить элемент" << endl;
	cout << "2 - Удалить элемент" << endl;
	cout << "3 - Изменить элемент" << endl;
	cout << "4 - Вывод на экран" << endl;
	cout << "5 - Сохранить в файл" << endl;
	cout << "6 - Линейный поиск" << endl;
	cout << "7 - Двоичный поиск" << endl;
	cout << "8 - Вывести подмножество на экран" << endl;
	cout << "9 - Сохранить подмножество в файл" << endl;
	cout << "0 - Выход" << endl;
	int num = InputNumber(0, 9, "Ваш выбор: ");
	cout << endl;
	return num;
}

bool ChangeInputData()
{
	Task<baggage> task;
	bool change = true;
	cout << "Выберите один из пунктов меню: " << endl;
	cout << "1 - Заполнение контейнера с консоли" << endl;
	cout << "2 - Заполнение контейнера из файла " << endl;
	cout << "0 - Выход" << endl;
	int changemenu = InputNumber(0, 2, "Ваш выбор: ");
	switch (changemenu)
	{
	case 1:
		task.ReadFromScreen(InputBaggage);
		break;

	case 2:
		change = task.ReadFromFile(ReadFromString);
		break;

	default:
		change = false;
		break;
	}
	if (change)
	{
		baggage elem;
		vector<baggage> subset;
		baggage search_elem;
		int numb;
		while (1)
		{
			int n = Menu();
			switch (n)
			{
			case 1:
				task.Add(InputBaggage());
				break;

			case 2:
				task.OutputScreen(task.vect, OutputBaggage);
				cout << "Всего - " << task.size() << endl;
				task.Remove(InputNumber(0, task.size(), "\nВведите номер удаляемого эл-та (0 - если передумали удалять):"));
				break;

			case 3:
				task.OutputScreen(task.vect, OutputBaggage);
				cout << "Всего - " << task.size() << endl;
				numb = InputNumber(0, task.size(), "\nВведите номер изменяемого эл-та (0 - если передумали изменять): ");
				if (numb != 0)
				{
					task.vect[numb - 1] = elem.ChangeBaggage(task.vect[numb - 1]);
					cout << "Данные изменены!" << endl;
				}
				break;

			case 4:
				task.OutputScreen(task.vect, OutputBaggage);
				break;

			case 5:
				task.OutputFile(task.vect, ToString);
				break;

			case 6:
				numb = InputNumber(1, 4, "Выберите тип поиска:\n 1 - по номеру рейса\n 2 - по пункту назначения\n 3 - по весу багажа\n 4 - по дате и времени вылета \nВаш выбор: ");
				search_elem = InputForSearchInfo(numb);
				subset = task.LinearySearch(search_elem, SearchInfo, numb);
				if (subset.size() != 0)
					task.OutputScreen(subset, OutputBaggage);
				else
					cout << "Элементы не найдены" << endl;
				break;

			case 7:
				numb = InputNumber(1, 3, "Выберите тип поиска:\n 1 - по номеру рейса\n 2 - по пункту назначения\n 3 - по весу багажа\n 4 - по дате и времени вылета \nВаш выбор: ");
				search_elem = InputForSearchInfo(numb);
				subset = task.BinarySearch(numb, search_elem, Сomparison, SearchInfo);
				if (subset.size() != 0)
					task.OutputScreen(subset, OutputBaggage);
				else
					cout << "Элементы не найдены" << endl;
				break;

			case 8:
				task.OutputScreen(subset, OutputBaggage);
				break;

			case 9:
				task.OutputFile(subset, ToString);
				break;


			default:
				cout << "Выход " << endl; exit(0);
				break;

			}
		}
	}
	system("pause");
}

void main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ChangeInputData();
}