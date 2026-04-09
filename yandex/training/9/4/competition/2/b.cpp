#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string target;
    cin >> target;

    int m;
    cin >> m;
    vector<string> vars(m);
    vector<int> correct(m);
    vector<int> wrong(m);
    for (int i = 0; i < m; i++) {
        cin >> vars[i];
        for (int j = 0; j < n; j++) {
            if (vars[i][j] == target[j]) correct[i]++;
            else wrong[i]++;
        }
    }

    vector<pair<int, int>> similar;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            int good = 0;
            int bad = 0;
            for (int k = 0; k < n; k++) {
                if (vars[i][k] == vars[j][k] && vars[i][k] == target[k]) good++;
                else if (vars[i][k] == vars[j][k] && vars[i][k] != target[k]) bad++;
            }

            if (good * 2 > correct[i] && good * 2 > correct[j] && bad * 2 > wrong[i] && bad * 2 > wrong[j]) {
                similar.push_back({i + 1, j + 1});
            }
        }
    }

    cout << similar.size() << "\n";
    for (auto& [i, j] : similar) {
        cout << i << " " << j << "\n";
    }
    
    return 0;
}