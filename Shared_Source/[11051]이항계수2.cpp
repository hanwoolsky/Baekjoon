#include <cstdio>

#define MAX_N		1000
#define DIV			10007

int combi[MAX_N + 1][MAX_N + 1];

int main() {
	int N, K, n, k;

	scanf("%d %d", &N, &K);

	for (n = 0; n <= N; ++n) {
		combi[n][0] = combi[n][n] = 1;
		for (k = 1; k < n; ++k) combi[n][k] = (combi[n - 1][k - 1] + combi[n - 1][k]) % DIV;
	}

	printf("%d\n", combi[N][K]);

	return 0;
}