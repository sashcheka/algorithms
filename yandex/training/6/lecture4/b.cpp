#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    n--;

    unordered_map<string, vector<string>> childs_of;
    unordered_map<string, string> parent_of;
    set<string> people;

    string child, parent;
    while (n--) {
        cin >> child >> parent;
        people.insert(child);
        people.insert(parent);

        childs_of[parent].push_back(child);
        parent_of[child] = parent;
    }

    unordered_map<string, int> pending_childs;
    for (const auto& [parent, childs] : childs_of) pending_childs[parent] = childs.size();

    unordered_map<string, int> descendants;
    queue<string> q;
    for (const string& p : people) {
        if (childs_of.find(p) == childs_of.end()) {
            descendants[p] = 0;
            q.push(p);
        }
    }

    while(!q.empty()) {
        string curr = q.front();
        q.pop();

        if (parent_of.find(curr) == parent_of.end()) continue;

        string parent = parent_of[curr];
        descendants[parent] += 1 + descendants[curr];
        pending_childs[parent]--;
        if (pending_childs[parent] == 0) q.push(parent);  
    }

    for (const string& p : people) cout << p << ' ' << descendants[p] << '\n';
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}