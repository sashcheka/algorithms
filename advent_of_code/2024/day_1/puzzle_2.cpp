#include<bits/stdc++.h>

using namespace std;

int main() {
    ifstream file("input.txt");

    unordered_map<long, long> m1;
    unordered_map<long, long> m2;
    long long n1, n2;
    while (file >> n1 >> n2) {
        m1[n1]++;
        m2[n2]++;
    }

    long long dist = 0;

    for (const pair<int, int>& p : m1) {
        dist += p.first * p.second * m2[p.first];
    }

    cout << dist;

    return 0;
}