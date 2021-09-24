#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue> // use bfs algorithm
#include <stdio.h> // use printf, scanf
#include <cstring> // use memset

#define MAX_SIZE 100

using namespace std;

int N, M;
int graph[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];

// ��,��,��,��
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0 , -1 };

bool IsInside(int ny, int nx) {
    return (0 <= nx && 0 <= ny && nx < M&& ny < N);
}

void bfs(int y, int x) {
    queue< pair<int, int> > q; // �̿��� ť, (y,x)
    // ó�� y,x�� �湮 �߱� ������
    visited[y][x] = true;
    dist[y][x] = 1;

    q.push(make_pair(y, x));
    while (!q.empty()) {
        // ť�� ���� ���Ҹ� ������
        y = q.front().first;
        x = q.front().second;
        q.pop();

        // �ش� ��ġ�� �ֺ��� Ȯ��
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            // ������ ����� �ʰ�, �̵��� �� �ִ� ĭ�̸鼭, ���� �湮���� �ʾҴٸ�
            if (IsInside(ny, nx) && graph[ny][nx] && !visited[ny][nx]) {
                visited[ny][nx] = true;
                dist[ny][nx] = dist[y][x] + 1; // ���� �湮�� + 1
                q.push(make_pair(ny, nx));
            }
        }
    }
}

int main() {
    /* �׷��� �� �湮���, �Ÿ� �ʱ�ȭ */
    memset(graph, false, sizeof(graph));
    memset(visited, false, sizeof(visited));
    memset(dist, false, sizeof(dist));

    /* �̷�(�׷���)�� ũ�� �Է�*/
    scanf("%d %d", &N, &M);

    /* �׷��� ���� �Է� */
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &graph[i][j]);
        }
    }

    /* �׷����� BFS�� ���� Ž�� */
    bfs(0, 0);

    /* �ּ� �� ������ ��� */
    printf("%d\n", dist[N - 1][M - 1]);
    return 0;
}
