#include <iostream>

using namespace std;

bool prime[1000001];

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

	int M, N;
	cin >> M >> N;

	prime[0] = prime[1] = false;
	for (int i = 2; i <= N; i++) {
		prime[i] = true;
	}
	eratos(N);
	for (int i = M; i <= N; i++) {
		if (prime[i]) cout << i << "\n";
	}
}