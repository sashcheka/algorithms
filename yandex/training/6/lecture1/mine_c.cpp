#include<bits/stdc++.h>

using namespace std;

bool areEqual(const vector<vector<int>>& a, const vector<vector<int>>& b) {
    if (a.size() != b.size()) 
        return false;

    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i]) 
            return false;

    return true;
}

int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void bfs(int startRow, int startCol, vector<vector<bool>>& matrix, vector<vector<bool>>& visited, int& minRow, int& maxRow, int& minCol, int& maxCol) {
    int n = matrix.size();
    int m = matrix[0].size();
    queue<pair<int, int>> q;
    q.push({startRow, startCol});
    visited[startRow][startCol] = true;

    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();

        minRow = min(minRow, row);
        maxRow = max(maxRow, row);
        minCol = min(minCol, col);
        maxCol = max(maxCol, col);

        for (auto& dir : directions) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                matrix[newRow][newCol] && !visited[newRow][newCol]) {
                visited[newRow][newCol] = true;
                q.push({newRow, newCol});
            }
        }
    }
}

// bool isValidRectangle(int minRow, int maxRow, int minCol, int maxCol, vector<vector<bool>>& matrix) {
//     for (int i = minRow; i <= maxRow; ++i) {
//         for (int j = minCol; j <= maxCol; ++j) {
//             if (!matrix[i][j])  {
//                 return false;  
//             }
//         }
//     }

//     return true;
// }

