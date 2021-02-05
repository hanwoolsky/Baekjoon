#include <cstdio>

#define MAX_N		1000

int nos[MAX_N];
int D[MAX_N];

int max(const int& a, const int& b) { return (a > b) ? a: b; }

int dp(const int& k) {
	//	湲곗�議곌굔
	if (k < 0) return 0;
	//	Memoization
	if (D[k] > 0) return D[k];
	//	�먰솕��
	D[k] = 0;
	for (int i = 0; i < k; ++i) {
		if (nos[i] < nos[k]) D[k] = max(D[k], D[i]);
	}
	D[k] += 1;

	return D[k];
}

int main() {
	int N, i;
	int ans = 0;

	scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		scanf("%d", nos + i);
		ans = max(ans, dp(i));
	}

	printf("%d\n", ans);

	return 0;
}