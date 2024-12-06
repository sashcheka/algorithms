#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    char oper;
    int x, k;
    vector<int> st(1e5);
    vector<long long> prefix(1e5, 0);
    int idx = 0;

    while (n--) {
        cin >> s;
        oper = s[0];

        if (oper == '+') {
            x = stoi(s.substr(1));
            st[idx] = x;
            prefix[idx + 1] = prefix[idx] + x;
            idx++;
        } else if (oper == '-') {
            cout << st[idx - 1] << '\n';
            idx--;
        } else if (oper == '?') {
            k = stoi(s.substr(1));
            cout << prefix[idx] - prefix[idx - k] << '\n';    
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
