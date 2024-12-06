#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
    ull max_limit = 1e18;
    ull low = 1, high = 1, prev_low = 0;
    string response;
    int query_count = 0;

    while (true) {
        cout << high << endl;
        cout.flush();
        query_count++;
        if (query_count > 200) {
            return 0;
        }

        cin >> response;
        if (response == "fail") {
            break;
        } else if (response == "wet") {
            prev_low = high;
            if (high >= max_limit / 2) {
                high = max_limit;
            } else {
                high *= 2;
            }
        } else if (response == "ok") {
            break;
        } else {
            return 0;
        }
    }

    if (response == "fail" && prev_low == 0) {
        cout << "! " << 1 << endl;
        cout.flush();
        return 0;
    }

    if (response == "fail") {
        high = high - 1;
    }

    low = prev_low + 1;
    ull mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        cout << mid << endl;
        cout.flush();
        query_count++;
        if (query_count > 200) {
            return 0;
        }

        cin >> response;
        if (response == "fail") {
            high = mid - 1;
            break;
        } else if (response == "wet") {
            low = mid + 1;
        } else if (response == "ok") {
            high = mid - 1;
        } else {
            return 0;
        }
    }

    cout << "! " << low << endl;
    cout.flush();
    return 0;
}
