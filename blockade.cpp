#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N;
int sum[101];
int weight[101][101];
int temp[101][101];
int length;
bool visited[101];
string area[101];

int dfs(int target,int len) {
	visited[target] = true;
	len++;
	for (int i = 0; i < N; i++) {
		if (temp[target][i] != 0 && !visited[i]) {
			len = dfs(i,len);
		}
	}
	return len;
}

int main(void) {
	cin >> N;
	char node[101];
	int x = 0;
	while (true) {
		scanf("%s", node);
		area[x] = node;
		if (strcmp(node,"-1") == 0) break;
		for (int j = 0; j < N; j++) {
			cin >> weight[x][j];
		}
		x++;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sum[i] += weight[i][j];
		}
	}

	for (int k = 0; k < N; k++) {
		int big = 0;
		int index = 0;
		for (int i = 0; i < N; i++) {
			if (big <= sum[i]) {
				big = sum[i];
				index = i;
			}
		}
		sum[index] = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == index) {
					temp[i][j] = 0;
				}
				else if (j == index) {
					temp[i][j] = 0;
				}
				else {
					temp[i][j] = weight[i][j];
				}
			}
		}
		length = 0;
		for (int v = 0; v < N; v++) {
			visited[v] = false;
		}
		if (index == 0) { length = dfs(1, 0); }
		else { length = dfs(0, 0); }
		if (length < N-1) {
			cout << area[index];
			return 0;
		}
	}
	cout << "None" << endl;
}
