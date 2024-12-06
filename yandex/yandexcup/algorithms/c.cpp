#include<bits/stdc++.h>

using namespace std;

int width(const string& s, char replace_char) {
    int curr_pos = 0;
    int min_pos = 0;
    int max_pos = 0;

    for (char ch : s) {
        if (ch == 'L' || (ch == '?' && replace_char == 'L')) {
            curr_pos -= 1;
        } else if (ch == 'R' || (ch == '?' && replace_char == 'R')) {
            curr_pos += 1;
        }
        
        min_pos = min(min_pos, curr_pos);
        max_pos = max(max_pos, curr_pos);
    }

    return max_pos - min_pos;
}

int main() {
    string s;
    cin >> s;

    int width_l = width(s, 'L');
    int width_r = width(s, 'R');

    int max_width = max(width_l, width_r);
    cout << max_width << endl;

    return 0;
}
