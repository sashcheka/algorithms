#include<bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;

    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    unordered_set<char> setik(alphabet.begin(), alphabet.end());

    for (const char& ch : s) {
        setik.erase(ch);
    }

    cout << *setik.begin();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}