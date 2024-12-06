#include <iostream>
#include <vector>

using namespace std;

vector<int> processClues(int n, const vector<int>& weights, int m, int k, const vector<int>& starts) {
    vector<int> maxLeft(n, 0);
    
    // Предварительно вычисляем максимально левую позицию для каждой улики
    for (int i = 0; i < n; ++i) {
        int j = i;
        while (j > 0 && weights[j - 1] <= weights[j]) {
            j--;
        }
        maxLeft[i] = j;
    }
    
    vector<int> results;
    
    // Выполняем каждый запрос
    for (int start : starts) {
        int pos = start - 1;  // Переходим к индексации с 0
        int currentWeight = weights[pos];
        int count = 0;
        
        // Ограничение на количество перемещений `k`
        while (pos > maxLeft[start - 1] && weights[pos - 1] <= currentWeight) {
            if (weights[pos - 1] == currentWeight) {
                count++;
                if (count > k) break;
            }
            pos--;
        }
        
        results.push_back(pos + 1);  // Возвращаем к индексации с 1
    }
    
    return results;
}

int main() {
    int n, m, k;
    cin >> n;
    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }
    
    cin >> m >> k;
    vector<int> starts(m);
    for (int i = 0; i < m; ++i) {
        cin >> starts[i];
    }
    
    vector<int> results = processClues(n, weights, m, k, starts);
    
    // Выводим результат
    for (int result : results) {
        cout << result << " ";
    }
    cout << endl;
    
    return 0;
}
