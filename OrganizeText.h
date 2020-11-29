#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#define INFINITY 1000000

class NeatText {
public:
    NeatText(const std::string& filename, int max);

    void line_sum();
    int line_cost(int i, int j);
    void compute_costs();
    void print();

private:
    int MAX;
    std::vector<std::string> user_input;
    std::vector<int> all_sums;
    std::vector<int> costs;
    std::vector<int> track;
    std::vector<int> print_list;
};

NeatText::NeatText(const std::string& filename, int max) {
    MAX = max;
    std::ifstream in;
    in.open(filename.c_str());
    std::string temp;
    while (in >> temp)
        user_input.push_back(temp);
    in.close();
    track.resize(user_input.size());
    all_sums.resize(user_input.size());
    costs.resize(user_input.size());
}

void NeatText::line_sum() {
    int sum = 0;
    for (int i = 0; i < user_input.size(); i++) {
        sum += user_input[i].length();
        all_sums[i] = i + sum;
    }
}

int NeatText::line_cost(int i, int j) {
    int num = MAX - all_sums[j] + all_sums[i] - user_input[i].length();
    if (num < 0) {
        return INFINITY;
    }
    if (j == user_input.size() - 1) {
        return 0;
    }

    return num * num * num;
}

void NeatText::compute_costs() {
    costs[0] = line_cost(0, 0);
    for (int j = 1; j < user_input.size(); j++) {
        costs[j] = INFINITY;
        for (int i = 0; i <= j; i++) {
            int cost;
            if (i == 0) {
                cost = line_cost(i, j);
            }
            else {
                cost = costs[i - 1] + line_cost(i, j);
            }
            if (cost < costs[j]) {
                costs[j] = cost;
                track[j] = i;
            }
        }
    }
}

void NeatText::print() {
    int i = track.size() - 1;
    print_list.push_back(i);
    while (track[i] != 0) {
        i = track[i] - 1;
        print_list.push_back(i);
    }
    int index = print_list.size() - 1;
    for (int j = 0; j < user_input.size(); j++) {
        if (j <= print_list[index]) {
            std::cout << user_input[j] << " ";
            continue;
        }
        std::cout << std::endl;
        std::cout << user_input[j] << " ";
        index--;
    }
}
