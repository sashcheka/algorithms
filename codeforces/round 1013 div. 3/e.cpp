#include <bits/stdc++.h>

using namespace std;

vector<int> generate_primes(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    vector<int> primes;

    for (long long i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (long long j = i * i; j <= n; j += i) is_prime[j] = false;
        }
    }

    return primes;
}

void solve(const vector<int>& primes) {
    int n;
    cin >> n;

    long long count = 0;
    for (int p : primes) {
        if (p > n) break;

        count += (long long)(n / p);
    }

    cout << count << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    const int MAX_N = 10000000;
    vector<int> primes = generate_primes(MAX_N);
    
    int t;
    cin >> t;
    while (t--) solve(primes);
    
    return 0;
}