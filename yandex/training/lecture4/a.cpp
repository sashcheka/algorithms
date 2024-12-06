#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    n--;

    unordered_map<string, vector<string>> parent_childs;
    set<string> people;
    unordered_set<string> childs;

    string child;
    string parent;
    while (n--) {
        cin >> child >> parent;

        people.insert(child);
        people.insert(parent);

        childs.insert(child);

        parent_childs[parent].push_back(child);
    }

    string root;
    for (const string& cand : people) {
        if (childs.count(cand) == 0) {
            root = cand;
            break;
        }
    }

    unordered_map<string, int> heights;
    queue<string> q;
    heights[root] = 0;
    q.push(root);

    while (!q.empty()) {
        string curr = q.front();
        q.pop();

        int curr_height = heights[curr];
        for (const string& child : parent_childs[curr]) {
            heights[child] = curr_height + 1;
            q.push(child);
        }
    }

    for (const string& p : people) cout << p << ' ' << heights[p] << '\n';
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}