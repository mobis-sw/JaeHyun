#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

string board[50];
int dist[50][50];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	stack<pair<int, int>> S;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'L')
				S.push({ i,j });
		}
	}

	queue<pair<int, int>> Q;
	int result = -1;

	while (!S.empty()) {
		for (int i = 0; i < 50; i++) {
			fill(dist[i], &dist[i][50], -1);
		}

		auto cur = S.top();
		S.pop();

		dist[cur.first][cur.second] = 0;
		Q.push({ cur.first, cur.second });

		int max_distance = dist[cur.first][cur.second];

		while (!Q.empty()) {
			auto cur = Q.front();
			Q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m)
					continue;
				if (board[nx][ny] == 'W' || dist[nx][ny] > -1)
					continue;

				dist[nx][ny] = dist[cur.first][cur.second] + 1;
				Q.push({ nx,ny });

				max_distance = max(max_distance, dist[nx][ny]);
			}
		}

		result = max(result, max_distance);
	}

	cout << result;
}
