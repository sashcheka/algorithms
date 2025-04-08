#include<bits/stdc++.h>

using namespace std;

long long get_number(int x, int y, int n) {
    if (n == 1) {
        if (x == 1 && y == 1) {
            return 1;
        } else if (x == 2 && y == 2) {
            return 2;
        } else if (x == 2 && y == 1) {
            return 3;
        } else if (x == 1 && y == 2) {
            return 4;
        }   
    }

    int half = pow(2, n - 1);
    long long part_size = pow(2, 2 * (n - 1));

    int part;
    int next_x;
    int next_y;
    if (x <= half && y <= half) {
        part = 0;
        next_x = x;
        next_y = y;
    } else if (x > half && y > half) {
        part = 1;
        next_x = x - half;
        next_y = y - half;
    } else if (x > half && y <= half) {
        part = 2;
        next_x = x - half;
        next_y = y;
    } else if (x <= half && y > half) {
        part = 3;
        next_x = x;
        next_y = y - half;
    }

    return part * part_size + get_number(next_x, next_y, n - 1);
}

pair<int, int> get_coordinates(long long d, int n) {
    if (n == 1) {
        if (d == 1) {
            return {1, 1};
        } else if (d == 2) {
            return {2, 2};
        } else if (d == 3) {
            return {2, 1};
        } else if (d == 4) {
            return {1, 2};
        }
    }

    int half = pow(2, n - 1);
    long long part_size = pow(2, 2 * (n - 1));
    int part = (d - 1) / part_size;
    long long next_d = d - part * part_size;
    pair<int, int> relative_coordinates = get_coordinates(next_d, n - 1);

    int x;
    int y;
    if (part == 0) {
        x = relative_coordinates.first;
        y = relative_coordinates.second;
    } else if (part == 1) {
        x = relative_coordinates.first + half;
        y = relative_coordinates.second + half;
    } else if (part == 2) {
        x = relative_coordinates.first + half;
        y = relative_coordinates.second;
    } else if (part == 3) {
        x = relative_coordinates.first;
        y = relative_coordinates.second + half;
    }

    return {x, y};
}

void solve() {
    int n, q;
    cin >> n >> q;

    while (q--) {
        string oper;
        cin >> oper;

        if (oper == "->") {
            int x, y;
            cin >> x >> y;
            cout << get_number(x, y, n) << '\n';
        } else if (oper == "<-") {
            long long d;
            cin >> d;
            pair<int, int> coordinates = get_coordinates(d, n);
            cout << coordinates.first << ' ' << coordinates.second << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}
