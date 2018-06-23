#pragma once
#include "stdafx.h"
#include <stdio.h>
#include <sstream>
#include <math.h>
#include <string>
#include <iostream>
#include <string>
#include "HelpUtils.h"
#include "MyDate.h"
#include "baggage.h"
using namespace std;

baggage::baggage()
{
	FlightNum = 0;
	MyDate DepDate;
	Destination = "";
	Surname = "";
	NumPieces = 0;
	Weight = 0;
}

baggage baggage::ChangeBaggage(baggage &res)
{
	cout << "Какое поле вы хотите изменить?" << endl;
	cout << "1 - Номер рейса" << endl;
	cout << "2 - Дата вылета" << endl;
	cout << "3 - Пункт назначения" << endl;
	cout << "4 - Фамилия пассажира" << endl;
	cout << "5 - Количество мест багажа" << endl;
	cout << "6 - Вес багажа" << endl;
	cout << "0 - Отмена" << endl;
	int num = InputNumber(0, 6, "");
	switch (num)
	{
	case 1: 
		res.FlightNum = InputNumber(0, 100, "Введите номер рейса: ");
		break;
	case 2:
		res.DepDate.InputDate();
		break;
	case 3:
		res.Destination = InputInformation("Введите пункт назначения: ");
		break;
	case 4:
		res.Surname = InputInformation("Введите фамилию пассажира: ");
		break;
	case 5:
		res.NumPieces = InputNumber(0, 200, "Введите количество мест для багажа: ");
		break;
	case 6:
		res.Weight = InputNumber(0, 100, "Введите вес багажа: ");
		break;
	default:
		cout << "Выход " << endl; exit(0);
		break;
	}
	return res;
}

// перегруженный оператор равенства
baggage& baggage::operator = (baggage b)
{
	FlightNum = b.FlightNum;
	DepDate = b.DepDate;
	Destination = b.Destination;
	Surname = b.Surname;
	NumPieces = b.NumPieces;
	Weight = b.Weight;
	return (*this);
}

//ввод с консоли
baggage InputBaggage()
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

//перевод структуры в строку
string ToString(baggage b, int i)
{
	string result = "Запись № " + to_string(i) + "\n" + "Номер рейса: " + to_string(b.FlightNum) + "\n" + "Дата вылета: " + b.DepDate.ToString() + "\n" + "Пункт назначения: " + b.Destination + "\n" + "Фамилия пассажира: " + b.Surname + "\n" + "Количество мест багажа: " + to_string(b.NumPieces) + "\n" + "Вес багажа: " + to_string(b.Weight) + "\n";
	return result;
}

//считываение baggage из строки
baggage ReadFromString(ifstream& input)
{
	baggage result;
	string s;
	try
	{
		if (!input.eof())
		{
			getline(input, s);
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Номер рейса: ";
			result.FlightNum = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Дата вылета: ";
			result.DepDate = result.DepDate.FromString(s.substr(wrd.length(), s.length()));
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Пункт назначения: ";
			result.Destination = s.substr(wrd.length(), s.length());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Фамилия пассажира: ";
			result.Surname = s.substr(wrd.length(), s.length());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Количество мест багажа: ";
			result.NumPieces = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Вес багажа: ";
			result.Weight = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
	}
	catch (...)
	{
		cout << "Ошибка записи в файл!" << endl;
	}
	return result;
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

//сравнение структур в зависимости от выбранного поля для сортировки
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
}