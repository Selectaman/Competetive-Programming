#include<bits/stdc++.h>
using namespace std;

// watch youtube videos of bit Manipulation of Apni Kaksha


int getBit(int n, int pos) {
	return ((n & (1 << pos)) != 0);
}

int setBit(int n, int pos) {
	return ((n | (1 << pos)));
}

int clearBit(int n, int pos) {
	return (n &  (~(1 << pos)));
}

int updateBit(int n, int pos, int i) {
	// update = clear + set;
	int mask = ~(1 << pos);
	n = (n & mask);
	return (n | (i << pos));
}

bool isPowerof2(int n) {
	return n && !(n & (n - 1));
}

int count1(int n) { // count number of 1 present in the binary of a Number
	int count = 0;
	while (n != 0) {
		n = (n & (n - 1));
		count++;
	}
	return count;
}


// No of Subsets of a set
void subsets(char arr[], int n) {
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if (getBit(i, j) == 1) {
				cout << arr[j] << " ";
			}
		}
		cout << "\n";
	}
}

// Find one unique element in the given array given that only one unique element is present
int unique1(int arr[], int n) {
	int xorsum = 0;
	for (int i = 0; i < n; i++) {
		xorsum = xorsum ^ arr[i];
	}
	return xorsum;
}

// WAP to find 2 numbers in an array where all numbers except 2 are present twice.
void unique2(int arr[], int n) {
	int xorsum = 0;
	for (int i = 0; i < n; i++) {
		xorsum = xorsum ^ arr[i];
	}
	int xorsum1 = xorsum;
	int pos;
	for (int i = 0; i < n; i++) {
		if (getBit(xorsum, i) == 1) {
			pos = i;
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		if (getBit(arr[i], pos) == 1) {
			xorsum = xorsum ^ arr[i];
		}
	}
	cout << xorsum << "\n";

	cout << (xorsum ^ xorsum1) << "\n";
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	unique2(arr, n);

	return 0;
}






