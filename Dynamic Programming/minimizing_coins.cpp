#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {
	long n, total;
	long min_coin = INT_MAX;
	cin >> n >> total;
	vector<long> v(total + 1, INT_MAX);
	v[0] = 0;
	vector<long> coins(0);
	
	for (int i = 0; i < n; i++) {
		long nr;
		cin >> nr;
		coins.push_back(nr);
		min_coin = min(min_coin, nr);
		if (nr < v.size()) {
			v[nr] = 1;
		}
	}

	for (int i = min_coin; i < total; i++) {
		for (int j = 0; j < coins.size(); j++) {
			if (v[i] != INT_MAX && i + coins[j] <= total) {
				v[i+coins[j]] = min(v[i+coins[j]], v[i] + 1);
			}
		}
	}

	if (v[total] == INT_MAX) {
		cout << -1 << endl;
	} else {
		cout << v[total] << endl;
	}	
}