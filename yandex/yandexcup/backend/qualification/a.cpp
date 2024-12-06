#include <bits/stdc++.h>

using namespace std;

int main() {
    cout << fixed << setprecision(9);
    unordered_map<int, int> patients;
    int total_temp = 0;
    int patients_count = 0;

    char oper;
    
    while (cin >> oper) {
        if (oper == '!') 
            return 0;

        if (oper == '+') {
            int id;
            double temp;
            cin >> id >> temp;
            if (patients.find(id) == patients.end()) {
                total_temp += temp * 10;
                patients_count++;
            } else {
                total_temp = total_temp - patients[id] + temp * 10;
            }
            patients[id] = (int)(temp * 10);
        }

        if (oper == '~') {
            int id;
            double temp;
            cin >> id >> temp;
            if (patients.find(id) != patients.end()) {
                total_temp = total_temp - patients[id] + temp * 10;
            } else {
                total_temp += temp * 10;
                patients_count++;
            }
            patients[id] = (int)(temp * 10);
        }

        if (oper == '-') {
            int id;
            cin >> id;
            if (patients.find(id) != patients.end()) {
                total_temp -= patients[id];
                patients_count--;
                patients.erase(id);
            }
        }

        if (oper == '?') {
            if (patients_count == 0) {
                cout << 0 << endl;
            } else {
                double avg = total_temp / (double)(patients_count * 10);
                cout << avg << endl;
            }
        }
    }

    return 0;
}
