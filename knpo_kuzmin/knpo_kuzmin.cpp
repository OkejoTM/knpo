#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;


vector<string> readDataFromFile(vector<vector<int>>& roads, vector<int>& costs)
{
	//открытие файла
	ifstream file;
	file.open("input.csv");

	//считывание первой строки файла
	string line;
	getline(file, line);
	stringstream ss(line);

	string label;
	vector<string> citiesLabes;
	

	//заполнить вектор названиями городов
	while (getline(ss, label, ';')) {
		if (label != "") {
			citiesLabes.push_back(label);
		}
	}
	roads.resize(citiesLabes.size(), vector<int>(citiesLabes.size(), 0));
	costs.resize(citiesLabes.size(), 0);

	getline(file, line);
	stringstream ssCost(line);		
	int costValueCol = 0;
	string costVal;

	// Считывание стоимости дорог
	while (getline(ssCost, costVal, ';')) {
		if (costVal != "") {
			costs[costValueCol] = stoi(costVal);
		}
		costValueCol++;
	}

	getline(file, line); // Считать пустую строку
	getline(file, line); // Считать названия город

	//заполнение матрицы смежности из файла
	int row = 0;
	while (getline(file, line)) {
		stringstream ss(line);
		string value;
		int col = 0;
		while (getline(ss, value, ';')) {
			if (value != "" && col > 0) {
				roads[row][col - 1] = stoi(value);
			}
			col++;
		}
		row++;
	}

	file.close();

	return citiesLabes;
}

int main() {
	
	vector<vector<int>> matrixRoads;
	vector<int> costs;
	auto labels = readDataFromFile(matrixRoads, costs);
	
	for (int i = 0; i < costs.size(); i++) {
		cout << costs[i] << " ";
	}
	cout << endl;

	/*for (int i = 0; i < matrixRoads.size(); i++) {
		for (int j = 0; j < matrixRoads.size(); j++) {

		}
	}*/

	/*const int N = 5;

	int costs[2][N];

	cout << "Enter costs of each city liters of fuel:\n";
	int i = 0;

	for (int j = 0; j < N; j++) 
	{
		costs[i][j] = j + 1;
		cout << j+1 << "city:";
		cin >> costs[i+1][j];
	}

	int roads[N][N];

	cout << "Enter roads:\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> roads[i][j];
		}
	}

	int roadsWithCosts[N][N];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			roadsWithCosts[i][j] = roads[i][j] * costs[1][i];
			roadsWithCosts[j][i] = roads[j][i] * costs[1][j];
		}
	}









	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << roadsWithCosts[i][j] << " ";
		}
		cout << endl;
	}

	cout << "costs: \n";
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < N; j++) {
			cout << costs[i][j] << " ";
		}
		cout << endl;
	}*/


	return 0;
}