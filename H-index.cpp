#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int n = citations.size();
    
    int num = 0;
    
    sort(citations.begin(), citations.end(), greater<int>());
    
    for(int i = 0; i < n; i++) {
        if(citations[i] >= i + 1) {
            num++;
        }
        else {
            break;
        }
    }
    
    return num;
}
