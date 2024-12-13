#include <iostream>
#include <vector>
#include <tuple>
#include <limits>
#include <fstream>

using namespace std;
typedef long long ll;

// Solve a system of linear Diophantine equations for a claw machine:
// a*X_A + b*X_B = X_P
// a*Y_A + b*Y_B = Y_P
// with cost = 3a + b minimized for nonnegative integers a,b.
//
// This simplified version only checks the direct computed solution from the formula.
// It does not attempt to adjust the solution by a parameter t for better feasibility or cost.
bool solve(ll XA, ll YA, ll XB, ll YB, ll XP, ll YP, ll &bestCost) {
    ll D = XA * YB - YA * XB;
    if (D == 0) return false; // No unique solution

    ll numA = XP * YB - YP * XB;
    ll numB = -XP * YA + YP * XA;

    if (numA % D != 0 || numB % D != 0) return false;

    ll a = numA / D;
    ll b = numB / D;

    // Check if this solution is nonnegative
    if (a >= 0 && b >= 0) {
        ll cost = 3LL * a + b;
        if (cost < bestCost) {
            bestCost = cost;
            return true;
        }
    }

    return false;
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
