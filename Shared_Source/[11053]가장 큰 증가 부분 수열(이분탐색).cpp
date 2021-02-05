#include <cstdio>

#define MAX_N		1000

int nos[MAX_N];
int L = -1, lis[MAX_N];

int getIndex(const int& n) {
	int low = 0, high = L, mid;

	while (low <= high) {
		mid = (low + high) >> 1;
		if (lis[mid] >= n) high = mid - 1;
		else low = mid + 1;
	}

	return high + 1;
}

int main() {
	int N, i, idx;

	scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		scanf("%d", nos + i);
		idx = getIndex(nos[i]);
		if (idx > L) L = idx;
		lis[idx] = nos[i];
	}

	printf("%d\n", L + 1);

	return 0;
}