#include <bits/stdc++.h>
using namespace std;

bool compare (int a, int b) {
    string s1 = to_string(a);
    string s2 = to_string(b);
    
    if(s1 + s2 > s2 + s1) {
        return true;
    }
    else
        return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), compare);
    
    for(auto i : numbers) {
        answer += to_string(i);
    }
    if(answer < "1")
        return "0";
    else
        return answer;
}
