#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;

        vector<vector<long long>> blocks(n, vector<long long>(m));
        vector<long long> sums(n, 0LL);

        for(int i = 0; i < n; i++){
            long long s = 0;
            for(int j = 0; j < m; j++){
                cin >> blocks[i][j];
                s += blocks[i][j];
            }
            sums[i] = s;
        }

        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b){
            return sums[a] > sums[b];
        });

        vector<long long> finalArr;
        finalArr.reserve((long long)n*m);

        for(int p=0; p<n; p++){
            int blockID = idx[p];
            for(int j=0; j<m; j++){
                finalArr.push_back(blocks[blockID][j]);
            }
        }

        long long prefix = 0, ans = 0;
        for(long long val : finalArr){
            prefix += val;
            ans += prefix;
        }

        cout << ans << "\n";
    }

    return 0;
}
