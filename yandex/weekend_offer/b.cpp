#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, t;
    cin >> n >> t;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int count = 0;
    for (int i = 0; i < n - 3; i++) {
        if (i > 0 && v[i - 1] == v[i])
            continue;

        for (int j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && v[j - 1] == v[j])
                continue;

            int l = j + 1;
            int r = n - 1;

            while (l < r) {
                long long sum = (long long)(v[i] + v[j] + v[l] + v[r]);

                if (sum == t) {
                    count++;

                    while (l < r && v[l] == v[l + 1])
                        l++;
                    while (l < r && v[r - 1] == v[r])
                        r--;

                    l++;
                    r--;
                } else if (sum < t) {
                    l++;
                } else {
                    r--;
                }
            }
        }
    }

    cout << count;

    return 0;
}
