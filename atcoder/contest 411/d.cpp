#include <bits/stdc++.h>
using namespace std;

struct Node {
    string part;
    Node* prev;
    Node(string s, Node* node) : part(s), prev(node) {}
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<Node*> pc(n, nullptr);
    Node* server = nullptr;

    for (int i = 0; i < q; i++) {
        int type, p;
        cin >> type >> p;
        p--;

        if (type == 1) {
            pc[p] = server;
        } else if (type == 2) {
            string s;
            cin >> s;
            pc[p] = new Node(s, pc[p]);
        } else if (type == 3) {
            server = pc[p];
        }
    }
    
    vector<string> ans;
    Node* curr = server;
    while (curr) {
        ans.push_back(curr->part);
        curr = curr->prev;
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}