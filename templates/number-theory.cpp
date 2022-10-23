/**
 * 1. prime number seive
 * 2. factorization sieve
 * 3. binary exponentiation
 * 4. binary multiplication
 * 5. modulo inverse of a prime
 * 6. euler totient function
 * 7. nCr
 * 8. factorials
 * 9. extended gcd algorithm
 * 10. linear diophantine equations;
 * 11. primality tests
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
ll binexp(ll a, ll b, ll p = MOD) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) b--, res = (res * a) % p;
    a = (a * a) % p;
    b >>= 1;
  }
  return res;
}

inline ll modinv(ll x, ll p = MOD) { return binexp(x, p - 2, p); }

struct fac_gen {
  fac_gen(ll N, ll p = MOD) : __p(p) {
    __fact.resize(N + 1);
    __fact[0] = 1;
    for (ll i = 1; i <= N; ++i) {
      __fact[i] = (__fact[i - 1] * i) % __p;
    }
  }
  vector<ll> __fact;
  ll operator[](ll i) { return __fact[i]; }

 private:
  ll __p;
};
fac_gen factorial(1000000);

ll choose(ll n, ll r, ll p = MOD) {
  ll res = factorial[n];
  res = (res * modinv(factorial[r], p)) % p;
  res = (res * modinv(factorial[n - r], p)) % p;
  return res;
}

/////////////////////////////////////////////////////////
// PRIME SIEVE
/////////////////////////////////////////////////////////
vector<bool> is_prime;
void init_sieve(ll N) {
  is_prime.assign(N + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (ll i = 2; i <= N; ++i) {
    if (!is_prime[i]) continue;
    for (ll j = i * i; j <= N; j += i) {
      is_prime[j] = false;
    }
  }
}

ll floor_root(ll x) {
  ll ans = sqrt(x) + 1;
  while (ans * ans > x) ans--;
  return ans;
}

//////////////////////////////////////////////////////////
//  PRIME FACTORIZATION USING SIEVE
/////////////////////////////////////////////////////////
vector<ll> fact_sieve;

int main() {
  while (true) {
    ll a, b;
    cin >> a >> b;
    cout << choose(a, b) << endl;
  }
}
