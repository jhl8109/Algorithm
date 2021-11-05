#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int N, M;
bool check = false;
string str;
vector<int> tmp;
vector<vector<int>> map;

bool visited[1000][1000];
int cnt = 0;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
stack<pair<int, int>> s;

bool IsInside(int ny, int nx) {
	return (0 <= nx && 0 <= ny && nx < N&& ny < M);
}

void solve(int x ,int y) {
	s.push(make_pair(y,x));
	visited[y][x] = true;
	while (!s.empty()) {
		y = s.top().first;
		x = s.top().second;
		s.pop(); 
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (IsInside(ny, nx) && !visited[ny][nx] && map[ny][nx] == 0) {
				visited[ny][nx] = true;
				cnt++;
				s.push(make_pair(ny, nx));
			}
		}
	}
}

int main(void) {
	cin >> N >> M;
	while (true) {
		cin >> str;
		if (str == "-1") break;
		for (int i = 0; i < str.size(); i++) {
			if (tmp.size() % M == M - 1) {
				tmp.push_back(str[i] - '0');
				map.push_back(tmp);
				tmp.clear();
			}
			else {
				tmp.push_back(str[i] - '0');
			}
		} 
	}

	solve(0,0);
	cout << M*N-cnt-1 << endl;
}