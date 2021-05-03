#include<bits/stdc++.h>
using namespace std;

bool isSafe(int** arr, int x, int y, int n) {
	for (int row = 1; row <= x; row++) {
		if (arr[row][y] == 1) {
			return false;
		}
	}

	int row = x;
	int col = y;
	while (row >= 1 && col >= 1) {
		if (arr[row][col] == 1) {
			return false;
		}
		row--;
		col--;
	}

	row = x;
	col = y;
	while (row >= 1 && col <= n) {
		if (arr[row][col] == 1) {
			return false;
		}
		row--;
		col++;
	}

	return true;
}

bool Nqueen(int** arr, int n, int x) {
	if (x >= n) {
		return true;
	}
	for (int i = 1; i <= n; i++) {
		if (isSafe(arr, x, i, n)) {
			arr[x][i] = 1;
			if (Nqueen(arr, n, x + 1)) {
				return true;
			}
			arr[x][i] = 0;
		}
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	int** arr = new int*[n + 1];
	for (int i = 1; i <= n; i++) {
		arr[i] = new int[n + 1];
		for (int j = 1; j <= n; j++) {
			arr[i][j] = 0;
		}
	}

	if (Nqueen(arr, n + 1, 1)) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
	}
	else {
		cout << "Can't be placed " << "\n";
	}







	return 0;
}






