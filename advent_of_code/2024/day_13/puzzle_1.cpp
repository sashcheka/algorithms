#include <iostream>
#include <vector>
#include <tuple>
#include <limits>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

int findMinimumCost(int dxA, int dyA, int dxB, int dyB, int Px, int Py) {
    int minCost = INT_MAX;

    for (int B = 0; B <= 100; ++B) {
        int PxResidual = Px - dxB * B;
        if (PxResidual % dxA != 0) continue;

        int A = PxResidual / dxA;
        if (A < 0) continue;

        if (dyA * A + dyB * B == Py) {
            int cost = 3 * A + 1 * B;
            minCost = min(minCost, cost);
        }
    }

    return minCost == INT_MAX ? -1 : minCost;
}

int main() {
    ifstream inputFile("input_1.txt");

    vector<tuple<int, int, int, int, int, int>> machines;
    string line;

    int dxA = 0, dyA = 0, dxB = 0, dyB = 0, Px = 0, Py = 0;
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
            while (i < line.size()) dyA = dyA * 10 + (line[i++] - '0');
            queue++;
        } else if (queue == 1) {
            while (line[i] != '+') i++;
            i++;
            while (line[i] != ',') dxB = dxB * 10 + (line[i++] - '0');

            while (line[i] != '+') i++;
            i++;
            while (i < line.size()) dyB = dyB * 10 + (line[i++] - '0');
            queue++;
        } else {
            while (line[i] != '=') i++;
            i++;
            while (line[i] != ',') Px = Px * 10 + (line[i++] - '0');

            while (line[i] != '=') i++;
            i++;
            while (i < line.size()) Py = Py * 10 + (line[i++] - '0');
            machines.emplace_back(dxA, dyA, dxB, dyB, Px, Py);
            dxA = dyA = dxB = dyB = Px = Py = 0;
            queue = 0;
        }
    }

    int totalPrizes = 0;
    int totalCost = 0;

    for (const auto& machine : machines) {
        int dxA, dyA, dxB, dyB, Px, Py;
        tie(dxA, dyA, dxB, dyB, Px, Py) = machine;

        int cost = findMinimumCost(dxA, dyA, dxB, dyB, Px, Py);
        if (cost != -1) {
            ++totalPrizes;
            totalCost += cost;
        }
    }

    cout << "Maximum prizes won: " << totalPrizes << endl;
    cout << "Minimum total cost: " << totalCost << endl;

    return 0;
}
