#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> t(n);
	for (int& x : t) cin >> x;

	int m;
	cin >> m;
	vector<int> p(m);
	for (int& x : p) cin >> x;

	int i = 0;
	int j = 0;
	int best_t = t[i];
	int best_p = p[j];
	while (i < n && j < m) {
		if (t[i] == p[j]) {
			cout << t[i] << " " << p[j];
			return 0;
		} 
		if (abs(t[i] - p[j]) < abs(best_t - best_p)) {
			best_t = t[i];
			best_p = p[j];
		}
		if (t[i] < p[j]) {
			++i;
		} else {
			++j;
		}
	}

	cout << best_t << " " << best_p;

	return 0;
}