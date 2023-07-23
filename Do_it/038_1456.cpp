#include <iostream>
#include <cmath>

using namespace std;
bool prime[10000001];

void eratos(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (prime[i]) {
			for (int j = 2 * i; j <= n; j += i) {
				prime[j] = false;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long A, B, count;
	cin >> A >> B;

	count = 0;
	prime[0] = prime[1] = false;
	for (int i = 2; i <= sqrt(B); i++) { // sqrt까지 안 하면 out of bounds
		prime[i] = true;
	}
	eratos(sqrt(B));
	for (int i = 2; i < sqrt(B); i++) {
		if (prime[i]) {
			long tmp = i;
			while ((double)i <= (double)B / (double)tmp) { // N^k와 B를 비교하면 변수 표현 범위 초과 => N과 B / N^(k-1)을 비교
				if ((double)i >= (double)A / (double)tmp) {
					count++;
				}
				tmp *= i;
			}
		}
	}
	cout << count;
}