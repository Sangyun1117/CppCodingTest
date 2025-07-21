#include <string>
#include <vector>
#include <stack>
using namespace std;

using state = pair<int,int>; //누적합, 현재인덱스

int solution(vector<int> numbers, int target) {
    int answer = 0;

    stack<state> s;
    
    s.push({numbers[0], 0});
    s.push({-numbers[0], 0});
    
    while(!s.empty()){
        state now = s.top(); s.pop();
        int nowValue = now.first;
        int nowIdx = now.second;
        if(nowIdx == numbers.size() - 1){
            if(nowValue == target)
                answer++;
        }else{
            s.push({nowValue + numbers[nowIdx+1], nowIdx+1});
            s.push({nowValue - numbers[nowIdx+1], nowIdx+1});
        }
    }
    
    return answer;
}
