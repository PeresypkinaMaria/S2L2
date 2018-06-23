#pragma once
#include <stdio.h>
#include <sstream>
#include <math.h>
#include <string>
#include <iostream>
#include "HelpUtils.h"
#include "MyDate.h"

using namespace std;

class baggage {
public:
	int FlightNum; //номер рейса
	MyDate DepDate; //дата вылета
	string Destination; //пунк назначения
	string Surname; //фамилия пассажира
	int NumPieces; //количество мест багажа
	int Weight; //вес багажа

	//конструктор
	baggage();

	//изменение структуры
	baggage ChangeBaggage(baggage &res);

	//перегруженный оператор равенства
	baggage& operator = (baggage b);
};

//ввод с консоли
baggage InputBaggage();

//вывод на консоль
void OutputBaggage(baggage b);

//перевод структуры в строку
string ToString(baggage b, int i);

//считывание структуры из строки
baggage ReadFromString(ifstream& input);

//поиск по выбранному критерию
bool SearchInfo(baggage b1, baggage b2, int type_search);

//ввод критерия сортировки в зависимости от выбранного типа
baggage InputForSearchInfo(int type_search);

//сравнение структур в зависимости от выбранного поля для сортировки
int Сomparison(baggage b1, baggage b2, int type_search);



/*baggage InputBaggage()
{
	baggage b;
	b.FlightNum = InputNumber(0, 100, "Введите номер рейса: ");
	b.DepDate.InputDate();
	b.Destination = InputInformation("Введите пункт назначения: ");
	b.Surname = InputInformation("Введите фамилию пассажира: ");
	b.NumPieces = InputNumber(0, 200, "Введите количество мест для багажа: ");
	b.Weight = InputNumber(0, 100, "Введите вес багажа: ");
	return b;
}

//вывод на консоль
void OutputBaggage(baggage b)
{
	cout << "Номер рейса: " << b.FlightNum << endl;
	cout << "Дата вылета: " << b.DepDate.ToString() << endl;
	cout << "Пункт назначения: " << b.Destination << endl;
	cout << "Фамилия пассажира: " << b.Surname << endl;
	cout << "Количество мест для багажа: " << b.NumPieces << endl;
	cout << "Вес багажа: " << b.Weight << endl;
}

//считывание даты из строки
MyDate DateFromString(string str)
{
	MyDate date;
	try 
	{
		istringstream s(str);
		string s1;
		if (getline(s, s1, ' '))
			date.day = atoi(s1.c_str()); //atoi - преобразует строку в целое число
		if (getline(s, s1, ' '))
			date.month = atoi(s1.c_str());
		if (getline(s, s1, ' '))
			date.year = atoi(s1.c_str());
	}
	catch (...)
	{
		cout << "Ошибка записи в файл!" << endl;
	}
	return date;
}

//считываение baggage из строки
baggage BagFromString(ifstream& str)
{
	baggage bag;
	string s;
	try
	{
		if (!str.eof())
			getline(str, s);
		if (!str.eof())
		{
			getline(str, s, '\n');
			string wrd = "Номер рейса: ";
			bag.FlightNum = atoi(s.substr(wrd.length(), s.length()).c_str()); //substr - возвращает указанное количество элементов из строки
		}
		//if (!str.eof())
			///////
	}
	catch (...)
	{
		cout << "Ошибка записи в файл!" << endl;
	}
	return bag;
}

//поиск по критериям
bool SearchInfo(baggage b1, baggage b2, int type_search)
{
	switch (type_search)
	{
	case 1:
		return (b1.FlightNum == b2.FlightNum);
	case 2:
		return (b1.DepDate == b2.DepDate);
	case 3:
		return (b1.Destination == b2.Destination);
	case 4:
		return (b1.Weight == b2.Weight);
	default:
		return false;
	}
}

//ввод выбранного критерия
baggage InputForSearchInfo(int type_search)
{
	baggage bag;
	switch (type_search)
	{
	case 1:
		bag.FlightNum = InputNumber(0, 100, "Введите номер рейса: ");
		return bag;
	case 2:
		bag.DepDate.InputDate();
		return bag;
	case 3:
		bag.Destination = InputInformation("Введите пункт назначения: ");
		return bag;
	case 4:
		bag.Weight = InputNumber(0, 100, "Введите вес багажа: ");
	default:
		return bag;
	}
}

int Сomparison(baggage b1, baggage b2, int type_search)
{
	switch (type_search)
	{
	case 1:
		if (b1.FlightNum > b2.FlightNum)
			return 1;
		else
			if (b1.FlightNum < b2.FlightNum)
				return -1;
			else
				return 0;
	case 2:
		if (b1.DepDate > b2.DepDate)
			return 1;
		else
			if (b1.DepDate < b2.DepDate)
				return -1;
			else
				return 0;
	case 3:
		if (b1.Destination > b2.Destination)
			return 1;
		else
			if (b1.Destination < b2.Destination)
				return -1;
			else
				return 0;
	case 4:
		if (b1.Weight > b2.Weight)
			return 1;
		else
			if (b1.Weight < b2.Weight)
				return -1;
			else
				return 0;
	default:
		return -2;
	}
}*/