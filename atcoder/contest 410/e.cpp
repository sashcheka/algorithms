#include <bits/stdc++.h>
using namespace std;

void solve(){
    int N, H, M;
    cin >> N >> H >> M;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++)cin >> A[i] >> B[i];

    vector<int> dp(H + 1, -1), next_dp(H + 1, -1);
    dp[H] = M;

    for(int i = 0; i < N; i++){
        fill(next_dp.begin(), next_dp.end(), -1);

        for (int h = 0; h <= H; h++){
            int m = dp[h];
            if (m < 0) continue;

            if (h >= A[i]){
                int next_h = h - A[i];
                next_dp[next_h] = max(next_dp[next_h], m);
            }

            if (m >= B[i]){
                int nm = m - B[i];
                next_dp[h] = max(next_dp[h], nm);
            }
        }

        dp.swap(next_dp);

        bool survive = false;
        for (int h = 0; h <= H; h++){
            if (dp[h] >= 0){
                survive = true;
                break;
            }
        }

        if (!survive){
            cout << i << "\n";
            return;
        }
    }

    cout << N << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
