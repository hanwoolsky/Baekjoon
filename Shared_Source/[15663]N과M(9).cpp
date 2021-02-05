#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int M, ans[8];
vector<pii> nos;

void backtracking(const int& loc) {
	int i;
	if (loc == M) {
		printf("%d", ans[0]);
		for (i = 1; i < M; ++i) printf(" %d", ans[i]);
		printf("\n");
		return;
	}

	for (i = 0; i < nos.size(); ++i) {
		if (nos[i].second > 0) {
			ans[loc] = nos[i].first;
			--nos[i].second;
			backtracking(loc + 1);
			++nos[i].second;
		}
	}
}

int main() {
	int N, n, i, j;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; ++i) {
		scanf("%d", &n);
		for (j = 0; j < nos.size(); ++j) {
			if (nos[j].first == n) {
				++nos[j].second;
				break;
			}
		}
		if (j == nos.size()) nos.push_back(make_pair(n, 1));
	}
	sort(nos.begin(), nos.end());

	backtracking(0);

	return 0;
}