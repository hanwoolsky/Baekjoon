#include <cstdio>

typedef long long ll;

ll N, A;

ll gcd(ll a, ll b) {
	ll t;

	while (b) {
		t = a % b;
		a = b;
		b = t;
	}

	return a;
}

ll getInverse(const ll &a) {
	ll r, q, s, t, s1 = 1, s2 = 0, t1 = 0, t2 = 1, r1 = N, r2 = a;

	while (r2) {
		q = r1 / r2, r = r1 % r2;
		s = s1 - q * s2, t = t1 - q * t2;

		r1 = r2, r2 = r;
		s1 = s2, s2 = s;
		t1 = t2, t2 = t;
	}

	t1 %= N;
	if (t1 < 0) t1 += N;

	return t1;
}

int main() {
	scanf("%lld %lld", &N, &A);

	if (gcd(N, A) == 1) printf("%lld %lld\n", N - A, getInverse(A));
	else printf("%lld -1\n", N - A);

	return 0;
}