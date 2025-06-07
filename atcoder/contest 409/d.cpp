#include <bits/stdc++.h>
using namespace std;

string rotate(string& s, int l, int n){
    int m = n - (l + 2), k = -1;
    for(int i = 0; i < m; i++)
        if(s[l + 2 + i] > s[l]){
            k = i;
            break;
        }
    if(k < 0) k = m;
    int r = l + (k + 1);
    string t = s.substr(0, l);
    t += s.substr(l + 1, r - l);
    t += s[l];
    t += s.substr(r + 1);
    return t;
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = s;
    for(int i = 0; i + 1 < n; i++){
        if(s[i + 1] < s[i]){
            t = rotate(s, i, n);
            break;
        }
    }
    cout << t << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
