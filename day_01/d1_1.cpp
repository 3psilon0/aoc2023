#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char **argv){

   ifstream input(argv[1]);
   string number;
   string line;
   vector<char> digits;
   int sum = 0;

   while(getline(input, line)){
      // number is set to empty string each time a line is read.
      number = "";

      for(int i = 0; i < line.length(); i++){
         if(isdigit(line[i])){
            digits.push_back(line[i]);
         }
      }
      
      // appends first and last digit in line to the empty string.
      number += digits[0];
      number += digits[digits.size() - 1];
      // digits array needs to be cleared before another line is read.
      digits.clear();
      sum += stoi(number);
   }

   cout << "\nThe total sum is: " << sum << endl;
   input.close();
}