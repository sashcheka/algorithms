#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAX_LIM = 1e14;
const ll MAX_PRIME = 1e7;

vector<ll> sieve(ll limit) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    vector<ll> primes;
    for (ll i = 2; i <= limit; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (ll j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

void solve() {
    ll l, r;
    cin >> l >> r;

    vector<ll> primes = sieve(sqrt(r));

    unordered_set<int> prime_divisor_counts = {2, 3, 5, 7, 11, 13, 17};

    int count = 0;

    for (ll p : primes) {
        ll current = p * p;
        int k = 2;
        while (current <= r) {
            if (current >= l) {
                if (prime_divisor_counts.count(k + 1)) {
                    count++;
                }
            }
            if (current > r / p) break;
            current *= p;
            k++;
        }
    }

    cout << count << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
