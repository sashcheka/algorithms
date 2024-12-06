#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, required;
    int k;
    cin >> s >> required >> k;
    
    unordered_map<char, int> freq_required;
    for (char c : required) {
        freq_required[c]++;
    }
    
    int n = s.size();
    int req_len = required.size();
    unordered_map<char, int> window_freq;
    int left = 0, valid = 0, best_start = -1, best_len = -1;
    
    for (int right = 0; right < n; ++right) {
        char c = s[right];
        
        if (freq_required.count(c)) {
            window_freq[c]++;
            if (window_freq[c] == freq_required[c]) {
                valid++;
            }
        }
        
        while (right - left + 1 > k) {
            char left_char = s[left];
            if (freq_required.count(left_char)) {
                if (window_freq[left_char] == freq_required[left_char]) {
                    valid--;
                }
                window_freq[left_char]--;
            }
            left++;
        }
        
        if (valid == req_len) {
            if (best_start == -1 || right - left + 1 > best_len || 
                (right - left + 1 == best_len && left > best_start)) {
                best_start = left;
                best_len = right - left + 1;
            }
        }
    }
    
    if (best_start == -1) {
        cout << -1 << '\n';
    } else {
        cout << s.substr(best_start, best_len) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
