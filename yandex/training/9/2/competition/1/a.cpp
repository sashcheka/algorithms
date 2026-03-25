#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, int> score;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        score[name] = 0;
    }

    int m;
    cin >> m;
    
    long long left = 0;
    long long right = 0;
    long long best = 0;
    string best_name;
    for (int j = 0; j < m; j++) {
        string sc, name;
        cin >> sc >> name;
        int delim_idx = sc.find(':');
        long long l = stoi(sc.substr(0, delim_idx));
        long long r = stoi(sc.substr(delim_idx + 1));
        if (left == l) {
            score[name] += r - right;
            right = r;
        } else {
            score[name] += l - left;
            left = l;
        }
        if (score[name] > best) {
            best = score[name];
            best_name = name;
        }
    }

    cout << best_name << " " << best;
    return 0;
}