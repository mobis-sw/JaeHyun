#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> V;
    int result = INT_MIN;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        V.push_back(num);
    }

    int st = 0;
    int en = m - 1;
    
    int add = 0;
    for(int i = 0; i < m; i++) {
        add += V[i];
    }

    while(en < n) {
        result = max(add, result);

        add -= V[st++];
        add += V[++en];
    }

    cout << result;
}
