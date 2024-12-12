#include <bits/stdc++.h>

using namespace std;

const vector<pair<int, int>> directions = { {-1,0}, {1,0}, {0,-1}, {0,1} };

int main(){
    ifstream file("input_1.txt");

    vector<string> grid;
    string line;
    while(getline(file, line)){
        if(line.empty()) break;
        grid.push_back(line);
    }

    int N = grid.size();
    if(N == 0){
        cout << 0;
        return 0;
    }
    int M = grid[0].size();

    // Initialize visited grid
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    long long total_price = 0;

    // Iterate through each cell
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!visited[i][j]){
                // Start BFS
                char plant = grid[i][j];
                queue<pair<int, int>> q;
                q.push({i,j});
                visited[i][j] = true;
                vector<pair<int, int>> region_cells;
                region_cells.emplace_back(i,j);

                while(!q.empty()){
                    pair<int, int> current = q.front(); q.pop();
                    int x = current.first;
                    int y = current.second;

                    for(auto &dir: directions){
                        int nx = x + dir.first;
                        int ny = y + dir.second;
                        if(nx >=0 && nx < N && ny >=0 && ny < M && !visited[nx][ny] && grid[nx][ny] == plant){
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                            region_cells.emplace_back(nx, ny);
                        }
                    }
                }

                // Calculate area
                int area = region_cells.size();

                // Initialize fence boundaries
                // fence_horizontal[row][col] represents fence between row-1 and row at column col
                // fence_vertical[row][col] represents fence between col-1 and col at row row
                // Initialize as empty
                // Using vector<vector<bool>> for fence_horizontal and fence_vertical
                // Size: fence_horizontal -> (N+1) x M
                //        fence_vertical -> N x (M+1)
                vector<vector<bool>> fence_horizontal(N+1, vector<bool>(M, false));
                vector<vector<bool>> fence_vertical(N, vector<bool>(M+1, false));

                // Mark fence boundaries
                for(auto &[x, y] : region_cells){
                    // Top fence
                    if(x == 0 || grid[x-1][y] != plant){
                        fence_horizontal[x][y] = true;
                    }
                    // Bottom fence
                    if(x == N-1 || grid[x+1][y] != plant){
                        fence_horizontal[x+1][y] = true;
                    }
                    // Left fence
                    if(y == 0 || grid[x][y-1] != plant){
                        fence_vertical[x][y] = true;
                    }
                    // Right fence
                    if(y == M-1 || grid[x][y+1] != plant){
                        fence_vertical[x][y+1] = true;
                    }
                }

                // Count horizontal fence segments
                int sides = 0;
                for(int row=0; row<=N; row++){
                    int j = 0;
                    while(j < M){
                        if(fence_horizontal[row][j]){
                            sides++;
                            while(j < M && fence_horizontal[row][j]){
                                j++;
                            }
                        }
                        else{
                            j++;
                        }
                    }
                }

                // Count vertical fence segments
                for(int col=0; col<=M; col++){
                    int i = 0;
                    while(i < N){
                        if(fence_vertical[i][col]){
                            sides++;
                            while(i < N && fence_vertical[i][col]){
                                i++;
                            }
                        }
                        else{
                            i++;
                        }
                    }
                }

                // Calculate price for this region
                long long price = (long long)area * (long long)sides;
                total_price += price;
            }
        }
    }

    cout << total_price;
}
