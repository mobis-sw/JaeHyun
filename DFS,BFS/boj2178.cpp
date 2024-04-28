#include <bits/stdc++.h>
using namespace std;

string board[101];
int dist[101][101];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    fill(&dist[0][0], &dist[100][100], -1);

    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        board[i] = str;
    }

    queue<pair<int, int>> Q;
    dist[0][0] = 1;
    Q.push({0,0});

    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        if(cur.first == n-1 && cur.second == m-1) {
            cout << dist[n-1][m-1];
            return 0;
        }

        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if(board[nx][ny] == '0' || dist[nx][ny] != -1)
                continue;
            
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            Q.push({nx, ny});
        }
    }
}