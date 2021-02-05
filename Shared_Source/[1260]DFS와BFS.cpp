#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define MAX_N		1000

int N, M, S;
vector<int> vDfs, vBfs;
bool visited[MAX_N + 1];
vector<int> adjs[MAX_N + 1];

void dfs(const int& cur) {
	visited[cur] = true;
	vDfs.push_back(cur);

	for (int i = 0; i < adjs[cur].size(); ++i) {
		if (!visited[adjs[cur][i]]) dfs(adjs[cur][i]);
	}
}

void bfs() {
	queue<int> que;
	que.push(S);
	visited[S] = true;

	int cur, i;
	while (!que.empty()) {
		cur = que.front(), que.pop();
		vBfs.push_back(cur);
		for (i = 0; i < adjs[cur].size(); ++i) {
			if (!visited[adjs[cur][i]]) visited[adjs[cur][i]] = true, que.push(adjs[cur][i]);
		}
	}
}

int main() {
	int i, j;

	scanf("%d %d %d", &N, &M, &S);

	while (M--) {
		scanf("%d %d", &i, &j);
		adjs[i].push_back(j);
		adjs[j].push_back(i);
	}

	for (i = 1; i <= N; ++i) {
		if (adjs[i].size() > 0) sort(adjs[i].begin(), adjs[i].end());
		visited[i] = false;
	}

	dfs(S);

	for (i = 1; i <= N; ++i) visited[i] = false;

	bfs();

	printf("%d", S);
	for (i = 1; i < vDfs.size(); ++i) printf(" %d", vDfs[i]);
	printf("\n");

	printf("%d", S);
	for (i = 1; i < vBfs.size(); ++i) printf(" %d", vBfs[i]);
	printf("\n");

    return 0;
}