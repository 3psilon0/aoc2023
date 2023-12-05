#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

int getId(string);
bool checkValidity(string);

int main(int argc, char **argv){
    string line;
    int id;
    bool valid;
    int sum = 0;
    ifstream input(argv[1]);

    while(getline(input, line)){
        id = getId(line);
        valid = checkValidity(line);
        if(valid){
            sum += id;
        }
    }
    cout << sum << endl;
    input.close();
}

int getId(string game){
    string gameNum = game.substr(0, game.find(":"));
    string id = gameNum.substr(gameNum.find(" "), gameNum.length() - 1);
    return stoi(id);
}
bool checkValidity(string game){
    bool possible = 1;
    size_t pos;
    int number;
    string color;
    string gameScore;
    string indScore;

    istringstream gameScores(game.substr(game.find(":") + 1, game.length() - 1));
    
    while(getline(gameScores, gameScore, ';')){
        istringstream scores(gameScore);
        while(getline(scores, indScore, ',')){
            size_t pos = indScore.find(' ', 1);
            number = stoi(indScore.substr(1, pos));
            color = indScore.substr(pos + 1, indScore.length() - 1);

            switch(color.length()){
                case 3:
                    if(number > 12){
                        possible = 0;
                    }
                    break;
                case 4:
                    if(number > 14){
                        possible = 0;
                    }
                    break;
                case 5:
                    if(number > 13){
                        possible = 0;
                    }
                    break;
            }
        }
    }
    return possible;
}