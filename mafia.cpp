#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;

typedef struct gang { 
	string person;
	string boss;
	int node;
	int level;
	int low;
};
gang mafia[2000];
string name[2000];

bool compare(const gang& g1, const gang& g2) {
	if (g1.node == g2.node) {
		if (g1.level == g2.level) {
			if (g1.low == g2.low) {
				return g1.person.compare(g2.person) < 0;
			}
			else return g1.low > g2.low;
		}
		else return g1.level < g2.level;
	}
	else return g1.node > g2.node;
}

void tierCheck(int index) {
	for (int i = 0; i < N; i++) {
		if (mafia[index].boss == mafia[i].person) {
			mafia[i].node++;
			tierCheck(i);
		}
	}
}

void how(int index, int level) {
	for (int i = 0; i < N - 1; i++) {
		if (mafia[i].boss == mafia[index].person) {
			mafia[i].level = level;
			how(i, level+1);
		}
	}
}
int how2(int index) {
	for (int i = 0; i < N; i++) {
		if (mafia[index].person == mafia[i].boss) {
			mafia[index].low = max(mafia[index].low, how2(i) + 1);
		}
	}
	return mafia[index].low;
}


int main(void) {

	string person, boss;

	cin >> N;

	for (int i = 0; i < N-1; i++) {
		cin >> person >> boss;
		mafia[i].person = person;
		mafia[i].boss = boss;
		mafia[i].level = 0;
		mafia[i].node = 0;
		mafia[i].low = 0;
		name[i] = person;
		
	}
	int check = 0;
	string root;
	for (int i = 0; i < N - 1; i++) {
		root = mafia[i].boss;
		for (int j = 0; j < N - 1; j++) {
			check = j;
			if (mafia[i].boss == name[j]) {
				break;
			}
			
		}
		if (check == N - 2) {
			mafia[N - 1].person = root;
			mafia[N - 1].node = N;
		}
		
	}
	for (int i = 0; i < N - 1; i++) {
		tierCheck(i);
		how2(i);
	}
	how(N-1,1);
	sort(mafia, mafia + N, compare);
	for (int i = 0; i < N; i++) {
		cout << mafia[i].person << endl;
	}
}