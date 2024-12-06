#include <bits/stdc++.h>
using namespace std;

struct Team {
    int hacked_servers = 0;
    int penalty_time = 0;
    map<char, int> failed_attempts;
};

int time_to_minutes(const string &start_time, const string &current_time) {
    int h1 = stoi(start_time.substr(0, 2));
    int m1 = stoi(start_time.substr(3, 2));
    int s1 = stoi(start_time.substr(6, 2));
    
    int h2 = stoi(current_time.substr(0, 2));
    int m2 = stoi(current_time.substr(3, 2));
    int s2 = stoi(current_time.substr(6, 2));
    
    int start_total = h1 * 3600 + m1 * 60 + s1;
    int current_total = h2 * 3600 + m2 * 60 + s2;
    
    int elapsed_seconds = current_total - start_total;
    if (elapsed_seconds < 0) {
        elapsed_seconds += 24 * 3600;
    }
    
    return elapsed_seconds / 60;
}

void solve() {
    string start_time;
    cin >> start_time;
    
    int n;
    cin >> n;
    
    map<string, Team> teams;
    
    cin.ignore();
    
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        
        // Извлечение данных из строки
        size_t name_start = line.find('"');
        size_t name_end = line.find('"', name_start + 1);
        string team_name = line.substr(name_start, name_end - name_start + 1);
        
        string current_time = line.substr(name_end + 2, 8);
        char server = line[name_end + 11];
        string result = line.substr(name_end + 13);
        
        int time_in_minutes = time_to_minutes(start_time, current_time);
        
        if (result == "ACCESSED") {
            teams[team_name].hacked_servers++;
            teams[team_name].penalty_time += time_in_minutes;
            teams[team_name].penalty_time += teams[team_name].failed_attempts[server] * 20; // штраф за неудачные попытки
        } else if (result == "DENIED" || result == "FORBIDEN") {
            teams[team_name].failed_attempts[server]++;
        }
    }
    
    vector<pair<string, Team>> sorted_teams(teams.begin(), teams.end());
    
    sort(sorted_teams.begin(), sorted_teams.end(), [](const pair<string, Team> &a, const pair<string, Team> &b) {
        if (a.second.hacked_servers != b.second.hacked_servers) {
            return a.second.hacked_servers > b.second.hacked_servers;
        }
        if (a.second.penalty_time != b.second.penalty_time) {
            return a.second.penalty_time < b.second.penalty_time;
        }
        return a.first < b.first;
    });
    
    int rank = 1;
    for (int i = 0; i < sorted_teams.size(); ++i) {
        if (i > 0 && 
            (sorted_teams[i].second.hacked_servers < sorted_teams[i-1].second.hacked_servers ||
             sorted_teams[i].second.penalty_time > sorted_teams[i-1].second.penalty_time)) {
            rank = i + 1;
        }
        cout << rank << " " << sorted_teams[i].first << " " << sorted_teams[i].second.hacked_servers 
             << " " << sorted_teams[i].second.penalty_time << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
