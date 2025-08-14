#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Missaile{
public:
    Missaile(int s, int e){
        start = s;
        end = e;
    }    
    int start;
    int end;
    
    bool operator < (Missaile other){
        if(end != other.end)
            return end < other.end;
        else
            return start < other.start;
    }
};
int solution(vector<vector<int>> targets) {
    int answer = 0;
    vector<Missaile> newV;
    for(int i=0; i<targets.size(); ++i){
        for(int j=0; j<targets[i].size(); ++j){
            Missaile m(targets[i][0], targets[i][1]);
            newV.push_back(m);
        }
    }
    sort(newV.begin(), newV.end());
    
    vector<bool> isClear(newV.size(),false);
    for(int i=0; i<newV.size(); ++i){
        if(isClear[i])
            continue;
        int nowEnd = newV[i].end;
        for(int j=i; j<newV.size(); ++j){
            if(newV[j].start < nowEnd){
                isClear[j] = true;
            }
            else{
                break;
            }
        }
        ++answer;
    }
    return answer;
}