#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    int sum = 0;
    int min_1_1 = 10;
    int min_1_2 = 10;
    int min_2_1 = 10;
    int min_2_2 = 10;
    for (const char& ch : s) {
        int d = ch - '0';
        sum += d;
        if (d % 3 == 1) {
            if (d < min_1_1) {
                min_1_2 = min_1_1;
                min_1_1 = d;
            } else if (d < min_1_2) {
                min_1_2 = d;
            }
        }
        if (d % 3 == 2) {
            if (d < min_2_1) {
                min_2_2 = min_2_1;
                min_2_1 = d;
            } else if (d < min_2_2) {
                min_2_2 = d;
            }
        }
    }

    vector<int> to_delete(10, 0);
    if (sum % 3 == 1) {
        if (min_1_1 < 10) {
            to_delete[min_1_1]++;
        } else {
            to_delete[min_2_1]++;
            to_delete[min_2_2]++;
        }
    } else if (sum % 3 == 2) {
        if (min_2_1 < 10) {
            to_delete[min_2_1]++;
        } else {
            to_delete[min_1_1]++;
            to_delete[min_1_2]++;
        }
    }

    sort(s.rbegin(), s.rend());
    for (const char& ch : s) {
        int d = ch - '0';
        if (to_delete[d]) {
            to_delete[d]--;
        } else {
            cout << ch;
        }
    }

    return 0;
}