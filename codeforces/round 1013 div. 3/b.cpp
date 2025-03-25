#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.rbegin(), a.rend());
    
    int teams = 0;
    int i = 0;
    long long curr_team_size = 0;
    while(i < n) {
        curr_team_size++;
        if((long long)a[i] * curr_team_size >= x) {
            teams++;
            curr_team_size = 0;
        }
        i++;
    }
    
    cout << teams << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}