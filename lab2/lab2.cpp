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

//����
int Menu()
{
	cout << endl;
	cout << "�������� ����������� ��������" << endl;
	cout << "1 - �������� �������" << endl;
	cout << "2 - ������� �������" << endl;
	cout << "3 - �������� �������" << endl;
	cout << "4 - ����� �� �����" << endl;
	cout << "5 - ��������� � ����" << endl;
	cout << "6 - �������� �����" << endl;
	cout << "7 - �������� �����" << endl;
	cout << "8 - ������� ������������ �� �����" << endl;
	cout << "9 - ��������� ������������ � ����" << endl;
	cout << "0 - �����" << endl;
	int num = InputNumber(0, 9, "��� �����: ");
	cout << endl;
	return num;
}

bool ChangeInputData()
{
	Task<baggage> task;
	bool change = true;
	cout << "�������� ���� �� ������� ����: " << endl;
	cout << "1 - ���������� ���������� � �������" << endl;
	cout << "2 - ���������� ���������� �� ����� " << endl;
	cout << "0 - �����" << endl;
	int changemenu = InputNumber(0, 2, "��� �����: ");
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
				cout << "����� - " << task.size() << endl;
				task.Remove(InputNumber(0, task.size(), "\n������� ����� ���������� ��-�� (0 - ���� ���������� �������):"));
				break;

			case 3:
				task.OutputScreen(task.vect, OutputBaggage);
				cout << "����� - " << task.size() << endl;
				numb = InputNumber(0, task.size(), "\n������� ����� ����������� ��-�� (0 - ���� ���������� ��������): ");
				if (numb != 0)
				{
					task.vect[numb - 1] = elem.ChangeBaggage(task.vect[numb - 1]);
					cout << "������ ��������!" << endl;
				}
				break;

			case 4:
				task.OutputScreen(task.vect, OutputBaggage);
				break;

			case 5:
				task.OutputFile(task.vect, ToString);
				break;

			case 6:
				numb = InputNumber(1, 4, "�������� ��� ������:\n 1 - �� ������ �����\n 2 - �� ������ ����������\n 3 - �� ���� ������\n 4 - �� ���� � ������� ������ \n��� �����: ");
				search_elem = InputForSearchInfo(numb);
				subset = task.LinearySearch(search_elem, SearchInfo, numb);
				if (subset.size() != 0)
					task.OutputScreen(subset, OutputBaggage);
				else
					cout << "�������� �� �������" << endl;
				break;

			case 7:
				numb = InputNumber(1, 3, "�������� ��� ������:\n 1 - �� ������ �����\n 2 - �� ������ ����������\n 3 - �� ���� ������\n 4 - �� ���� � ������� ������ \n��� �����: ");
				search_elem = InputForSearchInfo(numb);
				subset = task.BinarySearch(numb, search_elem, �omparison, SearchInfo);
				if (subset.size() != 0)
					task.OutputScreen(subset, OutputBaggage);
				else
					cout << "�������� �� �������" << endl;
				break;

			case 8:
				task.OutputScreen(subset, OutputBaggage);
				break;

			case 9:
				task.OutputFile(subset, ToString);
				break;


			default:
				cout << "����� " << endl; exit(0);
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