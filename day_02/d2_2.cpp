#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <array>

using namespace std;

// Returns the id of the game
int getId(string);
// Returns an array with minimum number of red, blue and green cubes needed to play the game
array<int, 3> getMinNumbers(string);

int main(int argc, char **argv){
    string line;
    int id;
    // min_colors_l is minimum number of cubes per line
    array <int, 3> min_colors_l;
    int pow = 1;
    int sum = 0;
    ifstream input(argv[1]);

    while(getline(input, line)){
        id = getId(line);
        min_colors_l = getMinNumbers(line);
        for(int i = 0; i < 3; i++){
            pow *= min_colors_l[i];
        }
        sum += pow;
        pow = 1;
    }
    cout << sum << endl;
    input.close();
}

int getId(string game){
    string gameNum = game.substr(0, game.find(":"));
    string id = gameNum.substr(gameNum.find(" "), gameNum.length() - 1);
    return stoi(id);
}
array <int, 3> getMinNumbers(string game){
    // min_colors_g is minimum number of cubes per game
    array<int, 3> min_colors_g = {0, 0, 0};
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
                // Red
                case 3:
                    if(number > min_colors_g[0]){
                        min_colors_g[0] = number;
                    }
                    break;

                // Blue
                case 4:
                    if(number > min_colors_g[1]){
                        min_colors_g[1] = number;
                    }
                    break;

                // Green
                case 5:
                    if(number > min_colors_g[2]){
                        min_colors_g[2] = number;
                    }
                    break;
            }
        }
    }
    return min_colors_g;
}