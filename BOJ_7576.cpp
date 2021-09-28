#include <iostream>
#include <queue>

using namespace std;

int M, N;
int map[1001][1001];
bool visited[1001][1001];
queue<pair<int,int>> q;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
int day = 0;

void bfs(int x, int y) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}
	
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= 0 && ny < N && nx >= 0 && nx < M && !visited[ny][nx] && map[ny][nx] == 0) {
				map[ny][nx] = map[y][x]+1;
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}
	}
}

int main(void) {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	bfs(0,0);
	int max = 0;
	bool check = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] > max) max = map[i][j];
			if (map[i][j] == 0) check = true;
		}
	}
	if (check) {
		day = -1;
	}
	else { day = --max; }
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}*/
	cout << day << endl;
}