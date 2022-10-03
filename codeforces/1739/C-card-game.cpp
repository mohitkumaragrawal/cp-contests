#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll MOD = 998244353;

ll binexp(ll base, ll pow, ll m = MOD) {
  ll result = 1;
  while (pow > 0) {
    if (pow & 1) {
      pow--;
      result = (result * base) % m;
    } else {
      base = (base * base) % m;
      pow /= 2;
    }
  }
  return result;
}

vector<ll> fact;
void init_fact() {
  fact.resize(61);
  fact[0] = 1;

  for (ll i = 1; i < fact.size(); ++i) {
    fact[i] = (i * fact[i - 1]) % MOD;
  }
}

ll choose(ll n, ll r) {
  ll result = fact[n];
  result = (result * binexp(fact[r], MOD - 2)) % MOD;
  result = (result * binexp(fact[n - r], MOD - 2)) % MOD;

  return result;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  init_fact();

  vector<ll> alice(61), bob(61), draw(61);

  alice[2] = 1, bob[2] = 0, draw[2] = 1;
  for (ll i = 4; i <= 60; i += 2) {
    alice[i] = (choose(i - 1, i / 2) + bob[i - 2]) % MOD;
    bob[i] = (choose(i - 2, i / 2) + alice[i - 2]) % MOD;
    draw[i] = draw[i - 2];
  }

  int T;
  cin >> T;
  while (T--) {
    ll N;
    cin >> N;

    ll num = fact[(N - 2) / 2];
    if (N == 2) num = 0;
    cout << (alice[N]) % MOD << " " << (bob[N]) % MOD << " " << draw[N] << endl;
  }
}