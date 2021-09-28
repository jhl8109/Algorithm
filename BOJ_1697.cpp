#include <iostream>
#include <queue>

using namespace std;

int N, K;
queue<int> q;
int pattern[3] = { -1,1,2 };
int map[100001] = { 0, };
bool visited[100001];
bool check(int npoint) {
	return (npoint >= 0 && npoint <= 100000 && !visited[npoint]);
}

void bfs(int start, int end) {
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		int point = q.front();
		q.pop();
		int npoint = point + 1;
		if (npoint == K) {
			cout << map[point] + 1 << endl;
			return;
		}
		if (check(npoint)) {
			q.push(npoint);
			visited[npoint] = true;
			map[npoint] = map[point] + 1;
		}
		npoint = point - 1;
		if (npoint == K) {
			cout << map[point] + 1 << endl;
			return;
		}
		if (check(npoint)) {
			q.push(npoint);
			visited[npoint] = true;
			map[npoint] = map[point] + 1;
		}
		npoint = point * 2;
		if (npoint == K) {
			cout << map[point] + 1 << endl;
			return;
		}
		if (check(npoint)) {
			q.push(npoint);
			visited[npoint] = true;
			map[npoint] = map[point] + 1;
		}
	}
}

int main(void) {
	cin >> N >> K;
	if (N == K) {
		cout << 0;
		return 0;
	}
	bfs(N,K);
}