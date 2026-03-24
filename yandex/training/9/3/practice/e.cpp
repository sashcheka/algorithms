#include<bits/stdc++.h>

using namespace std;

int main() {
    const int MOD = 1e9 + 7;

    int n;
    cin >> n;
    long long s1 = 0;
    long long s2 = 0;
    long long s3 = 0;
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        s3 = (s3 + s2 * a % MOD) % MOD;
        s2 = (s2 + s1 * a % MOD) % MOD;
        s1 = (s1 + a) % MOD;
    }

    cout << s3;
    return 0;
}