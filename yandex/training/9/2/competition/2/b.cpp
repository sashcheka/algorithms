#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();

    int max_freq = 0;
    unordered_set<char> chs;
    chs.reserve(26);
    vector<int> freq(26);
    vector<vector<int>> pos(26);
    for (int i = 0; i < n; i++) {
        char ch = s[i];
        chs.insert(ch);
        ++freq[ch - 'a'];
        max_freq = max(max_freq, freq[ch - 'a']);
        pos[ch - 'a'].push_back(i);
    }

    int best = 1;
    for (char ch : chs) {
        if (freq[ch - 'a'] != max_freq) continue;

        const vector<int>& p = pos[ch - 'a'];
        for (int cand = 1; cand <= 26; cand++) {
            bool valid = true;
            for (const int& i : p) {
                if (i + cand >= n || s[p[0] + cand] != s[i + cand]) {
                    valid = false;
                    break;
                }
            }
            if (!valid) break;
            best = max(best, cand + 1);
        }
    }

    cout << best;
    return 0;
}