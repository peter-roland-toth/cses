#include <iostream>

using namespace std;

int main() {
	long l, q;
	cin >> l >> q;
	long a[l+1];
	a[0] = 0;
	long sum = 0;
	for (long i = 0; i < l; i++) {
		long nr;
		cin >> nr;
		sum += nr;
		a[i+1] = sum;
	}

	for (long i = 0; i < q; i++) {
		long left, right;
		cin >> left >> right;
		cout << a[right] - a[left-1] << endl;
	}
}
