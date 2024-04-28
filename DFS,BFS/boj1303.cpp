#include <bits/stdc++.h>
using namespace std;

int n, m;
string board[100];
bool visited_W[100][100];
bool visited_B[100][100];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int cnt_W = 0;
int cnt_B = 0;

void DFS_B(pair<int, int> a) {
    visited_B[a.first][a.second] = 1;
    cnt_B++;
    
    for(int i = 0; i < 4; i++) {
        int nx = a.first + dx[i];
        int ny = a.second + dy[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if(board[nx][ny] == 'W' || visited_B[nx][ny] == 1)
            continue;
        
        DFS_B({nx, ny});
    }

    return;
}

void DFS_W(pair<int, int> a) {
    visited_W[a.first][a.second] = 1;
    cnt_W++;
    
    for(int i = 0; i < 4; i++) {
        int nx = a.first + dx[i];
        int ny = a.second + dy[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if(board[nx][ny] == 'B' || visited_W[nx][ny] == 1)
            continue;
        
        DFS_W({nx, ny});
    }

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int W = 0;
    int B = 0;

    cin >> m >> n;

    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        board[i] = str;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'W' && visited_W[i][j] == 0) {
                cnt_W = 0;
                DFS_W({i, j});
                W += cnt_W * cnt_W;
                // cout << cnt_W << '\n';
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'B' && visited_B[i][j] == 0) {
                cnt_B = 0;
                DFS_B({i, j});
                // cout << cnt;
                B += cnt_B * cnt_B;
            }
        }
    }

    cout << W << " " << B;
}