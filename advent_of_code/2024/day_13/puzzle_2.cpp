#include <iostream>
#include <vector>
#include <tuple>
#include <limits>
#include <fstream>

using namespace std;
typedef long long ll;

bool solve(ll XA, ll YA, ll XB, ll YB, ll XP, ll YP, ll &bestCost) {
    if (XA * YB - YA * XB == 0) return false;

    if ((XP * YB - YP * XB) % (XA * YB - YA * XB) != 0) return false;
    ll CA = (XP * YB - YP * XB) / (XA * YB - YA * XB);

    if ((XP - XA * CA) % XB != 0) return false;
    ll CB = (XP - XA * CA) / XB;

    bestCost = CA * 3 + CB;

    return true;
}

int main() {
    ifstream inputFile("input_1.txt");

    vector<tuple<ll, ll, ll, ll, ll, ll>> machines;
    string line;

    ll dxA = 0, dyA = 0, dxB = 0, dyB = 0, Px = 0, Py = 0;
    int queue = 0;

    while (getline(inputFile, line)) {
        if (line.empty()) continue;

        int i = 0;
        if (queue == 0) {
            while (line[i] != '+') i++;
            i++;
            while (line[i] != ',') dxA = dxA * 10 + (line[i++] - '0');

            while (line[i] != '+') i++;
            i++;
            while (i < (int)line.size()) dyA = dyA * 10 + (line[i++] - '0');
            queue++;
        } else if (queue == 1) {
            while (line[i] != '+') i++;
            i++;
            while (line[i] != ',') dxB = dxB * 10 + (line[i++] - '0');

            while (line[i] != '+') i++;
            i++;
            while (i < (int)line.size()) dyB = dyB * 10 + (line[i++] - '0');
            queue++;
        } else {
            while (line[i] != '=') i++;
            i++;
            while (line[i] != ',') Px = Px * 10 + (line[i++] - '0');

            while (line[i] != '=') i++;
            i++;
            while (i < (int)line.size()) Py = Py * 10 + (line[i++] - '0');

            Px += 10000000000000LL; 
            Py += 10000000000000LL;

            machines.emplace_back(dxA, dyA, dxB, dyB, Px, Py);
            dxA = dyA = dxB = dyB = Px = Py = 0;
            queue = 0;
        }
    }

    ll totalMinCost = 0;
    int prizesWon = 0;

    for (auto &m : machines) {
        ll XA, YA, XB, YB, XP, YP;
        tie(XA, YA, XB, YB, XP, YP) = m;

        ll bestCost = LLONG_MAX;
        if (solve(XA, YA, XB, YB, XP, YP, bestCost)) {
            totalMinCost += bestCost;
            prizesWon++;
        }
    }

    cout << "Prizes won: " << prizesWon << "\n";
    if (prizesWon > 0) {
        cout << "Minimum total cost: " << totalMinCost << "\n";
    } else {
        cout << "No prizes can be won.\n";
    }

    return 0;
}
