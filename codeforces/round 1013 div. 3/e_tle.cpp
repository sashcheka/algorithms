#include<bits/stdc++.h>

using namespace std;

int bs(long long& num, vector<long long>& primes, int& n) {
    int l = 0;
    int r = primes.size() - 1;

    while (l <= r) {
        int m = l + (r - l) / 2;

        if (num * primes[m] <= n) l = m + 1;
        else r = m - 1;
    }

    return l;
}

void solve() {
    int n;
    cin >> n;

    vector<long long> primes;
    primes.push_back(2);
    
    for (long long num = 3; num <= n; num += 2) {
        bool is_prime = true;

        for (long long prime : primes) {
            if (prime * prime > num) break;

            if (num % prime == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) primes.push_back(num);
    }

    long long count = 0;
    for (long long num = 1; num <= n; num++) {
        count += bs(num, primes, n);
    }

    cout << count << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}
