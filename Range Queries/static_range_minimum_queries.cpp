#include <iostream>
#include <cmath>

using namespace std;

int main() {
	long n, q;
	cin >> n >> q;

	long log = (long)log2(n) + 1;
	long arr[n][log];
	for (int i = 0; i < n; i++) {
		long a;
		cin >> a;
		arr[i][0] = a;
	}
	for (int j = 1; j < log; j++) {
		for (int i = 0; i + (1<<j) - 1 < n; i++) {
			arr[i][j] = min(arr[i][j-1], arr[i+(1<<(j-1))][j-1]);
		}
	}

	for (int query = 0; query < q; query++) {
		long l, r;
		cin >> l >> r;
		long len = r - l + 1;
		long k = (long)log2(len);
		cout << min(arr[l-1][k], arr[r - (1<<k)][k]) << endl;
	}

}
