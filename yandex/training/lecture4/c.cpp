#include<bits/stdc++.h>

using namespace std;

void solve() {
    ifstream file("c.txt");

    int n;
    file >> n;
    n--;

    unordered_map<string, string> parent_of;
    set<string> people;

    string child, parent;
    while (n--) {
        file >> child >> parent;
        people.insert(child);
        people.insert(parent);

        parent_of[child] = parent;
    }

    string a_child;
    string b_child;
    while (file >> a_child >> b_child) {
        queue<string> q;

        vector<string> a_ancestors;
        a_ancestors.push_back(a_child);
        q.push(a_child);

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            if (parent_of.find(curr) == parent_of.end()) continue;

            string nxt = parent_of[curr];
            a_ancestors.push_back(nxt);
            q.push(nxt);
        }

        unordered_set<string> b_ancestors;
        b_ancestors.insert(b_child);
        q.push(b_child);
        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            if (parent_of.find(curr) == parent_of.end()) continue;

            string nxt = parent_of[curr];
            b_ancestors.insert(nxt);
            q.push(nxt);
        }

        for (const string& ancestor : a_ancestors) {
            if (b_ancestors.count(ancestor)) {
                cout << ancestor << '\n';
                break;
            }
        }
    }

    file.close();
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}