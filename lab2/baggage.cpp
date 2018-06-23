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
	cout << "����� ���� �� ������ ��������?" << endl;
	cout << "1 - ����� �����" << endl;
	cout << "2 - ���� ������" << endl;
	cout << "3 - ����� ����������" << endl;
	cout << "4 - ������� ���������" << endl;
	cout << "5 - ���������� ���� ������" << endl;
	cout << "6 - ��� ������" << endl;
	cout << "0 - ������" << endl;
	int num = InputNumber(0, 6, "");
	switch (num)
	{
	case 1: 
		res.FlightNum = InputNumber(0, 100, "������� ����� �����: ");
		break;
	case 2:
		res.DepDate.InputDate();
		break;
	case 3:
		res.Destination = InputInformation("������� ����� ����������: ");
		break;
	case 4:
		res.Surname = InputInformation("������� ������� ���������: ");
		break;
	case 5:
		res.NumPieces = InputNumber(0, 200, "������� ���������� ���� ��� ������: ");
		break;
	case 6:
		res.Weight = InputNumber(0, 100, "������� ��� ������: ");
		break;
	default:
		cout << "����� " << endl; exit(0);
		break;
	}
	return res;
}

// ������������� �������� ���������
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

//���� � �������
baggage InputBaggage()
{
	baggage b;
	b.FlightNum = InputNumber(0, 100, "������� ����� �����: ");
	b.DepDate.InputDate();
	b.Destination = InputInformation("������� ����� ����������: ");
	b.Surname = InputInformation("������� ������� ���������: ");
	b.NumPieces = InputNumber(0, 200, "������� ���������� ���� ��� ������: ");
	b.Weight = InputNumber(0, 100, "������� ��� ������: ");
	return b;
}

//����� �� �������
void OutputBaggage(baggage b)
{
	cout << "����� �����: " << b.FlightNum << endl;
	cout << "���� ������: " << b.DepDate.ToString() << endl;
	cout << "����� ����������: " << b.Destination << endl;
	cout << "������� ���������: " << b.Surname << endl;
	cout << "���������� ���� ��� ������: " << b.NumPieces << endl;
	cout << "��� ������: " << b.Weight << endl;
}

//������� ��������� � ������
string ToString(baggage b, int i)
{
	string result = "������ � " + to_string(i) + "\n" + "����� �����: " + to_string(b.FlightNum) + "\n" + "���� ������: " + b.DepDate.ToString() + "\n" + "����� ����������: " + b.Destination + "\n" + "������� ���������: " + b.Surname + "\n" + "���������� ���� ������: " + to_string(b.NumPieces) + "\n" + "��� ������: " + to_string(b.Weight) + "\n";
	return result;
}

//����������� baggage �� ������
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
			string wrd = "����� �����: ";
			result.FlightNum = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "���� ������: ";
			result.DepDate = result.DepDate.FromString(s.substr(wrd.length(), s.length()));
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "����� ����������: ";
			result.Destination = s.substr(wrd.length(), s.length());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "������� ���������: ";
			result.Surname = s.substr(wrd.length(), s.length());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "���������� ���� ������: ";
			result.NumPieces = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "��� ������: ";
			result.Weight = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
	}
	catch (...)
	{
		cout << "������ ������ � ����!" << endl;
	}
	return result;
}

//����� �� ���������
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

//���� ���������� ��������
baggage InputForSearchInfo(int type_search)
{
	baggage bag;
	switch (type_search)
	{
	case 1:
		bag.FlightNum = InputNumber(0, 100, "������� ����� �����: ");
		return bag;
	case 2:
		bag.DepDate.InputDate();
		return bag;
	case 3:
		bag.Destination = InputInformation("������� ����� ����������: ");
		return bag;
	case 4:
		bag.Weight = InputNumber(0, 100, "������� ��� ������: ");
	default:
		return bag;
	}
}

//��������� �������� � ����������� �� ���������� ���� ��� ����������
int �omparison(baggage b1, baggage b2, int type_search)
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