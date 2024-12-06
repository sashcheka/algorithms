#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;

    int time = 0;
    int pointer = 'A';

    for (const char& ch : s) {
        int clockwise = abs(ch - pointer);
        int counter_clockwise = 26 - clockwise;

        time += min(clockwise, counter_clockwise);

        pointer = ch;
    }

    cout << time;

    return 0;
}
