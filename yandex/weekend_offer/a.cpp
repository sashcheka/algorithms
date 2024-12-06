#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, t;
    cin >> n >> t;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    long long time = 0;
    for (int i = 0; i < t; i++)
        time += v[i];

    int cand = 0;
    long long min_time = time;

    for (int i = t; i < n; i++) {
        time = time -  v[i - t] + v[i];
        if (time < min_time) {
            min_time = time;    
            cand = i + 1 - t;
        }
    }

    cout << cand + 1;

    return 0;
}
