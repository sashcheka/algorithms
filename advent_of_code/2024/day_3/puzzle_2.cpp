#include<bits/stdc++.h>

using namespace std;

int main() {
    string file_name;
    cin >> file_name;
    file_name += ".txt";
    ifstream file(file_name);
    string line;

    long long sum = 0;
    bool enable = true;

    while (getline(file, line)) {
        int i = 0;
        int n = line.size();

        while (i < n) {
            string s, t;
            if (i + 4 < n && line.substr(i, 4) == "do()") {
                enable = true;
            }
            if (i + 7 < n && line.substr(i, 7) == "don't()") {
                enable = false;
            }

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
                        if (enable) sum += a * b;
                    }
                }
            }
            i++;
        }
    }

    cout << sum;
    return 0;
}