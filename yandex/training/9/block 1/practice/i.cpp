#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <utility>

using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	vector<pair<int, int>> cands;
	if (a > 0 && c > 0) {
		cands.push_back({b + 1, d + 1});
	}
	if (b > 0 && d > 0) {
		cands.push_back({a + 1, c + 1});
	}
	if (a > 0 && b > 0) {
		cands.push_back({max(a, b) + 1, 1});
	}
	if (c > 0 && d > 0) {
		cands.push_back({1, max(c, d) + 1});
	}

	auto [x, y] = *min_element(cands.begin(), cands.end(), [](const auto& p1, const auto& p2){
		return p1.first + p1.second < p2.first + p2.second;
	});
	cout << x << " " << y;

	return 0;
}