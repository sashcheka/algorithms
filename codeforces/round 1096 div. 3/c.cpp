#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> six;
    six.reserve(n);
    vector<int> three;
    three.reserve(n);
    vector<int> two;
    two.reserve(n);
    vector<int> other;
    other.reserve(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a % 6 == 0) {
            six.push_back(a);
        } else if (a % 3 == 0) {
            three.push_back(a);
        } else if (a % 2 == 0) {
            two.push_back(a);
        } else {
            other.push_back(a);
        }
    }

    for (int a : six) cout << a << " ";
    for (int a : three) cout << a << " ";
    for (int a : other) cout << a << " ";
    for (int a : two) cout << a << " ";
    cout << "\n";

    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
