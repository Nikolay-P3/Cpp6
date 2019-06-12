#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct CarShop {
	string model;
	string manufacturer;
	string type;
	int year;
	int cost;
};

void Init(CarShop *arr, const int n) {
	for (int i = 0; i < n; i++)
	{
		cout << "Input model: ";
		cin >> arr[i].model;
		cout << "Input manufacturer: ";
		cin >> arr[i].manufacturer;
		cout << "Input type: ";
		cin >> arr[i].type;
		cout << "Input year: ";
		cin >> arr[i].year;
		cout << "Input cost: ";
		cin >> arr[i].cost; cin.ignore();
		
	}
}

void Print(CarShop *arr, const int n)
{
	cout << "\nList: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i].model << " | " << arr[i].manufacturer << " | " << arr[i].type << " | " << arr[i].year << " | " << arr[i].cost << " | " << endl;
	}
}

void Write(CarShop *arr, const int n)
{
	ofstream file("file.txt", ios::binary | ios::in);
	for (int i = 0; i < n; i++)
	{

		file.write((char*)&arr[i].model, sizeof arr[i].model);
		file.write((char*)&arr[i].manufacturer, sizeof arr[i].manufacturer);
		file.write((char*)&arr[i].type, sizeof arr[i].type);
		file.write((char*)&arr[i].year, sizeof arr[i].year);
		file.write((char*)&arr[i].cost, sizeof arr[i].cost);
		

	}
	file.close();
}

void Select(CarShop *arr, const int n)
{
	cout << "Your Select";
	for (int i = 0; i < n; i++) {
		if (arr[i].year <= 2014 && (arr[i].manufacturer != "China" || arr[i].manufacturer != "china"))
			cout << arr[i].model << " | " << arr[i].manufacturer << " | " << arr[i].type << " | " << arr[i].year << " | " << arr[i].cost << " | " << endl;
	}
}

int main()
{
	int n;
	cout << "How many: ";
	cin >> n;
	CarShop *arr = new CarShop[n];
	Init(arr, n);
	Print(arr, n);
	Write(arr, n);
	Select(arr, n);
	delete[] arr;
	return 0;
}
