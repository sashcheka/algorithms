#include <bits/stdc++.h>
using namespace std;

// Function to trim leading and trailing whitespaces
string trim(const string &s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end = s.find_last_not_of(" \t\r\n");
    if (start == string::npos || end == string::npos)
        return "";
    return s.substr(start, end - start + 1);
}

// Function to split a string by delimiter and convert to long longegers
vector<long long> split_program(const string &s, char delimiter=',') {
    vector<long long> program;
    string token;
    stringstream ss(s);
    while (getline(ss, token, delimiter)) {
        token = trim(token);
        if (!token.empty()) {
            long long num = stoi(token);
            if (num < 0 || num > 7) {
                cerr << "Invalid program number: " << num << ". Must be between 0 and 7." << endl;
                exit(1);
            }
            program.push_back(num);
        }
    }
    return program;
}

int main() {
    // Initialize registers
    long long A = 0, B = 0, C = 0;
    string line;

    // Read Register A
    getline(cin, line);
    size_t pos = line.find(':');
    if (pos != string::npos) {
        A = stoll(trim(line.substr(pos + 1)));
    } else {
        cerr << "Invalid input format for Register A." << endl;
        return 1;
    }

    // Read Register B
    getline(cin, line);
    pos = line.find(':');
    if (pos != string::npos) {
        B = stoll(trim(line.substr(pos + 1)));
    } else {
        cerr << "Invalid input format for Register B." << endl;
        return 1;
    }

    // Read Register C
    getline(cin, line);
    pos = line.find(':');
    if (pos != string::npos) {
        C = stoll(trim(line.substr(pos + 1)));
    } else {
        cerr << "Invalid input format for Register C." << endl;
        return 1;
    }
    getline(cin, line);

    // Read Program
    getline(cin, line);
    pos = line.find(':');
    vector<long long> program;
    if (pos != string::npos) {
        string program_str = trim(line.substr(pos + 1));
        program = split_program(program_str);
    } else {
        cerr << "Invalid input format for Program." << endl;
        return 1;
    }

    // Simulation variables
    size_t ip = 0; // Instruction polong longer
    vector<long long> outputs;

    // Define operand types per opcode
    // true for combo, false for literal
    // Opcodes 0,2,4,5,6,7 use combo operands
    // Opcodes 1,3 use literal operands
    bool operand_is_combo[8] = {true, false, true, false, true, true, true, true};

    while (ip < program.size()) {
        if (ip + 1 >= program.size()) {
            // No operand available; halt
            break;
        }
        long long opcode = program[ip];
        long long operand = program[ip + 1];
        // Debug: prlong long current instruction
        // cout << "IP: " << ip << ", Opcode: " << opcode << ", Operand: " << operand << endl;

        // Determine operand value based on operand type
        long long operand_value = 0;
        if (operand_is_combo[opcode]) {
            // Combo operand
            if (operand >= 0 && operand <=3) {
                operand_value = operand;
            } else if (operand ==4) {
                operand_value = A;
            } else if (operand ==5) {
                operand_value = B;
            } else if (operand ==6) {
                operand_value = C;
            } else {
                cerr << "Invalid combo operand: " << operand << endl;
                return 1;
            }
        } else {
            // Literal operand
            operand_value = operand;
        }

        // Execute instruction based on opcode
        bool jumped = false;
        switch(opcode) {
            case 0: { // adv
                // denominator is 2^operand_value
                double denominator = pow(2.0, (double)operand_value);
                if (denominator == 0) {
                    cerr << "Division by zero in adv instruction." << endl;
                    return 1;
                }
                long long result = static_cast<long long>(A / denominator);
                A = result;
                break;
            }
            case 1: { // bxl
                // operand is literal
                B = B ^ operand_value;
                break;
            }
            case 2: { // bst
                // operand_value modulo 8
                long long value = operand_value % 8;
                B = value;
                break;
            }
            case 3: { // jnz
                if (A != 0) {
                    // Jump to operand_value
                    if (operand_value < 0 || (size_t)operand_value >= program.size()) {
                        // Jumping to beyond the program will cause halt
                        ip = operand_value;
                        jumped = true;
                    } else {
                        ip = operand_value;
                        jumped = true;
                    }
                }
                break;
            }
            case 4: { // bxc
                // Calculate B XOR C and store in B. Operand is ignored.
                B = B ^ C;
                break;
            }
            case 5: { // out
                // operand_value modulo 8
                long long out_val = operand_value % 8;
                outputs.push_back(out_val);
                break;
            }
            case 6: { // bdv
                // denominator is 2^operand_value
                double denominator = pow(2.0, (double)operand_value);
                if (denominator == 0) {
                    cerr << "Division by zero in bdv instruction." << endl;
                    return 1;
                }
                long long result = static_cast<long long>(A / denominator);
                B = result;
                break;
            }
            case 7: { // cdv
                // denominator is 2^operand_value
                double denominator = pow(2.0, (double)operand_value);
                if (denominator == 0) {
                    cerr << "Division by zero in cdv instruction." << endl;
                    return 1;
                }
                long long result = static_cast<long long>(A / denominator);
                C = result;
                break;
            }
            default:
                cerr << "Invalid opcode: " << opcode << endl;
                return 1;
        }

        if (!jumped) {
            ip += 2;
        }
    }

    // Prepare output
    string output_str = "";
    for (size_t i = 0; i < outputs.size(); ++i) {
        output_str += to_string(outputs[i]);
        if (i != outputs.size() -1)
            output_str += ",";
    }

    // Prlong long the output
    cout << output_str << endl;

    return 0;
}
