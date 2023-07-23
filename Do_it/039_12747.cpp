#include <iostream>
#include <cmath>
#include <string>

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

bool isPalindrome(long k) {
	string strK = to_string(k);

	int s = 0;
	int e = strK.size() - 1;
	while(s < e) {
		if (strK[s] != strK[e]) return false;
		s++;
		e--;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long n;
	cin >> n;

	prime[0] = prime[1] = false;
	for (int i = 2; i < 10000001; i++) {
		prime[i] = true;
	}
	eratos(10000000);

	long i = n;
	while (true) {
		if (prime[i]) {
			if (isPalindrome(i)) {
				cout << i << "\n";
				break;
			}
		}
		i++;
	}
}