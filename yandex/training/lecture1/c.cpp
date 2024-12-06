#include<bits/stdc++.h>

using namespace std;

vector<string> compress(const vector<string>& lst) {
    vector<string> ans = {lst[0]};

    for (int i = 1; i < lst.size(); i++)
        if (lst[i] != ans.back())
            ans.push_back(lst[i]);

    if (ans.size() > 1 && set<char>(ans[0].begin(), ans[0].end()) == set<char>{'.'})
        ans.erase(ans.begin());
    
    if (ans.size() > 1 && set<char>(ans.back().begin(), ans.back().end()) == set<char>{'.'})
        ans.pop_back();

    return ans;
}

vector<string> invert(const vector<string>& lst) {
    vector<string> ans;

    if (lst.empty())
        return ans;

    for (int i = 0; i < lst[0].size(); i++) {
        string new_str;

        for (const string& s : lst)
            new_str += s[i];

        ans.push_back(new_str);
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<string> matrix(n);

    for (int i = 0; i < n; i++)
        cin >> matrix[i];

    matrix = invert(compress(invert(compress(matrix))));

    vector<string> I = {"#"};
    vector<string> O = {"###", "#.#", "###"};
    vector<string> C = {"##", "#.", "##"};
    vector<string> L = {"#.", "##"};
    vector<string> H = {"#.#", "###", "#.#"};
    vector<string> P = {"###", "#.#", "###", "#.."};

    if (matrix == I)
        cout << 'I';
    else if (matrix == O)
        cout << 'O';
    else if (matrix == C)
        cout << 'C';
    else if (matrix == L)
        cout << 'L';
    else if (matrix == H)
        cout << 'H';
    else if (matrix == P)
        cout << 'P';
    else
        cout << 'X';

    return 0;
}
