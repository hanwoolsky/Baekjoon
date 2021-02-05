#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_N		1000

struct No {
	int n;
	int idx;
} nos[MAX_N];
int N, tree[MAX_N + 1];

bool comp(const No& a, const No& b) { return (a.n < b.n || (a.n == b.n && a.idx > b.idx)); }

int query(int idx) {
	int res = 0;

	while (idx > 0) {
		res = max(res, tree[idx]);
		idx -= idx & (-idx);
	}

	return res;
}

void update(int idx, int lis) {
	while (idx <= N) {
		tree[idx] = max(tree[idx], lis);
		idx += idx & (-idx);
	}
}

int main() {
	int i;

	scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		scanf("%d", &nos[i].n);
		nos[i].idx = i + 1;
	}

	sort(nos, nos + N, comp);

	for (i = 0; i < N; ++i) {
		update(nos[i].idx, query(nos[i].idx) + 1);
	}

	printf("%d\n", query(N));

	return 0;
}