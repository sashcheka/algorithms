#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main() {
    ifstream file("input_1.txt");

    string stone;
    vector<string> stones;
    while (file >> stone) stones.push_back(stone);

    for (int blink = 0; blink < 25; blink++) {
        int n = stones.size();
        vector<string> temp;

        for (int i = 0; i < n; i++) {
            string stone = stones[i];
            if (stone == "0") {
                temp.push_back("1");
            } else if (stone.size() % 2 == 0) {
                int half = stone.size() / 2;
                string left_stone = stone.substr(0, half);
                string right_stone = stone.substr(half);

                int j = 0;
                while (right_stone[j] == '0') j++;
                if (j == right_stone.size()) right_stone = "0";
                else right_stone = right_stone.substr(j);

                temp.push_back(left_stone);
                temp.push_back(right_stone);
            } else {
                long long big_stone = stoll(stone) * 2024;
                temp.push_back(to_string(big_stone));
            }
        }

        stones = temp;
    }

    cout << stones.size();
    return 0;
}
