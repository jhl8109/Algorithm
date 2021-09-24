#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int map[26][26];
int dx[4] = { 0, 1, -1, 0 };
int dy[4] = { 1, 0, 0, -1 };
queue<pair<int, int>> q;
bool visited[26][26];
vector<int> v;


bool IsInside(int ny, int nx) {
	return (0 <= nx && 0 <= ny && nx < N&& ny < N);
}

int bfs(int x, int y) {
	int dist = 1;
	visited[y][x] = true;
	q.push(make_pair(y, x));

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (IsInside(ny, nx) && !visited[ny][nx] && map[ny][nx]) {
				visited[ny][nx] = true;
				dist++;
				q.push(make_pair(ny, nx));
			}
		}

	}
	return dist;
}

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int pp = bfs(i, j);
			if (pp != 1) {
				v.push_back(pp);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	
}