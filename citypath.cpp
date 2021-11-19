#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct Node
{
	int data;
	int index;
	int next[100];
}Node;

int N;
queue<pair<int, int>> q;
Node tree[100];
int dist[100];
int save[100];
bool visited[100];


int far(int * dist) {
	int king = 0;
	for (int i = 0; i < N; i++) {
		king = max(king, dist[i]);
	}
	return king;
}


void solve(int base) {
	dist[base] = 0;
	q.push(make_pair(base, 0));
	int cur = 0;
	int edge = 0;
	int d = 0;
	int pos = 0;
	while (!q.empty()) {
		cur = q.front().first;
		edge = q.front().second + 1;
		q.pop();
		for (int i = 0; i < tree[cur].index; i++)
		{
			pos = tree[cur].next[i] - 1;
			if (cur == base) d = dist[cur] + 1;
			else d = dist[cur] + 1 + tree[cur].index - 1;
			if (dist[pos] > d) {
				dist[pos] = d;
				q.push(make_pair(pos, edge));
			}
		}
	}

}

int main(void) {
	cin >> N;
	int linked;
	for (int i = 0; i < N; i++) {
		int data = 0;
		cin >> data;
		tree[i].data = i;
		tree[i].index = 0;
		linked = 1;
		do
		{
			cin >> linked;
			if (linked == 0) break;
			tree[i].next[tree[i].index++] = linked;
		} while (true);
	}
	
	for (int i = 0; i < N; i++) {
		fill(dist, dist+100, 10000);
		fill(visited, visited + 100, false);
		solve(i);
		save[i] = far(dist);
	}
	cout << far(save);
}