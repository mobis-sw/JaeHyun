#include <bits/stdc++.h>
using namespace std;

bool visited[200];

void DFS(int num, vector<vector<int>> V) { 
    visited[num] = 1;
    
    for(int i = 0; i < V[num].size(); i++) {
        if(V[num][i] == 1 && visited[i] == 0) { 
            DFS(i, V);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int answer = 0;
    
    for(int i = 0; i < computers.size(); i++) {
        for(int j = 0; j < computers[i].size(); j++) {
            if(computers[i][j] == 1 && visited[j] == 0) {
                answer++;
                
                DFS(j, computers);
            }
        }
    }
    
    return answer;
}
