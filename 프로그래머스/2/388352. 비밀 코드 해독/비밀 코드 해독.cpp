#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(int n, int start, vector<int>&current, vector<vector<int>>& q, vector<int>& ans)
{
    if(current.size() == 5)
    {
        for(int i=0; i<q.size(); ++i)
        {
            int count = 0;
            for(int numC : current)
            {
                for(int numQ : q[i])
                {
                    if(numC==numQ)
                    {
                        ++count;
                    }
                }
            }
            if(count != ans[i])
            {
                return;
            }  
        }
        ++answer;
        return;
    }
    
    for(int i=start; i<=n; ++i)
    {
        current.push_back(i);
        dfs(n, i+1, current, q, ans);
        current.pop_back();
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    
    vector<int> current;
    dfs(n, 1, current, q, ans);

    return answer;
}