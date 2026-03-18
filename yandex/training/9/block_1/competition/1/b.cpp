#include<bits/stdc++.h>

using namespace std;
    
const int POSITION = 0;
const int VALUE = 1;
const int PARITY = 2;

int main() {
    int n, m;
    cin >> n >> m;

    vector<tuple<int, long long, int>> add_v(n), sub_v(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        long long x;
        cin >> l >> r >> x;
        int p = l % 2;
        add_v[i] = {l, x, p};
        sub_v[i] = {r + 1, x, p};
    }

    sort(add_v.begin(), add_v.end());
    sort(sub_v.begin(), sub_v.end());

    long long even_sum = 0;
    long long odd_sum = 0;
    int add_idx = 0;
    int sub_idx = 0;
    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;

        while (add_idx < n && get<POSITION>(add_v[add_idx]) <= q) {
            long long x = get<VALUE>(add_v[add_idx]);
            int p = get<PARITY>(add_v[add_idx]);
            if (p == 0) {
                even_sum += x;
            } else {
                odd_sum += x;
            }
            add_idx++;
        }

        while (sub_idx < n && get<POSITION>(sub_v[sub_idx]) <= q) {
            long long x = get<VALUE>(sub_v[sub_idx]);
            int p = get<PARITY>(sub_v[sub_idx]);
            if (p == 0) {
                even_sum -= x;
            } else {
                odd_sum -= x;
            }
            sub_idx++;
        }

        if (q % 2 == 0) {
            cout << even_sum - odd_sum << "\n";
        } else {
            cout << odd_sum - even_sum << "\n";
        }
    }

    return 0;
}