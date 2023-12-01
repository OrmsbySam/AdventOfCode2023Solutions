//
// Created by ormsb on 11/30/2023.
//
#include "day1.h"

int day1() {
    std::string filename = "../day1.txt";
    std::ifstream in(filename);
    std::string buffer;

    std::vector<int> numPairs;
    std::regex pattern("\\d");


    if (in.is_open()) {
        while (std::getline(in, buffer)) {
            std::sregex_iterator iterator(buffer.begin(), buffer.end(), pattern);
            std::sregex_iterator end;

            if(iterator == end) {
                // NO DIGITS FOUND
            }

            int firstNum = std::stoi(iterator->str());
            int lastNum;

            for (; iterator != end; ++iterator) {
                lastNum = std::stoi(iterator->str());
            }
//            std::cout << buffer << std::endl;
//            std::cout << "First Num: " << firstNum * 10 << std::endl;
//            std::cout << "Last Num: " << lastNum << std::endl;
            numPairs.push_back((firstNum * 10) + lastNum);
        }
        in.close();

        int total = 0;
        for(int num : numPairs) {
            total += num;
        }

        std::cout << "Sum of all calibration values: " << total; //55488



    } else {
        std::cout << "Error opening file: " << filename << std::endl;
    }

    return 0;
}

