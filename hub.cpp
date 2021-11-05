#include <iostream>
#include <set>

using namespace std;

int N;


set<int> s[1000];
int dp[1000];
int center[1000];


void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b; 
		if (dp[a] != 0 && dp[b] != 0 && dp[a] == dp[b]) continue; 
		else{
			center[a]++;
			center[b]++;
		}
		if (dp[a] == 0 && dp[b] == 0) {
			dp[a] = a;
			dp[b] = a;
			s[a].insert(a);
			s[a].insert(b);
		}
		else if (dp[a] != 0 && dp[b] == 0) {
			dp[b] = dp[a];
			s[dp[a]].insert(b);
		}
		else if (dp[a] == 0 && dp[b] != 0) {
			dp[a] = dp[b];
			s[dp[b]].insert(a);
		}
		else {
			int x, y;
			if (a < b) {
				x = a;
				y = b;
			}
			else {
				x = b;
				y = a;
			}
			s[dp[y]].clear();
			for (int j = 1; j <= N; j++) {
				if (dp[j] == dp[y]) {
					dp[j] = dp[x];
					s[dp[x]].insert(j);
				}
			}
		}
	}
}

int main(void) {
	input();
	int cnt = 0;
	int bigCenter = 0;
	int big = 0;
	int index = 0;
	bool twice = false;;
	set<int> check;
	for (int i = 1; i <= N; i++) {
		if (bigCenter <= center[i]) {
			bigCenter = center[i];
			index = i;
		}
	}
	for (int i = 1; i <= N; i++) {
		
		if (i == index) continue;
		if (center[i] == bigCenter) {
			twice = true;
			index = 0;
			break;
		}
	}

	
	cout << index << " " << s[dp[index]].size() << endl;

	for (int i = 1; i <= N; i++) {
		if (s[i].size() != 0) cnt++;
		if (big <= s[i].size()) {
			big = s[i].size();
		}
		

	}

	cout << big << endl;	
	cout << cnt  << endl;
	
	
}