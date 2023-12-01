//
// Created by ormsb on 11/30/2023.
//
#include "day1.h"

int findDigits(const std::string& str) {
    int firstDigit = -1;
    int lastDigit = -1;

    for(char ch : str) {
        if(isdigit(ch)) {
            if(firstDigit == -1) {
                firstDigit = ch - '0';
            }
            lastDigit = ch - '0';
        }
    }

    return (firstDigit != -1 && lastDigit != -1) ? (firstDigit * 10 + lastDigit) : -1;
}

int day1Part1() {
    const std::string filename = "../day1.txt";
    std::ifstream in(filename);
    std::string buffer;
    int total = 0;

    if(in.is_open()) {
        while(std::getline(in, buffer)) {
            int numPair = findDigits(buffer);

            if(numPair != -1) {
                total += numPair;
            }
        }
        in.close();
        std::cout << "Part 1 - Sum of all calibration values: " << total << std::endl;
    } else {
        std::cout << "Day 1 - Part 1 - Error opening file: " << filename << std::endl;
    }

    return 0;
}

int day1Part2() {
    const std::string filename = "../day1.txt";
    std::ifstream in(filename);
    std::string buffer;

    int total = 0;

    if(in.is_open()) {
        while(std::getline(in, buffer)) {

        }
        in.close();
        std::cout << "Part 2 - Sum of all calibration values: " << total << std::endl;
    } else {
        std::cout << "Day 1 - Part 1 - Error opening file: " << filename << std::endl;
    }

    return 0;
}


