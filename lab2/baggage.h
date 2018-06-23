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
	int FlightNum; //����� �����
	MyDate DepDate; //���� ������
	string Destination; //���� ����������
	string Surname; //������� ���������
	int NumPieces; //���������� ���� ������
	int Weight; //��� ������

	//�����������
	baggage();

	//��������� ���������
	baggage ChangeBaggage(baggage &res);

	//������������� �������� ���������
	baggage& operator = (baggage b);
};

//���� � �������
baggage InputBaggage();

//����� �� �������
void OutputBaggage(baggage b);

//������� ��������� � ������
string ToString(baggage b, int i);

//���������� ��������� �� ������
baggage ReadFromString(ifstream& input);

//����� �� ���������� ��������
bool SearchInfo(baggage b1, baggage b2, int type_search);

//���� �������� ���������� � ����������� �� ���������� ����
baggage InputForSearchInfo(int type_search);

//��������� �������� � ����������� �� ���������� ���� ��� ����������
int �omparison(baggage b1, baggage b2, int type_search);



/*baggage InputBaggage()
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

//���������� ���� �� ������
MyDate DateFromString(string str)
{
	MyDate date;
	try 
	{
		istringstream s(str);
		string s1;
		if (getline(s, s1, ' '))
			date.day = atoi(s1.c_str()); //atoi - ����������� ������ � ����� �����
		if (getline(s, s1, ' '))
			date.month = atoi(s1.c_str());
		if (getline(s, s1, ' '))
			date.year = atoi(s1.c_str());
	}
	catch (...)
	{
		cout << "������ ������ � ����!" << endl;
	}
	return date;
}

//����������� baggage �� ������
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
			string wrd = "����� �����: ";
			bag.FlightNum = atoi(s.substr(wrd.length(), s.length()).c_str()); //substr - ���������� ��������� ���������� ��������� �� ������
		}
		//if (!str.eof())
			///////
	}
	catch (...)
	{
		cout << "������ ������ � ����!" << endl;
	}
	return bag;
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
}*/