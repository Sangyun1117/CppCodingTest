#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int xLen;
int yLen;
struct Pos{
    int y;
    int x;
    int count;
};

int bfs(Pos start, Pos end, vector<string>& maps){
    queue<Pos> q;
    q.push(start);
    vector<vector<bool>> visited(yLen, vector<bool>(xLen, false));
    
    while(!q.empty()){
        Pos now = q.front(); q.pop();
        if(now.x==end.x && now.y==end.y){
            return now.count;
        }
        
        for(int i=0; i<4; ++i){
            int nextY = now.y + dy[i];
            int nextX = now.x + dx[i];
            
            if(nextY<0||nextY>=yLen||nextX<0||nextX>=xLen)
                continue;
            if(visited[nextY][nextX] || maps[nextY][nextX] == 'X')
                continue;
            
            visited[nextY][nextX] = true;
            q.push({nextY, nextX, now.count + 1});
        }
    }
    return -1;
}

int solution(vector<string> maps) {
    Pos start;
    Pos lever;
    Pos end;
    
    yLen = maps.size();
    xLen = maps[0].size();
    
    for(int i =0; i<yLen; ++i){
        for(int j=0; j<xLen; ++j){
            if(maps[i][j] == 'S'){
                start = {i, j, 0};
            }
            else if(maps[i][j] == 'E'){
                end = {i, j, 0};
            }
            else if(maps[i][j] == 'L'){
                lever = {i, j, 0};
            }
        }
    }
    int r1 = bfs(start, lever, maps);
    if(r1==-1)
        return -1;
    int r2 = bfs(lever, end, maps);
    if(r2==-1)
        return -1;
    return r1+r2;
}

