#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// This function returns a new string filled with the digits spelled out with letters in a given string (in order)
string findDigits(string);

int main(int argc, char **argv){

   ifstream input(argv[1]);
   string number;
   string word;
   string line;
   vector<char> digits;
   string digitsInWord;
   int sum = 0;

   while(getline(input, line)){
      // number and word is set to empty string each time a line is read.
      number = "";
      word = "";

      for(int i = 0; i < line.length(); i++){
        // if character is a digit then first appends all digits in word string to digits vector then the current digit.     
         if(isdigit(line[i])){
            digitsInWord = findDigits(word);
            for(auto elem : digitsInWord){
                digits.push_back(elem);
            }
            word = "";
            digits.push_back(line[i]);
         }
        // fills word string with all the character between previous digit and next digit.
         else{
            word += line[i];
         }
      }

      digitsInWord = findDigits(word);
      for(auto elem : digitsInWord){
        digits.push_back(elem);
      }
    
      // appends first and last digit in line to the empty number string.
      if(digits.size() != 0){
        number += digits[0];
        number += digits[digits.size() - 1];
      }
      else{
        number = "0";
      }
      // digits array needs to be cleared before another line is read.
      digits.clear();
      sum += stoi(number);
   }

   cout << "\nThe total sum is: " << sum << endl;
   input.close();
}
string findDigits(string word){
    map<int, string> digitOrdering;
    string digitsInString = "";
    vector<string> wdigits {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for (int i = 0; i < wdigits.size(); i++){
        if(word.find(wdigits[i]) != string::npos){
            digitOrdering[word.find(wdigits[i])] = to_string(i+1);
        }
    }
    for(int j = 0; j < word.length(); j++){
        if(digitOrdering.count(j)){
            digitsInString += digitOrdering[j];
        }
    }
    return digitsInString;
}