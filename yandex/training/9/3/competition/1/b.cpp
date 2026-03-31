#include<bits/stdc++.h>

using namespace std;

int main() {
    int n = 0;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    int best = 0;
    int l = 0;
    unordered_map<int, int> pupka;
    for (int r = 0; r < n; r++) {
        pupka[p[r]]++;
        while (pupka.size() > 2) {
            pupka[p[l]]--;
            if (pupka[p[l]] == 0) pupka.erase(p[l]);
            l++;
        }
        if (pupka.size() == 2) {
            int cand = r - l + 1;
            best = max(best, cand);
        }
    }

    cout << best;
    return 0;
}