#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    long long sum_a = 0;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum_a += a[i];
    }

    long long sum_b = 0;
    vector<long long> b(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        sum_b += b[i];
    }

    if(sum_a < sum_b) {
        cout << "NO\n";
        return;
    }

    int deficit_idx = -1;
    for(int i = 0; i < n; i++) {
        if(a[i] < b[i]) {
            if (deficit_idx == -1) {
                deficit_idx = i;
            } else {
                cout << "NO\n";
                return;
            }
        }
    }

    if(deficit_idx == -1) {
        cout << "YES\n";
        return;
    }

    long long diff = b[deficit_idx] - a[deficit_idx];

    bool possible = true;
    for(int j = 0; j < n; j++) {
        if(j == deficit_idx) continue;
        if(a[j] < b[j] + diff) {
            possible = false;
            break;
        }
    }

    if(possible) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}
