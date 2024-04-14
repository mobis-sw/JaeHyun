#include <bits/stdc++.h>
using namespace std;

int n;
int calc[20];
int buf_ans;
int cnt = 0;

void DFS(int pos, vector<int> V) {
    if(pos == n) {
        int add = 0;
        for(int i = 0; i < n; i++) {
            add += calc[i];
        }
        
        if(add == buf_ans)
            cnt++;
        
        return;
    }
    
    calc[pos] = V[pos];
    DFS(pos + 1, V);
    
    calc[pos] = -V[pos];
    DFS(pos + 1, V);
}

int solution(vector<int> numbers, int target) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int answer = 0;
    buf_ans = target;
    
    n = numbers.size();
    
    DFS(0, numbers);

    answer = cnt;
    
    return answer;
}
