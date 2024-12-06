#include <bits/stdc++.h>

using namespace std;

int mod_pow(int base, int mod) {
    int res = 1;
    int exp = mod - 2;

    while (exp) {
        if (exp % 2)
            res = (res * base) % mod;

        base = (base * base) % mod;
        exp = exp / 2;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a = 7;
    int p = 11;

    cout << "without invert: " << (7 / 3) % 11 << '\n';
    int invert = mod_pow(3, p);
    cout << "invert:" << invert << '\n';

    cout << "with invert: " << (7 * invert) % 11;

    return 0;
}
