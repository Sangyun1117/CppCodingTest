#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    //초기값
    long currentNum = 0;
    for(int i=0; i<p.length(); i++){
        long multifly = static_cast<long>(pow(10,p.length() - i - 1));
        currentNum += multifly*(t[i] - '0');
    }
    if(currentNum <= stol(p))
        ++answer;
    
    int startP = 0;
    int endP = p.length();
    
    while(endP < t.length()){
        currentNum -= (t[startP++] - '0') * static_cast<long>(pow(10,p.length() - 1));
        currentNum *= 10;
        currentNum += t[endP++] - '0';
        if(currentNum <= stol(p))
            ++answer;
    }
    return answer;
}