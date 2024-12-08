#include<bits/stdc++.h>

using namespace std;

bool calculate(const vector<long long>& nums, long long target) {
    string target_string = to_string(target);
    unordered_set<long long> current;
    current.insert(nums[0]);

    for (int i = 1; i < nums.size(); i++) {
        unordered_set<long long> next;

        for (const auto& val : current) {
            long long add_result = val + nums[i];
            next.insert(add_result);

            long long multiply_result = val * nums[i];
            next.insert(multiply_result);

            string concatenate_result_string = to_string(val) + to_string(nums[i]);
            if (concatenate_result_string.size() <= target_string.size()) {
               long long concatenate_result = stoll(concatenate_result_string);
                next.insert(concatenate_result);
            } else {
                cout << "LONG" << ' ';
            }
        }

        current = move(next);
    }

    return current.find(target) != current.end();
}

int main() {
    ifstream file("input_1.txt");
    string line;

    long long total = 0;
    while (getline(file, line)) {
        int i = 0;

        long long target = 0;
        while (line[i] != ':') {
            target = target * 10 + (line[i] - '0');
            i++;
        }

        i += 2;

        vector<long long> nums;
        long long num = 0;
        while (i < line.size()) {
            if (line[i] == ' ') {
                nums.push_back(num);
                num = 0;
            } else {
                num = num * 10 + (line[i] - '0');
            }
            i++;
        }
        nums.push_back(num);

        if (calculate(nums, target)) total += target;
    }   
        
    cout << total;
    return 0;
}
