#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

const vector<pair<int, int>> directions = { {-1,0}, {0,1}, {1,0}, {0,-1} };

pair<long long, long long> dfs(char plot, int i, int j, const vector<vector<char>>& grid, vector<vector<bool>>& visited) {
    int n = grid.size();
    int m = grid[0].size();
    
    if (i < 0 || i >= n || j < 0 || j >= m) return {0, 1};
    if (grid[i][j] != plot) return {0, 1};
    if (visited[i][j]) return {0, 0};
    
    visited[i][j] = true;
    
    long long area = 1;
    long long perimeter = 0;
    
    for (auto& dir : directions) {
        int ni = i + dir.first;
        int nj = j + dir.second;
        pair<long long, long long> result = dfs(plot, ni, nj, grid, visited);
        area += result.first;
        perimeter += result.second;
    }
    
    return {area, perimeter};
}

int main() {
    ifstream file("input_1.txt");
    string line;
    vector<vector<char>> grid;

    while (getline(file, line)) {
        vector<char> row;
        for (char ch : line) row.push_back(ch);
        grid.push_back(row);
    }

    long long price = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                pair<long long, long long> p = dfs(grid[i][j], i, j, grid, visited);
                
                cout << "Processing Region: " << grid[i][j] 
                     << " | Area: " << p.first 
                     << " | Perimeter: " << p.second 
                     << " | Price: " << p.first * p.second << endl;
                
                price += p.first * p.second;
            }
        }
    }

    cout << "\nTotal Price: " << price << endl;
    return 0;
}
