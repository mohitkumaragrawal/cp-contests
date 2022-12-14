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

template <ll mod>
struct MODINT_ {
  ll value;
  MODINT_() = default;
  MODINT_(ll x) : value(x % mod) {}
  MODINT_(const MODINT_& m) : value(m.value % mod) {}
  MODINT_& operator=(const MODINT_& m) {
    value = m.value;
    return *this;
  }
  ll inverse_value() const { return modinv(value, mod); }
  MODINT_& operator+=(const MODINT_& m) {
    value = (value + m.value) % mod;
    return *this;
  }
  MODINT_& operator-=(const MODINT_& m) {
    value = (mod + value - m.value) % mod;
    return *this;
  }
  MODINT_& operator*=(const MODINT_& m) {
    value = (value * m.value) % mod;
    return *this;
  }
  MODINT_& operator/=(const MODINT_& m) {
    value = (value * m.inverse_value()) % mod;
    return *this;
  }
  MODINT_& operator++() {
    value++;
    value %= mod;
    return *this;
  }
  MODINT_& operator--() {
    value--;
    value %= mod;
    return *this;
  }
  MODINT_ operator*(const MODINT_& b) { return MODINT_(value * b.value); }
  MODINT_ operator*(ll b) { return MODINT_(value * b); }
  MODINT_ operator-(const MODINT_& b) { return MODINT_(mod + value - b.value); }
  MODINT_ operator-(ll b) { return MODINT_(mod + value - b); }
  MODINT_ operator+(const MODINT_& b) { return MODINT_(value + b.value); }
  MODINT_ operator+(ll b) { return MODINT_(value + b); }
  MODINT_ operator/(const MODINT_& b) {
    return MODINT_(value * modinv(b.value, mod));
  }
  MODINT_ operator/(ll b) { return MODINT_(value * modinv(b, mod)); }
};
using MODINT = MODINT_<MOD>;
vector<MODINT> factorial;
void init_factorial() {
  factorial.resize(1000005);
  factorial[0] = factorial[1] = 1;
  for (ll i = 2; i < 1000005; ++i) {
    factorial[i] = (factorial[i - 1] * i);
  }
}
inline MODINT choose(const MODINT& a, const MODINT& b) {
  return factorial[a.value] /
         (factorial[b.value] * factorial[(a.value - b.value)]);
}

vector<bool> is_prime;
void init_is_prime(ll N = 200005) {
  is_prime.assign(N + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (ll i = 2; i <= N; ++i) {
    if (!is_prime[i]) continue;
    for (ll j = i * i; j <= N; j += i) {
      is_prime[j] = false;
    }
  }
}

vector<ll> sieve;
void init_sieve(ll N = 200005) {
  sieve.resize(N + 1);
  for (ll i = 1; i <= N; ++i) {
    sieve[i] = i;
  }
  for (ll i = 2; i * i <= N; ++i) {
    if (sieve[i] != i) continue;
    for (ll j = i * i; j <= N; j += i) {
      if (sieve[j] == j) sieve[j] = i;
    }
  }
}

vector<ll> fact;
void init_fact(ll mod, ll N = 200005) {
  fact.resize(N + 1);
  fact[0] = 1;
  for (ll i = 1; i <= N; ++i) {
    fact[i] = (fact[i - 1] * i) % mod;
  }
}

ll floor_root(ll x) {
  ll ans = sqrt(x) + 1;
  while (ans * ans > x) ans--;
  return ans;
}

int main() {}
