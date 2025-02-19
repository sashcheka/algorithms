#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string singular;
        cin >> singular;

        string plural = singular.substr(0, singular.size() - 2) + 'i';
        cout << plural << '\n';
    };
    
    return 0;
}
