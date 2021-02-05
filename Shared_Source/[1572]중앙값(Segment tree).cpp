#include <cstdio>

#define MAX_N		250000
#define MAX_V		65536
#define SZ_TR		262144

typedef long long ll;

int tr[SZ_TR], nos[MAX_N];

void update(const int& nd, const int& from, const int& to, const int& idx, const int& add) {
	if (from > idx || to < idx) return;
	tr[nd] += add;
	if (from == to) return;

	int left = nd << 1, right = left + 1, mid = (from + to) >> 1;
	update(left, from, mid, idx, add);
	update(right, mid + 1, to, idx, add);
}

int findKth(const int& nd, const int& from, const int& to, const int& kth) {
	if (from == to) return from;

	int left = nd << 1, right = left + 1, mid = (from + to) >> 1;

	if (tr[left] >= kth) return findKth(left, from, mid, kth);
	else return findKth(right, mid + 1, to, kth - tr[left]);
}

int main() {
	ll ans;
	int N, K, M, i;

	scanf("%d %d", &N, &K);
	M = (K + 1) >> 1;

	for (i = 0; i < K; ++i) {
		scanf("%d", nos + i);
		update(1, 0, MAX_V, nos[i], 1);
	}

	ans = findKth(1, 0, MAX_V, M);

	for (i = K; i < N; ++i) {
		scanf("%d", nos + i);
		update(1, 0, MAX_V, nos[i], 1);
		update(1, 0, MAX_V, nos[i - K], -1);
		ans += findKth(1, 0, MAX_V, M);
	}

	printf("%lld\n", ans);

	return 0;
}