#include <iostream>

using namespace std;

long find(long x, long y) {
	long r, c;

	long b = max(y, x);
		
	if (b % 2 == 0) {
		r = b * b;
	} else {
		r = (b-1) * (b-1) + 1;
	}

	if (b % 2 == 0) {
		c = (b-1) * (b-1) + 1;
	} else {
		c = b * b;
	}

	long result = 0;

	if (x == y) {
		result = (long)((r + c) / 2);
	} else if (x < y) {
		if (r < c) {
			result = r + x - 1;
		} else {
			result = r - x + 1;
		}
	} else {
		if (r < c) {
			result = c - y + 1;
		} else {
			result = c + y - 1;
		}
	}

	return result;
}

int main() {
	long n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		long y, x;
		cin >> y >> x;

		cout << find(x, y) << endl;
	}
}
