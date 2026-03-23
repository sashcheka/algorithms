#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<string, int> mapka;
    unordered_set<string> all;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            string lang;
            cin >> lang;
            mapka[lang]++;
            if (mapka[lang] == n) {
                all.insert(lang);
            }
        }
    }

    cout << all.size() << "\n";
    for (const string& lang : all) cout << lang << "\n";

    cout << mapka.size() << "\n";
    for (auto [lang, _] : mapka) cout << lang << "\n";

    return 0;
}