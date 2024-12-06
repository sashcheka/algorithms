#include<bits/stdc++.h>

using namespace std;

void solve(int n, vector<int>& p, string& s) {
    vector<int> ans(n);
    vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i) {
        if (visited[i]) 
            continue;
        
        int curr = i;
        vector<int> cycle;
        int count = 0;

        do {
            visited[curr] = true;
            cycle.push_back(curr);

            if (s[curr] == '0')
                count++;

            curr = p[curr] - 1;
        } while (curr != i);

        for (const int& node : cycle)
            ans[node] = count;
    }

    for (const int& count : ans)
        cout << count << ' ';

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        vector<int> p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];

        string s;
        cin >> s;

        solve(n, p, s);
    }

    return 0;
}
