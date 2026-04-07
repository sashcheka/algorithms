#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

int main() {
	int n;
	cin >> n;
	string w, s;
	cin >> w >> s;

	stack<char> st;
	unordered_map<char, char> closing = {
		{')', '('},
		{']', '['},
	};
	for (char ch : s) {
		if (closing.contains(ch) && !st.empty() && st.top() == closing[ch]) {
			st.pop();
		} else {
			st.push(ch);
		}
	}

	int to_add = n - (int)s.size();
	string rem_s = "";
	for (int added = 0; added < to_add; added++) {
		for (char b : w) {
			if (closing.contains(b) && !st.empty() && st.top() == closing[b]) {
				rem_s += b;
				st.pop();
				break;
			} else if (!closing.contains(b) && st.size() + added + 1 <= to_add) {
				st.push(b);
				rem_s += b;
				break;
			}
		}
	}

	cout << s + rem_s;
	return 0;
}
