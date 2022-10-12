#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll MOD = 998244353;

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
fac_gen factorial(10000);

ll binexp(ll a, ll b, ll p = MOD) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) b--, res = (res * a) % p;
    a = (a * a) % p;
    b >>= 1;
  }
  return res;
}

void solve() {
  ll m, n;
  cin >> m >> n;

  if ((m + n) % 2 == 0) {
    cout << 0 << endl;
    return;
  }

  ll result = 1;
  result = (factorial[m + n - 2] * factorial[m + n - 1]) % MOD;

  result = (result * binexp(factorial[m - 1], MOD - 2, MOD)) % MOD;
  result = (result * binexp(factorial[n - 1], MOD - 2, MOD)) % MOD;
  result = (result * binexp(factorial[(m + n - 1) / 2], MOD - 2, MOD)) % MOD;
  result = (result * binexp(factorial[(m + n - 1) / 2], MOD - 2, MOD)) % MOD;

  ll left_sq = (m * n) - (m + n - 1);
  result = (result * binexp(2, left_sq, MOD)) % MOD;

  cout << result << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}