#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer;
    int x = 0;
    int y = 0;
    int maxX = board[0]/2;
    int maxY = board[1]/2;
    int minX = (-1) * board[0]/2;
    int minY = (-1) * board[1]/2;
    for(string line : keyinput){
        if(line == "up" && y <maxY ){
            y++;
        } else if(line == "down" && y > minY){
            y--;
        }else if(line =="left" && x > minX){
            x--;
        }else if(line == "right" && x < maxX )
            x++;
    }
    answer.push_back(x);
    answer.push_back(y);
    return answer;
}