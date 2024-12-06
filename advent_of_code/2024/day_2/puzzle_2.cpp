#include<bits/stdc++.h>

using namespace std;


bool is_safe(const vector<int>& v) {
    bool incr = true, decr = true;
    
    for (int i = 1; i < v.size(); i++) {
        int diff = abs(v[i - 1] - v[i]);

        if (diff < 1 || diff > 3) {
            return false;
        }

        if (v[i - 1] > v[i]) incr = false;
        if (v[i - 1] <v[i]) decr = false;
    }

    return incr || decr;
}

bool is_tolerate_safe(const vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        vector<int> temp = v;
        temp.erase(temp.begin() + i);

        if (is_safe(temp)) return true;
    }
    return false;
}

int main() {
    int count = 0;

    ifstream file("test.txt");
    string line;

    while (getline(file, line)) {
        stringstream ss(line);

        int i;
        vector<int> v;
        while (ss >> i) v.push_back(i);

        if (is_safe(v) || is_tolerate_safe(v)) count++;
    }

    cout << count;
    return 0;
}