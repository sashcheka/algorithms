#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int best = 0;
    int curr = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != 'a' && s[i] != 'h') {
            curr = 0;
        } else {
            if (i > 0 && (s[i - 1] == 'a' || s[i - 1] == 'h') && s[i - 1] != s[i]) {
                ++curr;
            } else {
                curr = 1;
            }
        }
        best = max(best, curr);
    }

    cout << best;
    return 0;
}