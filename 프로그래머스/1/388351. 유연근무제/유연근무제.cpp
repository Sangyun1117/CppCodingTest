#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    for(int i=0; i<schedules.size(); ++i){
        int dream = schedules[i];
        int realDreamTime = (dream/100)*60 + (dream%100);
        int count = 0;
        for(int j=0; j<timelogs[i].size(); ++j){
            if(7-startday == j || 6-startday==j)
                continue; //주말은 제외함
            if(6-startday<0 && j==6)
                continue;
            int current = timelogs[i][j];
            int realCurrentTime = (current/100)*60 + (current%100);
            if(realCurrentTime <= realDreamTime + 10){
                ++count;
            }
        }
        if(count == 5)
            ++answer;
    }

    return answer;
}