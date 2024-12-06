#include <bits/stdc++.h>

using namespace std;

vector<int> solve(string& s) {
    stringstream ss(s);
    string part;

    vector<int> nums;

    while(getline(ss, part, ',')) {
        int dash_idx = -1;

        for (int i = 0; i < part.size(); i++) {
            if (part[i] == '-') {
                dash_idx = i;
                break;
            }
        }

        if (dash_idx != -1) {
            int l = stoi(part.substr(0, dash_idx));
            int r = stoi(part.substr(dash_idx + 1));

            for (int i = l; i <= r; i++)
                nums.push_back(i);

        } else {
            nums.push_back(stoi(part));
        }
    }
        
    return nums;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    vector<int> nums = solve(s);

    for (const int& num : nums)
        cout << num << ' ';   

    return 0;
}
