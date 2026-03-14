#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	if (c < 0) {
		cout << "NO SOLUTION";
		return 0;
	}

	if (a == 0) {
		cout << "MANY SOLUTIONS";
		return 0;
	}

	if (((c * c - b) / a) * a != (c * c - b)) {
		cout << "NO SOLUTION";
		return 0;
	}

	cout << (c * c - b) / a;

	return 0;
}
