#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <unordered_map>
#include <array>
#include <utility>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

/*
    We'll represent each cell by an integer id (row * width + col).

    Steps:
    1) Read input, find start and end cells.
    2) BFS from start to get distFromStart[] (normal path).
    3) BFS from end to get distToEnd[] (normal path).
    4) For each cell c, run BFS that can pass through walls up to 20 steps
       to discover possible cheat-end cells r. Record the best time saved
       for (c, r).
    5) Count how many have >= 50 (or 100, depending on your puzzle) saved.
*/

// Directions for up, down, left, right
static const vector<pair<int,int>> DIRS = {
    {1,0}, {-1,0}, {0,1}, {0,-1}
};

// Convert (r,c) -> single index
inline int toID(int r, int c, int cols) {
    return r * cols + c;
}

// Check if within grid bounds
bool validCell(int r, int c, int n, int m) {
    return (r >= 0 && r < n && c >= 0 && c < m);
}

// Standard BFS on the normal track (walls blocked).
// dist[] is sized n*m.  We do BFS from (startR, startC).
// 'grid' is a 2D array of chars, with '#' for walls.
void bfsNormalTrack(int startR, int startC,
                    const vector<vector<char>> &grid,
                    vector<int> &dist) 
{
    int n = grid.size();
    int m = grid[0].size();

    fill(dist.begin(), dist.end(), INT_MAX);

    queue<pair<int,int>> q;
    dist[toID(startR, startC, m)] = 0;
    q.push({startR, startC});

    while(!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        int curDist = dist[toID(r, c, m)];

        for(auto &d: DIRS) {
            int nr = r + d.first;
            int nc = c + d.second;
            if(!validCell(nr, nc, n, m)) continue;
            if(grid[nr][nc] == '#') continue; // can't pass walls in normal BFS
            int idx = toID(nr, nc, m);

            if(dist[idx] > curDist + 1) {
                dist[idx] = curDist + 1;
                q.push({nr, nc});
            }
        }
    }
}

