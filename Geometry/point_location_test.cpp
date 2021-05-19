#include <iostream>

using namespace std;

int main() {
	long n;
	cin >> n;

	for (long i = 0; i < n; i++) {
		long x1, y1, x2, y2, x3, y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		
		long det = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);

		if (det == 0) {
			cout << "TOUCH" << endl;
		} else if (det < 0) {
			cout << "RIGHT" << endl;
		} else {
			cout << "LEFT" << endl;
		}
	}
}