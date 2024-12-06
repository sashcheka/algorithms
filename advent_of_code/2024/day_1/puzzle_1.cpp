#include<bits/stdc++.h>

using namespace std;

int main() {
    ifstream file("input.txt");

    vector<long long> v1, v2;
    long long n1, n2;
    while (file >> n1 >> n2) {
        v1.push_back(n1);
        v2.push_back(n2);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    long long dist = 0;
    for (int i = 0; i < v1.size(); i++) {
        dist += abs(v1[i] - v2[i]);
    }

    cout << dist;

    return 0;
}