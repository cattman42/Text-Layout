// Caleb Catt
// 2/20/2020 Turn in
// CMSC 510
// Text Layout Assignment
#include <iostream>
#include "OrganizeText.h"

int main(int argc, const char* argv[]) {
    std::cout << "Enter maximum characters per line: ";
    int max;
    std::cin >> max;

    NeatText T("Text_LayoutText.txt", max);
    T.line_sum();
    T.compute_costs();
    T.print();
    return 0;
}
