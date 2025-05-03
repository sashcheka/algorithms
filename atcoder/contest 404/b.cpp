#include<bits/stdc++.h>

using namespace std;

int count(int& n, vector<string>& s, vector<string>& t) {
    int result = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] != t[i][j]) result++;
        }
    }

    return result;
}


void rotate(int& n, vector<string>& s) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(s[i][j], s[j][i]);
        }
    }

    for (int i = 0; i < n; i++) {
        reverse(s[i].begin(), s[i].end());
    }
}

void solve() {
    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<string> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    int ans = INT_MAX;
    for (int i = 0; i < 4; i++) {
        int cand = count(n, s, t);
        ans = min(ans, cand + i);
        rotate(n, s);
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}