#include <iostream>

using namespace std;

int main() {
	string n;
	long current_length, best;
	cin >> n;
	char current = n[0];
	current_length = 1;
	best = 1;
	for (long i = 1; i < n.size(); i++) {
		if (n[i] == current) {
			current_length += 1;
		} else {
			current_length = 1;
		}

		current = n[i];
		best = max(best, current_length);
	}

	cout << best << endl;
}
