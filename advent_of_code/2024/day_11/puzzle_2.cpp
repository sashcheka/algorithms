#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>

using namespace std;
typedef long long ll;

map<pair<ll, int>, ll> dupa;

ll count(ll stone, int steps) {
    if (steps == 0) return 1;

    pair<ll, int> key = {stone, steps};
    if (dupa.find(key) != dupa.end()) return dupa[key];

    if (stone == 0) {
        ll res = count(1, steps - 1);
        return dupa[key] = res;
    }

    string str = to_string(stone);
    int l = str.size();
    if (l % 2 == 0) {
        ll left = stoll(str.substr(0, l / 2));
        ll right = stoll(str.substr(l / 2));

        ll res = count(left, steps - 1) + count(right, steps - 1);
        return dupa[key] = res;
    } else {
        ll res = count(stone * 2024, steps - 1);
        return dupa[key] = res;
    }
}

int main() {
    ifstream file("input_1.txt");

    ll stone;
    vector<ll> stones;
    while (file >> stone) stones.push_back(stone);

    ll ans = 0;
    for (ll stone : stones) ans += count(stone, 75);
        
    cout << ans;
    return 0;
}
