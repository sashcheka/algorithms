#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        bool flag = false;
        for (int i = 0; i < str.size() - 1; i++) {
            if (str[i] == str[i + 1]) {
                flag = true;
                break;
            }
        }

        if (flag) {
            cout << 1 << '\n';
        } else {
            cout << str.size() << '\n';
        }
    };
    
    return 0;
}
