#include <string>
#include <vector>
using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    
    int row = (num-1)/w; //층 번호
    int idx = (num-1)%w; //층 내 위치
    int col;
    int allRow = (n-1)/w; //총 층 수
    int allCol;
    int allIdx = (n-1)%w;
    
    if(row%2==0)
        col = idx;
    else
        col = w - 1 - idx;
    
    if(allRow%2==0){
        allCol = allIdx;
        answer = allRow-row;
        if(allCol >= col)
            ++answer;
    }
    else{
        allCol = w - 1 - allIdx;
        answer = allRow-row;
        if(allCol <= col)
            ++answer;
    }
    return answer;
}