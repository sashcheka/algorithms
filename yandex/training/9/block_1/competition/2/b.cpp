#include<bits/stdc++.h>

using namespace std;

int main() {
    long long n, m, h, w;
    cin >> n >> m >> h >> w;

    auto count_folds = [](long long sheet, long long bag) {
        int folds = 0;
        while (sheet > bag) {
            sheet = (sheet + 1) / 2;
            ++folds;
        }
        return folds;
    };

    int cand_1 = count_folds(n, h) + count_folds(m, w);
    int cand_2 = count_folds(n, w) + count_folds(m, h);
    int best = min(cand_1, cand_2);
    cout << best;

    return 0;
}