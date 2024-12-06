#include<bits/stdc++.h>

using namespace std;

int main() {
    ifstream file("input.txt");
    string line;

    int count = 0;
    while (getline(file, line)) {
        stringstream ss(line);

        int i;
        vector<int> v;
        while (ss >> i) v.push_back(i);

        bool incr = true;
        bool decr = true;
        bool safe = true;
        
        for (int i = 1; i < v.size(); i++) {
            int diff = abs(v[i - 1] - v[i]);

            if (diff < 1 || diff > 3) {
                safe = false;
                break;
            }

            if (v[i - 1] > v[i]) incr = false;
            if (v[i - 1] < v[i]) decr = false;
        }

        if (safe && (incr || decr)) count++;
    }

    cout << count;
    return 0;
}