#include<bits/stdc++.h>
using namespace std;

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


int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif

	// cout << setBit(5, 1) << "\n";
	// cout << clearBit(5, 2) << "\n";
	cout << updateBit(5, 1, 1) << "\n";

	return 0;
}






