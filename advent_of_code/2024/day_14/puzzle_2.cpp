#include <iostream>
#include <vector>
#include <tuple>
#include <limits>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    ifstream file("input_1.txt");
    string line;

    vector<vector<int>> robots;
    while (getline(file, line)) {
        int i = 2;

        int sign = 1;
        int px = 0;
        if (line[i] == '-') {
            sign = -1;
            i++;
        }
        while (line[i] != ',') px = px * 10 + line[i++] - '0';
        i++;
        px *= sign;

        sign = 1;
        int py = 0;
        if (line[i] == '-') {
            sign = -1;
            i++;
        }
        while (line[i] != ' ') py = py * 10 + line[i++] - '0';
        i += 3;
        py *= sign;

        sign = 1;
        int vx = 0;
        if (line[i] == '-') {
            sign = -1;
            i++;
        }
        while (line[i] != ',') vx = vx * 10 + line[i++] - '0';
        i++;
        vx *= sign;

        sign = 1;
        int vy = 0;
        if (line[i] == '-') {
            sign = -1;
            i++;
        }
        while (i < line.size()) vy = vy * 10 + line[i++] - '0';
        vy *= sign;

        robots.push_back({px, py, vx, vy});
    }

    int n = 103;
    int m = 101;
    int steps = 1e5;

    vector<int> quadrants(4, 0);
    for (int step = 1; step <= steps; step++) {
        bool found = true;
        cout << "STEP : " << step << '\n';
        vector<vector<int>> grid(n, vector<int>(m, 0));

        for (auto robot : robots) {
            int px = robot[0], py = robot[1], vx = robot[2], vy = robot[3];
            if (vx < 0) vx += m;
            if (vy < 0) vy += n;

            int nx = abs((px + (vx * step) % m) % m);
            int ny = abs((py + (vy * step) % n) % n);
            if (grid[ny][nx] != 0) {
                found = false;
                continue;
            }
            grid[ny][nx]++;

            int q = 0;
            if (ny == n / 2 || nx == m / 2) continue;

            if (ny > n / 2) q += 2;
            if (nx > m / 2) q += 1;
            quadrants[q]++;
        }

        if (!found) continue;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) cout << " \n"[j == m - 1];
                else cout << "#\n"[j == m - 1];
            }
        }
        break;
    }

    int sf = 1;
    for (int q : quadrants) sf *= q;
    cout << sf;
    return 0;
}
