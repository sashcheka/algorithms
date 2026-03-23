#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	const int HOME = 1;
	const int SHOP = 2;
	int last_shop = -1;
	int worst = 0;

	stack<int> st;
	for (int idx = 0; idx != 10; ++idx) {
		int point;
		cin >> point;
		if (point == HOME) {
			st.push(idx);
		} else if (point == SHOP) {
			if (last_shop == -1) {
				while (!st.empty()) {
					int top = st.top();
					st.pop();
					int cand = idx - top;
					worst = max(worst, cand);
				}
			} else {
				while (!st.empty()) {
					int top = st.top();
					st.pop();
					int cand = min(top - last_shop, idx - top);
					worst = max(worst, cand);
				}
			}
			last_shop = idx;
		}
	}

	while (!st.empty()) {
		int top = st.top();
		st.pop();
		int cand = top - last_shop;
		worst = max(worst, cand);
	}

	cout << worst;
	return 0;
}
