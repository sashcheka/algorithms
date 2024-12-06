#include<bits/stdc++.h>

using namespace std;

int main() {
    ifstream file("input_1.txt");
    string line;

    long long sum = 0;

    while (getline(file, line)) {
        int i = 0;
        int n = line.size();
        while (i < n) {
            string s, t;
            if (i + 4 < n && line.substr(i, 4) == "mul(") {
                i += 4;
                while (isdigit(line[i])) {
                    s += line[i];
                    i++;
                }
                if (line[i] == ',') {
                    i++;
                    while (isdigit(line[i])) {
                        t += line[i];
                        i++;
                    }
                    if (line[i] == ')') {
                        long long a = stoi(s);
                        long long b = stoi(t);
                        sum += a * b;
                    }
                } else {
                    i++;
                    continue;
                }
            } else {
                i++;
            }
        }
    }

    cout << sum;
    return 0;
}