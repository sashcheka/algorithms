#include <bits/stdc++.h>

using namespace std;

vector<long long> generate_primes(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    vector<long long> primes;

    for (long long i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (long long j = i * i; j <= n; j += i) is_prime[j] = false;
        }
    }

    return primes;
}

int bs(vector<long long>& primes, int n) {
    int l = 0;
    int r = primes.size() - 1;
    
    while (l <= r) {
        int m = l + (r - l) / 2;

        if (primes[m] <= n) l = m + 1;
        else r = m - 1;
    }

    return l;
}

void solve(vector<long long>& primes) {
    int n;
    cin >> n;
    
    long long count = 0;
    int pos = bs(primes, n);

    for (int i = 0; i < pos; i++) {
        long long p = primes[i];
        count += (long long)(n / p);
    }
    
    cout << count << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<long long> primes = generate_primes(1e7);
    
    int t;
    cin >> t;
    while (t--) solve(primes);
    
    return 0;
}