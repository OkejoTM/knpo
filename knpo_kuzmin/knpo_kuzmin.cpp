#include <iostream>





using namespace std;

int main() {
	const int N = 5;

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
	}


	return 0;
}