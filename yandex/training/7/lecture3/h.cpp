#include <bits/stdc++.h>

using namespace std;

static const int SIZE = 128;
vector<vector<vector<long long>>> fenwick;
int n;

void update(int x, int y, int z, long long diff) {
    int i = x;
    while (i < n) {
        int j = y;
        while (j < n) {
            int k = z;
            while (k < n) {
                fenwick[i][j][k] += diff;
                k = k | (k + 1);
            }
            j = j | (j + 1);
        }
        i = i | (i + 1);
    }
}

long long query(int x, int y, int z) {
    long long prefix_3d_sum = 0;
    int i = x;
    while (i >= 0) {
        int j = y;
        while (j >= 0) {
            int k = z;
            while (k >= 0) {
                prefix_3d_sum += fenwick[i][j][k];
                k = (k & (k + 1)) - 1;
            }
            j = (j & (j + 1)) - 1;
        }
        i = (i & (i + 1)) - 1;
    }
    return prefix_3d_sum;
}

long long calculate(int x1, int y1, int z1, int x2, int y2, int z2) {
    long long xyz = query(x2, y2, z2) - query(x1 - 1, y1 - 1, z1 - 1);
    long long x   = query(x1 - 1, y1 - 1, z2) - query(x1 - 1, y2, z2);
    long long y   = query(x1 - 1, y2, z1 - 1) - query(x2, y1 - 1, z2);
    long long z   = query(x2, y1 - 1, z1 - 1) - query(x2, y2, z1 - 1);
    return xyz + x + y + z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    fenwick.assign(n, vector<vector<long long>>(n, vector<long long>(n, 0)));

    while (true) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int x, y, z;
            long long k;
            cin >> x >> y >> z >> k;
            update(x, y, z, k);
        }
        else if (cmd == 2) {
            int x1, y1, z1, x2, y2, z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            cout << calculate(x1, y1, z1, x2, y2, z2) << "\n";
        }
        else if (cmd == 3) {
            break;
        }
    }

    return 0;
}
