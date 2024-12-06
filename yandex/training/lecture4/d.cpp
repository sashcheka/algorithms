#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value): value(value), left(nullptr), right(nullptr) {}
};

TreeNode* add(TreeNode* root, int value) {
    if (!root) {
        cout << "DONE" << '\n';
        return new TreeNode(value);
    };

    if (value < root->value) {
        root->left = add(root->left, value);
    } else if (value > root->value) {
        root->right = add(root->right, value);
    } else if (value == root->value) {
        cout << "ALREADY" << '\n';
    }

    return root;
}

void search(TreeNode* root, int value) {
    if (!root) {
        cout << "NO" << '\n';
        return;
    }

    if (value < root->value) {
        search(root->left, value);
    } else if (value > root->value) {
        search(root->right, value);
    } else {
        cout << "YES" << '\n';
        return;
    }
}

void printtree(TreeNode* root, int depth) {
    if (!root) return;

    printtree(root->left, depth + 1);
    for (int i = 0; i < depth; i++) cout << '.';
    cout << root->value << '\n';
    printtree(root->right, depth + 1);
}

void solve() {
    ifstream file("d.txt");

    TreeNode* root = nullptr;

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string query;
        iss >> query;

        if (query == "ADD") {
            int value;
            iss >> value;
            root = add(root, value);
        } else if (query == "SEARCH") {
            int value;
            iss >> value;
            search(root, value);
        } else if (query == "PRINTTREE") {
            printtree(root, 0);
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}