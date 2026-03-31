#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_map<int, long long> dupka;
    dupka[0] = 1;
    long long ans = 0;
    int d = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') d++;
        else d--;
        ans += dupka[d];
        dupka[d]++;
    }
    cout << ans;
    return 0;
}