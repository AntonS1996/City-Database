#pragma once
#include <Windows.h>
#include "connection.c"
#include "CityActions.c"
#include "DistrictActions.c"
#include "StreetActions.c"
#include "BuildingActions.c"
#include "LandmarkActions.c"
#include <string>
#include <iostream>
#include "stdio.h"
#include <iostream>
#include "conio.h"

using namespace std;

void menu();

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	connectToDB();
	menu();
	disconnectFromDB();

	return 0;
}

void selectMenu() {
	int menuPoint;
	cout << "1. �������� ������� �������" << endl;
	cout << "2. �������� ������� �������" << endl;
	cout << "3. �������� ������� ����" << endl;
	cout << "4. �������� ������� ������" << endl;
	cout << "5. �������� ������� ����������������������" << endl;
	cout << "������ ����� - ��������� �����" << endl;
	cin >> menuPoint;
	switch (menuPoint)
	{
	case 1:
		ReadCityTable();
		break;
	case 2:
		ReadDistrictTable();
		break;
	case 3:
		ReadStreetTable();
		break;
	case 4:
		ReadBuildingTable();
		break;
	case 5:
		ReadLandmarkTable();
		break;
	default: break;
	}
}

void updateMenu() {
	int menuPoint;
	cout << "1. �������� ������ � ������" << endl;
	cout << "2. �������� ������ � ������" << endl;
	cout << "3. �������� ������ �� �����" << endl;
	cout << "4. �������� ������ � ������" << endl;
	cout << "5. �������� ������ � ���������������������" << endl;
	cout << "������ ����� - ��������� �����" << endl;
	cin >> menuPoint;
	switch (menuPoint)
	{
	case 1:
		UpdateCityTable();
		break;
	case 2:
		UpdateDistrictTable();
		break;
	case 3:
		UpdateStreetTable();
		break;
	case 4:
		UpdateBuildingTable();
		break;
	case 5:
		UpdateLandmarkTable();
		break;
	default: break;
	}
}

void insertMenu() {
	int menuPoint;
	cout << "1. �������� �����" << endl;
	cout << "2. �������� �����" << endl;
	cout << "3. �������� �����" << endl;
	cout << "4. �������� ������" << endl;
	cout << "5. �������� ���������������������" << endl;
	cout << "������ ����� - ��������� �����" << endl;
	cin >> menuPoint;
	switch (menuPoint)
	{
	case 1:
		InsertCityTable();
		break;
	case 2:
		InsertDistrictTable();
		break;
	case 3:
		InsertStreetTable();
		break;
	case 4:
		InsertBuildingTable();
		break;
	case 5:
		InsertLandmarkTable();
		break;
	default: break;
	}
}

void deleteMenu() {
	int menuPoint;
	cout << "1. ������� �����" << endl;
	cout << "2. ������� �����" << endl;
	cout << "3. ������� �����" << endl;
	cout << "4. ������� ������" << endl;
	cout << "5. ������� ���������������������" << endl;
	cout << "������ ����� - ��������� �����" << endl;
	cin >> menuPoint;
	switch (menuPoint)
	{
	case 1:
		DeleteCityTable();
		break;
	case 2:
		DeleteDistrictTable();
		break;
	case 3:
		DeleteStreetTable();
		break;
	case 4:
		DeleteBuildingTable();
		break;
	case 5:
		DeleteLandmarkTable();
		break;
	default: break;
	}
}

void selectSmthMenu() {
	int menuPoint;
	cout << "1. ���������� ������ � ������ � ���������� ����� �������" << endl; //
	cout << "2. ���������� ������ �������, ����������� � ����������� ������" << endl;
	cout << "3. ������� ������ ����, ������� ��������� � ����������� ������" << endl;
	cout << "4. ������� ������ ������ ��� ���������� ������ � �����" << endl;
	cout << "5. ���������� ������ � ���������� ���������������������" << endl;
	cout << "������ ����� - ��������� �����" << endl;
	cin >> menuPoint;
	switch (menuPoint)
	{
	case 1:
		SelectCityTable();
		break;
	case 2:
		SelectDistrictTable();
		break;
	case 3:
		SelectStreetTable();
		break;
	case 4:
		SelectBuildingTable();
		break;
	case 5:
		SelectLandmarkTable();
		break;
	default: break;
	}
}

void menu() {
	int menuPoint;
	while (1) {
		cout << "1. �������� ������ ������" << endl;
		cout << "2. �������� ������ � �������" << endl;
		cout << "3. �������� ������ � �������" << endl;
		cout << "4. ������� ������ �� �������" << endl;
		cout << "5. �������� ���������� ������ �� �������" << endl;
		cin >> menuPoint;
		switch (menuPoint)
		{
		case 1:
			selectMenu();
			break;
		case 2:
			updateMenu();
			break;
		case 3:
			insertMenu();
			break;
		case 4:
			deleteMenu();
			break;
		case 5:
			selectSmthMenu();
			break;
		default: return;
		}
		continue;
	}
}
