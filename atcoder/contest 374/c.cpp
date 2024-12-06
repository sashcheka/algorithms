#include<bits/stdc++.h>
 
using namespace std;
 
int solve(int n) {
    vector<int> k(n);
    for (int i = 0; i < n; i++)
        cin >> k[i];

    int min_max_size = INT_MAX;

    for (int mask = 0; mask < (1 << n); mask++) {
        int a = 0;
        int b = 0;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i))
                a += k[i];
            else
                b += k[i];
        }

        int max_size = max(a, b);
        min_max_size = min(min_max_size, max_size);
    }

    return min_max_size;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;

    int ans = solve(n);
    cout << ans;

    return 0;
}