// BFS that can pass through walls for up to 20 steps.
// We keep track of (r, c, used) = (row, col, how many walls used so far).
// The array cheatLen[] we use here to store the BFS "distance" ignoring walls 
// (i.e., how many steps total from (startR,startC)), but you also need 
// to ensure we don't exceed 20 wall-passes. 
void bfsCheating(int startR, int startC,
                 const vector<vector<char>> &grid,
                 vector<int> &cheatLen) 
{
    int n = grid.size();
    int m = grid[0].size();

    // We'll store in cheatLen[] the number of BFS steps from (startR,startC)
    // ignoring walls. We'll keep a separate structure "wallUsed" 
    // to track how many walls we've passed so far.
    fill(cheatLen.begin(), cheatLen.end(), INT_MAX);

    // We'll store state as (row, col, stepsSoFar, wallsUsed).
    // BFS ensures the first time we set cheatLen[r,c] is the minimal # of steps.
    struct State {
        int r, c;       // position
        int distSoFar;  // how many moves from start
        int wallsUsed;
    };

    queue<State>q;
    // At the start, 0 distance traveled, 0 walls used
    cheatLen[toID(startR, startC, m)] = 0;
    q.push({startR, startC, 0, 0});

    while(!q.empty()) {
        auto st = q.front(); 
        q.pop();

        int r  = st.r;
        int c  = st.c;
        int d  = st.distSoFar; 
        int wU = st.wallsUsed;

        for(auto &dir : DIRS){
            int nr = r + dir.first;
            int nc = c + dir.second;
            if(!validCell(nr, nc, n, m)) continue;

            int newWallsUsed = wU + (grid[nr][nc] == '#' ? 1 : 0);
            if(newWallsUsed > 20) {
                // Can't exceed 20 walls
                continue;
            }
            int idx = toID(nr, nc, m);

            // The BFS distance ignoring walls is d + 1
            // If cheatLen[idx] > d+1, we found a better path
            if(cheatLen[idx] > d + 1) {
                cheatLen[idx] = d + 1;
                q.push({nr, nc, d + 1, newWallsUsed});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read the input from a file or stdin.
    // Here, we assume "test_1.txt" has lines that match the example.
    ifstream file("input_1.txt");
    if(!file.is_open()) {
        cerr << "Could not open test_1.txt\n";
        return 1;
    }

    vector<string> lines;
    string line;
    while(getline(file, line)) {
        // skip empty lines if any, or you can store them
        if(!line.empty()) {
            lines.push_back(line);
        }
    }
    file.close();

    // Build the grid as vector<vector<char>>
    // (Alternatively, you can keep it as vector<string>.)
    int n = (int)lines.size();
    if(n == 0) {
        cerr << "Empty input.\n";
        return 1;
    }
    int m = (int)lines[0].size();

    vector<vector<char>> grid(n, vector<char>(m));
    for(int r = 0; r < n; r++) {
        for(int c = 0; c < m; c++) {
            grid[r][c] = lines[r][c];
        }
    }

    // Find S and E
    int startR=-1, startC=-1, endR=-1, endC=-1;
    for(int r = 0; r < n; r++) {
        for(int c = 0; c < m; c++) {
            if(grid[r][c] == 'S') {
                startR = r; 
                startC = c;
            }
            if(grid[r][c] == 'E') {
                endR = r; 
                endC = c;
            }
        }
    }

    if(startR < 0 || endR < 0) {
        cerr << "Could not find S or E in the grid.\n";
        return 1;
    }

    // Prepare distance vectors
    vector<int> distFromStart(n*m), distToEnd(n*m);

    // BFS from S
    bfsNormalTrack(startR, startC, grid, distFromStart);
    // BFS from E
    bfsNormalTrack(endR, endC, grid, distToEnd);

    // The normal distance from S->E (no cheat):
    int distNoCheat = distFromStart[toID(endR, endC, m)];
    if(distNoCheat == INT_MAX) {
        cerr << "No path from S to E in normal BFS?\n";
        // Might be valid if puzzle allows no path, but typically not.
        return 1;
    }

    // We'll store best time saved for each (startCell, endCell).
    // key = ( (long long)startCell << 32 ) ^ endCell
    // value = max time saved for that cheat pair
    unordered_map<long long, int> bestCheat; 
    bestCheat.reserve(n*m);
    bestCheat.max_load_factor(0.7f);

    // For each cell c that is reachable in normal BFS,
    // run the BFS that can pass through walls up to 20 steps 
    // to find possible "cheat exit" cells r.
    vector<int> cheatLen(n*m); // re-used on each iteration

    for(int rr = 0; rr < n; rr++){
        for(int cc = 0; cc < m; cc++){
            int cIdx = toID(rr, cc, m);

            // If we cannot reach (rr,cc) in normal BFS, skip
            if(distFromStart[cIdx] == INT_MAX) {
                continue;
            }

            // BFS that can pass up to 20 walls, from (rr, cc)
            bfsCheating(rr, cc, grid, cheatLen);

            // Now see which cells (x, y) are reachable
            for(int x = 0; x < n; x++) {
                for(int y = 0; y < m; y++) {
                    int r2Idx = toID(x, y, m);
                    // If cheatLen[r2Idx] is still INT_MAX, not reachable with <=20 walls
                    if(cheatLen[r2Idx] == INT_MAX) {
                        continue;
                    }

                    // We can only exit cheat mode if it's a valid track cell
                    // i.e. '.' or 'S' or 'E'
                    if(grid[x][y] == '#') {
                        continue;
                    }

                    // timeWithCheat:
                    //   = distFromStart[cIdx]    // normal path from S to (rr, cc)
                    //   + cheatLen[r2Idx]       // BFS steps ignoring walls from (rr,cc) to (x,y)
                    //   + distToEnd[r2Idx]      // normal path from (x,y) to E
                    //
                    // We assume cheatLen[r2Idx] is the # of moves ignoring walls (the BFS distance).
                    int timeWithCheat = distFromStart[cIdx]
                                      + cheatLen[r2Idx]
                                      + distToEnd[r2Idx];

                    int saved = distNoCheat - timeWithCheat;
                    if(saved <= 0) {
                        continue; 
                    }

                    // Build a 64-bit key
                    long long key = ((long long)cIdx << 32) ^ (long long)r2Idx;
                    if(!bestCheat.count(key)) {
                        bestCheat[key] = saved;
                    } else {
                        bestCheat[key] = max(bestCheat[key], saved);
                    }
                }
            }
        }
    }

    // Finally, count how many cheats save at least 50 picoseconds
    // (or 100, depending on your puzzle).
    int ans = 0;
    for(auto &kv : bestCheat) {
        if(kv.second >= 100) {
            ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}
