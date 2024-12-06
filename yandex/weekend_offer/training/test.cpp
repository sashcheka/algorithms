#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

// Функция для вычисления расстояния по манхэттенской метрике
int manhattan_distance(pair<int, int> city1, pair<int, int> city2) {
    return abs(city1.first - city2.first) + abs(city1.second - city2.second);
}

int bfs_min_steps(int n, vector<pair<int, int>>& cities, int k, int start, int end) {
    // Очередь для BFS: (номер города, количество шагов)
    queue<pair<int, int>> q;
    q.push({start, 0});

    // Массив для отслеживания посещенных городов
    vector<bool> visited(n, false);
    visited[start] = true;

    while (!q.empty()) {
        int current_city = q.front().first;
        int steps = q.front().second;
        q.pop();

        // Если достигли конечного города
        if (current_city == end) {
            return steps;
        }

        // Проверяем достижимость каждого города из текущего
        for (int next_city = 0; next_city < n; ++next_city) {
            if (!visited[next_city]) {
                int distance = manhattan_distance(cities[current_city], cities[next_city]);
                if (distance <= k) {  // Если расстояние не превышает k, добавляем в очередь
                    visited[next_city] = true;
                    q.push({next_city, steps + 1});
                }
            }
        }
    }

    // Если путь не найден
    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> cities(n);
    for (int i = 0; i < n; ++i) {
        cin >> cities[i].first >> cities[i].second;
    }

    int k;
    cin >> k;

    int start, end;
    cin >> start >> end;

    // Переход к нумерации с 0 для удобства
    start--; 
    end--;

    int result = bfs_min_steps(n, cities, k, start, end);
    cout << result << endl;

    return 0;
}
