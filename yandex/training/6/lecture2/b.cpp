#include<bits/stdc++.h>

using namespace std;

void solve_using_map() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    unordered_map<int, int> m;
    m[0] = 1;

    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];

        int target = sum - k;
        if (m.find(target) != m.end())
            count += m[target];

        m[sum]++;
    }

    cout << count;
}

void solve_using_two_pointers() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int l = 0;
    int r = 0;
    int sum = 0;
    int count = 0;

    while (r < n) {
        sum += v[r];

        while (l <= r && sum > k) {
            sum -= v[l];
            l++;
        }

        if (sum == k)
            count++;

        r++;
    }

    cout << count;
}

void solve_using_prefix_sum() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> p(n + 1, 0);
    for (int i = 1; i < n + 1; i++)
        p[i] = p[i - 1] + v[i - 1];

    int count = 0;
    for (int r = 0; r < n + 1; r++) {
        for (int l = 0; l < r; l++) {
            if (p[r] - p[l] == k)
                count++;
        }
    }

    cout << count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // solve_using_map();
    // solve_using_two_pointers();
    solve_using_prefix_sum();

    return 0;
}