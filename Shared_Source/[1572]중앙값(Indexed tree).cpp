#include <cstdio>

#define MAX_N		250000
#define SZ_TR		262144
#define OFFSET		131072

typedef long long ll;

int tr[SZ_TR], nos[MAX_N];

void update(int idx, const int& add) {
	idx += OFFSET;

	while (idx > 0) {
		tr[idx] += add;
		idx >>= 1;
	}
}

int findKth(int kth) {
	int cur = 1;
	while (cur < OFFSET) {
		if (tr[cur << 1] >= kth) cur <<= 1;
		else kth -= tr[cur << 1], cur = (cur << 1) + 1;
	}

	return cur - OFFSET;
}

int main() {
	ll ans;
	int N, K, M, i;

	scanf("%d %d", &N, &K);
	M = (K + 1) >> 1;

	for (i = 0; i < K; ++i) {
		scanf("%d", nos + i);
		update(nos[i], 1);
	}

	ans = findKth(M);

	for (i = K; i < N; ++i) {
		scanf("%d", nos + i);
		update(nos[i], 1);
		update(nos[i - K], -1);
		ans += findKth(M);
	}

	printf("%lld\n", ans);

	return 0;
}