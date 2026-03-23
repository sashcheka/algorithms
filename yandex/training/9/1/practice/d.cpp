#include<bits/stdc++.h>

using namespace std;

int main() {
    int room, cond;
    cin >> room >> cond;

    string mode;
    cin >> mode;
    if (mode == "freeze") {
        cout << (cond <= room ? cond : room);
    } else if (mode == "heat") {
        cout << (cond >= room ? cond : room);
    } else if (mode == "auto") {
        cout << (cond);
    } else if (mode == "fan") {
        cout << (room);
    }
    cout << "\n";

    return 0;
}