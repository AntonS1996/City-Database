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
	cout << "1. Показать таблицу городов" << endl;
	cout << "2. Показать таблицу районов" << endl;
	cout << "3. Показать таблицу улиц" << endl;
	cout << "4. Показать таблицу зданий" << endl;
	cout << "5. Показать таблицу достопримечательностей" << endl;
	cout << "Другой номер - вернуться назад" << endl;
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
	cout << "1. Изменить данные о городе" << endl;
	cout << "2. Изменить данные о районе" << endl;
	cout << "3. Изменить данные об улице" << endl;
	cout << "4. Изменить данные о здании" << endl;
	cout << "5. Изменить данные о достопримечательности" << endl;
	cout << "Другой номер - вернуться назад" << endl;
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
	cout << "1. Добавить город" << endl;
	cout << "2. Добавить район" << endl;
	cout << "3. Добавить улицу" << endl;
	cout << "4. Добавить здание" << endl;
	cout << "5. Добавить достопримечательность" << endl;
	cout << "Другой номер - вернуться назад" << endl;
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
	cout << "1. Удалить город" << endl;
	cout << "2. Удалить район" << endl;
	cout << "3. Удалить улицу" << endl;
	cout << "4. Удалить здание" << endl;
	cout << "5. Удалить достопримечательность" << endl;
	cout << "Другой номер - вернуться назад" << endl;
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
	cout << "1. Посмотреть данные о городе с конкретным кодом региона" << endl; //
	cout << "2. Посмотреть список районов, находящихся в определённом округе" << endl;
	cout << "3. Вывести список улиц, которые находятся в определённом городе" << endl;
	cout << "4. Вывести список зданий для конкретных города и улицы" << endl;
	cout << "5. Посмотреть данные о конкретной достопримечательности" << endl;
	cout << "Другой номер - вернуться назад" << endl;
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
		cout << "1. Показать данные таблиц" << endl;
		cout << "2. Изменить данные в таблице" << endl;
		cout << "3. Добавить строку в таблицу" << endl;
		cout << "4. Удалить строку из таблицы" << endl;
		cout << "5. Показать конкретные данные из таблицы" << endl;
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
