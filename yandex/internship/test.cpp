#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);
    unordered_map<int, int> count_a, count_b, count_c;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        count_a[a[i]] = 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        count_b[b[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        count_c[c[i]]++;
    }

    unordered_map<int, int> include_count;
    unordered_set<int> events_to_include;
    for (auto &entry : count_a) {
        int e = entry.first;
        int cnt = min({count_a[e], count_b[e], count_c[e]});
        if (cnt > 0) {
            include_count[e] = cnt;
            events_to_include.insert(e);
        }
    }

    unordered_map<int, int> used_a, used_b, used_c;
    int includedYears = 0;
    for (int i = 0; i < n; i++) {
        int event_a = a[i];
        int event_b = b[i];
        int event_c = c[i];
        if (events_to_include.count(event_a) && include_count[event_a] > used_a[event_a] &&
            events_to_include.count(event_b) && include_count[event_b] > used_b[event_b] &&
            events_to_include.count(event_c) && include_count[event_c] > used_c[event_c]) {
            used_a[event_a]++;
            used_b[event_b]++;
            used_c[event_c]++;
            includedYears++;
        }
    }

    int deletions = n - includedYears;
    cout << deletions;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
