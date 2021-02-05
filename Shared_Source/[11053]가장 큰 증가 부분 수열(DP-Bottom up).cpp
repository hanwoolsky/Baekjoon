#include <cstdio>

#define MAX_N		1000

int nos[MAX_N];
int D[MAX_N];

int max(const int& a, const int& b) { return (a > b) ? a: b; }

int dp(const int& N) {
	int res = 0;
	int i, j;

	for (i = 0; i < N; ++i) {
		for (j = 0; j < i; ++j) {
			if (nos[j] < nos[i]) D[i] = max(D[i], D[j]);
		}
		D[i] += 1;
		res = max(res, D[i]);
	}

	return res;
}

int main() {
	int N, i;

	scanf("%d", &N);
	for (i = 0; i < N; ++i) scanf("%d", nos + i);

	printf("%d\n", dp(N));

	return 0;
}