bool isValidRectangle(int minRow, int maxRow, int minCol, int maxCol, vector<vector<bool>>& matrix) {
    for (int i = minRow; i <= maxRow; ++i) {
        if (!matrix[i][minCol] || !matrix[i][maxCol]) return false; // Left and right boundary
    }
    for (int j = minCol; j <= maxCol; ++j) {
        if (!matrix[minRow][j] || !matrix[maxRow][j]) return false; // Top and bottom boundary
    }
    return true; // Hollow center allowed
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    vector<vector<bool>> matrix(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char ch;
            cin >> ch;
            matrix[i][j] = ch == '#' ? 1 : 0;
        }
    }

    cout << "READED MATRIX" << '\n';

    int min_row = n, max_row = -1;
    int min_col = n, max_col = -1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1) {
                if (i < min_row) min_row = i;
                if (i > max_row) max_row = i;
                if (j < min_col) min_col = j;
                if (j > max_col) max_col = j;
            }
        }
    }

    int new_n = max_row - min_row + 1;
    int new_m = max_col - min_col + 1;

    vector<vector<bool>> trimmedGrid(new_n, vector<bool>(new_m));

    for (int i = 0; i < new_n; ++i)
        for (int j = 0; j < new_m; ++j)
            trimmedGrid[i][j] = matrix[min_row + i][min_col + j];

    cout << "TRIMMED MATRIX" << '\n';
    for (auto row : trimmedGrid) {
        for (auto flag : row)
            cout << flag << ' ';
        if (row.size())
            cout << '\n';
    }

    n = trimmedGrid.size();
    int m = trimmedGrid[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    bool valid = true;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (trimmedGrid[i][j] && !visited[i][j]) {
                int minRow = i, maxRow = i, minCol = j, maxCol = j;

                bfs(i, j, trimmedGrid, visited, minRow, maxRow, minCol, maxCol);

                if (!isValidRectangle(minRow, maxRow, minCol, maxCol, trimmedGrid)) {
                    valid = false;
                    break;
                }
            }
        }
        if (!valid) 
            break;
    }
    cout << "CHECKED MATRIX FOR RECTANGLES" << '\n';

    vector<vector<int>> rows;
    int prev_col_cell = -1;
    vector<int> prev_row;
    for (int i = 0; i < n; i++) {
        vector<int> curr_row;
        int on_row = 0;
        int off_row = 0;
        for (int j = 0; j < m; j++) {
            if (trimmedGrid[i][j] == 1) {
                on_row++;
                if (prev_col_cell == 0)
                    curr_row.push_back(1);
            } else if (trimmedGrid[i][j] == 0) {
                off_row++;
                if (prev_col_cell == 1)
                    curr_row.push_back(0);
            }

            prev_col_cell = trimmedGrid[i][j];
        }

        if (off_row == m)
            curr_row.push_back(2);
        else if (on_row == m)
            curr_row.push_back(3);

        if (prev_row != curr_row)
            rows.push_back(curr_row);
        prev_row = curr_row;
        prev_col_cell = -1;
    }

    cout << "ROWS" << '\n';

    vector<vector<int>> cols;
    int prev_row_cell = -1;
    vector<int> prev_col;
    for (int i = 0; i < n; i++) {
        vector<int> curr_col;
        int on_col = 0;
        int off_col = 0;
        for (int j = 0; j < m; j++) {
            if (trimmedGrid[j][i] == 1) {
                on_col++;
                if (prev_row_cell == 0)
                    curr_col.push_back(1);
            } else if (trimmedGrid[j][i] == 0) {
                off_col++;
                if (prev_row_cell == 1)
                    curr_col.push_back(0);
            }

            prev_row_cell = trimmedGrid[j][i];
        }

        if (off_col == n)
            curr_col.push_back(2);
        else if (on_col == n)
            curr_col.push_back(3);

        if (prev_col != curr_col)
            cols.push_back(curr_col);

        prev_col = curr_col;
        prev_row_cell = -1;
    }
    cout << "COLS" << '\n';


    cout << "ROWS: " << '\n';
    for (auto& row : rows) {
        for (auto& flag : row)
            cout << flag << ' ';
        if (row.size())
            cout << '\n';
    }

    cout << '\n' << "COLS: " << '\n';
    for (auto& col : cols) {
        for (auto& flag : col)
            cout << flag << ' ';
        if (col.size())
            cout << '\n';
    }

    cout << '\n' << "LETTER: ";

    cout << "ANS" << '\n';

    vector<char> letters = {'C', 'H', 'P', 'O','L', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I'};
    vector<pair<vector<vector<int>>, vector<vector<int>>>> patterns = {
        // Patterns for 'C'
        {{{3}, {0, 1}}, {{3}, {0}, {3}}},
        // Patterns for 'H'
        {{{3}, {1, 0}, {3}}, {{0, 1}, {3}, {0, 1}}},
        // Patterns for 'P'
        {{{3}, {0, 1, 0}, {0}}, {{3}, {0, 1}, {3}, {0}}},
        // Patterns for 'O'
        {{{3}, {0, 1}, {3}}, {{3}, {0, 1}, {3}}},
        // Patterns for 'L'
        {{{3}, {1}}, {{0},{3}}},
        // Multiple Patterns for 'I'
        {{{3}}, {{3}}},
        {{{0, 2}}, {{0, 2}}},
        {{{2}, {0}, {2}}, {{1, 0}, {2}}},
        {{{2}, {0}}, {{1}, {2}}},
        {{{2}, {1}}, {{2}, {1}}},
        {{{2}, {1}, {2}}, {{2}, {1, 0}}},
        {{{1}, {2}}, {{2}, {0}}},
        {{{1, 0}, {2}}, {{2}, {0}, {2}}},
        {{{2}, {1,0}, {2}}, {{2}, {1,0}, {2}}},
        {{{2}, {3}}, {{1}}},
        {{{3},{2},{3}}, {{1,0}}},
        {{{3}, {2}}, {{0}}},
        {{{0}}, {{2}, {3}}},
        {{{1, 0}}, {{2}, {3}, {2}}},
        {{{1}}, {{3}, {2}}},
    };

    for (size_t i = 0; i < 5; i++) {
        if (areEqual(cols, patterns[i].first) && areEqual(rows, patterns[i].second)) {
            cout << letters[i];
            return 0;
        }
    }

    if (!valid) {
        cout << 'X';
        return 0;
    }

    for (size_t i = 5; i < patterns.size(); i++) {
        if (areEqual(cols, patterns[i].first) && areEqual(rows, patterns[i].second)) {
            cout << letters[i];
            return 0;
        }
    }

    cout << 'X';
    return 0;
}
