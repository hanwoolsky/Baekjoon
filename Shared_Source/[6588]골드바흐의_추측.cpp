#include <cstdio>

#define MAX_NO 1000000
#define MAX_CALC 1000

bool flags[MAX_NO + 1];
int primes[MAX_NO], prmIdx = -1;

int main() {
	int no, i, j, m;

	for (i = 2; i <= MAX_CALC; ++i) {
		if (!flags[i]) {
			primes[++prmIdx] = i;
			for (j = i * i; j <= MAX_NO; j += i) flags[j] = true;
		}
	}
	for (i = MAX_CALC + 1; i <= MAX_NO; ++i) {
		if (!flags[i]) primes[++prmIdx] = i;
	}

	scanf("%d", &no);
	while (no > 0) {
		i = 1, j = prmIdx;
		while (i <= j) {
			m = (i + j) >> 1;
			if (primes[m] >= no) j = m - 1;
			else i = m + 1;
		}
		i = 1, ++j;
		while (i <= j) {
			if (no == (primes[i] + primes[j])) {
				printf("%d = %d + %d\n", no, primes[i], primes[j]);
				break;
			}
			else if (no < (primes[i] + primes[j])) --j;
			else ++i;
		}
		if (i > j) printf("Goldbach's conjecture is wrong.\n");
		scanf("%d", &no);
	}

	return 0;
}