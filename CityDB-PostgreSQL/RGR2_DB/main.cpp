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
	cout << "3. Ïîêàçàòü òàáëèöó óëèö" << endl;
	cout << "4. Ïîêàçàòü òàáëèöó çäàíèé" << endl;
	cout << "5. Ïîêàçàòü òàáëèöó äîñòîïðèìå÷àòåëüíîñòåé" << endl;
	cout << "Äðóãîé íîìåð - âåðíóòüñÿ íàçàä" << endl;
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
	cout << "1. Èçìåíèòü äàííûå î ãîðîäå" << endl;
	cout << "2. Èçìåíèòü äàííûå î ðàéîíå" << endl;
	cout << "3. Èçìåíèòü äàííûå îá óëèöå" << endl;
	cout << "4. Èçìåíèòü äàííûå î çäàíèè" << endl;
	cout << "5. Èçìåíèòü äàííûå î äîñòîïðèìå÷àòåëüíîñòè" << endl;
	cout << "Äðóãîé íîìåð - âåðíóòüñÿ íàçàä" << endl;
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
	cout << "1. Äîáàâèòü ãîðîä" << endl;
	cout << "2. Äîáàâèòü ðàéîí" << endl;
	cout << "3. Äîáàâèòü óëèöó" << endl;
	cout << "4. Äîáàâèòü çäàíèå" << endl;
	cout << "5. Äîáàâèòü äîñòîïðèìå÷àòåëüíîñòü" << endl;
	cout << "Äðóãîé íîìåð - âåðíóòüñÿ íàçàä" << endl;
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
	cout << "1. Óäàëèòü ãîðîä" << endl;
	cout << "2. Óäàëèòü ðàéîí" << endl;
	cout << "3. Óäàëèòü óëèöó" << endl;
	cout << "4. Óäàëèòü çäàíèå" << endl;
	cout << "5. Óäàëèòü äîñòîïðèìå÷àòåëüíîñòü" << endl;
	cout << "Äðóãîé íîìåð - âåðíóòüñÿ íàçàä" << endl;
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
	cout << "1. Ïîñìîòðåòü äàííûå î ãîðîäå ñ êîíêðåòíûì êîäîì ðåãèîíà" << endl; //
	cout << "2. Ïîñìîòðåòü ñïèñîê ðàéîíîâ, íàõîäÿùèõñÿ â îïðåäåë¸ííîì îêðóãå" << endl;
	cout << "3. Âûâåñòè ñïèñîê óëèö, êîòîðûå íàõîäÿòñÿ â îïðåäåë¸ííîì ãîðîäå" << endl;
	cout << "4. Âûâåñòè ñïèñîê çäàíèé äëÿ êîíêðåòíûõ ãîðîäà è óëèöû" << endl;
	cout << "5. Ïîñìîòðåòü äàííûå î êîíêðåòíîé äîñòîïðèìå÷àòåëüíîñòè" << endl;
	cout << "Äðóãîé íîìåð - âåðíóòüñÿ íàçàä" << endl;
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
		cout << "1. Ïîêàçàòü äàííûå òàáëèö" << endl;
		cout << "2. Èçìåíèòü äàííûå â òàáëèöå" << endl;
		cout << "3. Äîáàâèòü ñòðîêó â òàáëèöó" << endl;
		cout << "4. Óäàëèòü ñòðîêó èç òàáëèöû" << endl;
		cout << "5. Ïîêàçàòü êîíêðåòíûå äàííûå èç òàáëèöû" << endl;
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
