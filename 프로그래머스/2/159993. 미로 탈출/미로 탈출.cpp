#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
using Pos = pair<int, int>;

int solution(vector<string> maps) {
    Pos start;
    Pos lever;
    Pos end;
    int xLen = maps.size();
    int yLen = maps[0].size();
    
    for(int i =0; i<maps.size(); ++i){
        for(int j=0; j<maps[i].size(); ++j){
            if(maps[i][j] == 'S'){
                start.first = i;
                start.second = j;
            }
            else if(maps[i][j] == 'E'){
                end.first = i;
                end.second = j;
            }
            else if(maps[i][j] == 'L'){
                lever.first = i;
                lever.second = j;
            }
        }
    }
    
    queue<Pos> q;
    q.push(start);
    vector<vector<bool>> visited(xLen,vector<bool>(yLen, false));
    int count = 0;
    bool checkLever = false;
    visited[start.first][start.second] = true;
    while(!q.empty()){
        Pos now = q.front(); q.pop();
        
        if(now.first==lever.first && now.second==lever.second){
            checkLever = true;
            break;
        }
        for(int i=0; i<4; ++i){
            int nextY = now.first + dy[i];
            int nextX = now.second + dx[i];
            if(nextY<0||nextY>=maps.size()||nextX<0||nextX>=maps[0].size())
                continue;
            if(visited[nextY][nextX]||maps[nextY][nextX]=='X')
                continue;
            q.push({nextY, nextX});
            visited[nextY][nextX] = true;
            count++;
        }
    }
    if(!checkLever)
        return -1;
    
    bool checkEnd = false;
    queue<Pos> q2;
    q2.push(lever);
    vector<vector<bool>> visited2(xLen,vector<bool>(yLen, false));
    visited2[lever.first][lever.second] = true;
    
    while(!q2.empty()){
        Pos now = q2.front(); q2.pop();
        
        if(now.first==end.first && now.second==end.second){
            checkEnd = true;
            break;
        }
        for(int i=0; i<4; ++i){
            int nextY = now.first + dy[i];
            int nextX = now.second + dx[i];

            if(nextY<0||nextY>=maps.size()||nextX<0||nextX>=maps[0].size())
                continue;
            if(visited2[nextY][nextX]||maps[nextY][nextX]=='X')
                continue;
            q2.push({nextY, nextX});
            visited2[nextY][nextX] = true;
            count++;
        }
    }

    if(!checkEnd)
        return -1;
    else{
        return count;
    }
}

