#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> min_rem(k, LLONG_MAX);
    min_rem[0] = 0;

    set<pair<long long, int>> setik;
    for (int rem = 0; rem < k; rem++) setik.insert({min_rem[rem], rem});

    long long best = 0;
    long long run = 0;
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        run += a;

        int rem = (run % k + k) % k;
        auto it = setik.begin();
        if (it != setik.end() && it->second == rem) ++it;
        if (it != setik.end() && it->first != LLONG_MAX) best = max(best, run - it->first);

        if (run < min_rem[rem]) {
            setik.erase({min_rem[rem], rem});
            min_rem[rem] = run;
            setik.insert({run, rem});
        }
    }

    cout << best;

    return 0;
}