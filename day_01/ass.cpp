#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::string strip_string(std::string);
void replace_words_digits(std::string&);

int main(int argc, char const* argv[])
{
    std::ifstream calibration_value("input.txt", std::ios::out);

    std::string str;
    std::string strip_str;
    int sum = 0;
    int i = 1;

    while (getline(calibration_value, str)) {
        replace_words_digits(str);
        strip_str = strip_string(str);
        sum += (int)(strip_str.at(0) - '0') * 10 + (int)(strip_str.at(strip_str.length() - 1) - '0');
        i++;
    }

    calibration_value.close();

    std::cout << sum << std::endl;

    return 0;
}

// strips out all non digit character
std::string strip_string(std::string str)
{
    std::string out;
    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str[i])) {
            out += str[i];
        }
    }

    return out;
}

// replace words with number with the following format
// one -> o1e
// five -> f5e
// eight -> e8t
// this handles strings like threeightwo'
// the possible eccess characters will be stripped out by
// strip_string function
void replace_words_digits(std::string& str)
{
    std::vector<std::string> s = {"one",
                                  "two",
                                  "three",
                                  "four",
                                  "five",
                                  "six",
                                  "seven",
                                  "eight",
                                  "nine"};

    for (int i = 0; i < s.size(); i++) {
        while (str.find(s.at(i)) != std::string::npos) {
            str.replace(str.find(s.at(i)), s.at(i).length(), s.at(i).at(0) + std::to_string(i + 1) + s.at(i).at(s.at(i).length() - 1));
        }
    }
}