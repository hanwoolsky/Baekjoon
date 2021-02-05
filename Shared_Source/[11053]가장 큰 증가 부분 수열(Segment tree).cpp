#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_N		1000
#define SZ_TR		2048

struct No {
	int n;
	int idx;
} nos[MAX_N];
int tree[SZ_TR];

bool comp(const No& a, const No& b) { return (a.n < b.n || (a.n == b.n && a.idx > b.idx)); }

int query(const int& nd, const int& from, const int& to, const int& srchIdx) {
	if (from > srchIdx) return 0;
	if (to <= srchIdx) return tree[nd];

	int left = nd << 1, right = left + 1, mid = (from + to) >> 1;

	return max(query(left, from, mid, srchIdx), query(right, mid + 1, to, srchIdx));
}

void update(const int& nd, const int& from, const int& to, int idx, int lis) {
	if (from > idx || to < idx) return;
	tree[nd] = max(tree[nd], lis);
	if (from == to) return;

	int left = nd << 1, right = left + 1, mid = (from + to) >> 1;

	update(left, from, mid, idx, lis);
	update(right, mid + 1, to, idx, lis);
}

int main() {
	int N, i;

	scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		scanf("%d", &nos[i].n);
		nos[i].idx = i + 1;
	}

	sort(nos, nos + N, comp);

	for (i = 0; i < N; ++i) {
		update(1, 1, N, nos[i].idx, query(1, 1, N, nos[i].idx) + 1);
	}

	printf("%d\n", query(1, 1, N, N));

	return 0;
}