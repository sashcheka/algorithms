#include<bits/stdc++.h>
using namespace std;

bool is_valid(long long& sum, long long& mx) {
    return sum > 2 * mx;
}

void solve() {
    int n;
    cin >> n;
    unordered_map<long long, int> dupa;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dupa[a[i]]++;
    }

    long long pairs_perimeter = 0;
    long long max_pair_len = 0;
    int pairs_cnt = 0;
    vector<long long> odds;

    for (auto [len, cnt] : dupa) {
        int pairs = cnt / 2;
        if (pairs) {
            pairs_perimeter += 2LL * pairs * len;
            pairs_cnt += pairs;
            if (len > max_pair_len) max_pair_len = len;
        }
        if (cnt % 2) odds.push_back(len);
    }

    sort(odds.rbegin(), odds.rend());

    long long ans = 0;

    // only pairs
    if (pairs_cnt >= 2 && is_valid(pairs_perimeter, max_pair_len)) {
        ans = max(ans, pairs_perimeter);
    }

    // pairs + 1 odd.
    if (pairs_cnt >= 1 && odds.size() >= 1) {
        for (long long& len : odds) {
            long long mx = max(max_pair_len, len);
            long long sum = pairs_perimeter + len;
            if (is_valid(sum, mx)) { 
                ans = max(ans, sum); 
                break;
            }
        }
    }

    if (pairs_cnt >= 1 && odds.size() >= 2) {
        for (int i = 0; i < odds.size() - 1; i++) {
            long long len_1 = odds[i];
            long long len_2 = odds[i + 1];
            long long mx = max(max_pair_len, len_1);
            long long sum = pairs_perimeter + len_1 + len_2;
            if (is_valid(sum, mx)) { 
                ans = max(ans, sum); 
                break; 
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}