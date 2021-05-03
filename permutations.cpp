#include<bits/stdc++.h>
using namespace std;

//watch youtube video: https://youtu.be/YK78FU5Ffjw

void permute(int n, stack<int> st, map<int, int> mpp) {
	if (st.size() == n) {
		for (int i = 0; i < n; i++) {
			cout << st.top() << " ";
			st.pop();
		}
		cout << "\n";
		return;
	}
	for (auto it : mpp) {
		int key = it.first;
		int value = it.second;
		if (value == 0) {
			st.push(key);
			mpp[key] = 1;
			permute(n, st, mpp);
			st.pop();
			mpp[key] = 0;
		}
	}

	return;

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	map<int, int> mpp;
	for (int i = 0; i < n; i++) {
		int key;
		cin >> key;
		mpp[key] = 0;
	}

	stack<int> st;
	permute(n, st, mpp);



	return 0;
}






