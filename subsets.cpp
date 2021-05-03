#include<bits/stdc++.h>
using namespace std;

// watch video for hint: https://youtu.be/rYkfBRtMJr8

vector<vector<int>> ans;

void subsets(int arr[], vector<int> v, int i, int n) {
	if (i == n) {
		ans.push_back(v);
		return;
	}

	// decided not to pick
	subsets(arr, v, i + 1, n);

	// decided to pick
	v.push_back(arr[i]);
	subsets(arr, v, i + 1, n);
	return;
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

	vector<int> v;
	subsets(arr, v, 0, n);

	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
}






