//
// Created by ormsb on 11/30/2023.
//
#include "day1.h"

int findFirstDigit(const std::string& str) {
    for (char ch : str) {
        if (isdigit(ch)) {
            return ch - '0';
        }
    }
    return -1;  // No digit found
}

int findLastDigit(const std::string& str) {
    for (auto it = str.rbegin(); it != str.rend(); ++it) {
        if (isdigit(*it)) {
            return *it - '0';
        }
    }
    return -1; // No digit found
}

int day1() {
    const std::string filename = "../day1.txt";
    std::ifstream in(filename);
    std::string buffer;

    std::vector<int> numPairs;

    if (in.is_open()) {
        while (std::getline(in, buffer)) {
            int firstNum = findFirstDigit(buffer);
            int lastNum = findLastDigit(buffer);

            if (firstNum == -1 || lastNum == -1) {
                // No digits found in this line
                // Not possible but might as well account for
                continue;
            }

            numPairs.push_back((firstNum * 10) + lastNum);
        }
        in.close();

        int total = 0;
        for (int num : numPairs) {
            total += num;
        }

        std::cout << "Part 1 - Sum of all calibration values: " << total << std::endl;

    } else {
        std::cout << "Error opening file: " << filename << std::endl;
    }

    return 0;
}

