#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll primes[] = {1000000007, 9137705699, 5743236313, 2211411701, 9141165697};
ll SZ = 5;

ll binexp(ll a, ll b, ll p) {
  if (b < 0) return 0;
  ll res = 1;
  while (b > 0) {
    if (b & 1) b--, res = (res * a) % p;
    a = (a * a) % p;
    b >>= 1;
  }
  return res;
}

inline ll modinv(ll x, ll p) { return binexp(x, p - 2, p); }

ll LCM(ll a, ll b, ll p) {
  ll res = (a * b) % p;
  res = (res * modinv(__gcd(a, b), p)) % p;
  return res;
}

ll n;
ll a[100005];

bool check(ll p) {
  ull prod = 1;
  for (ll i = 0; i < n; ++i) {
    prod = (prod * a[i]) % p;
  }

  ull lcm = LCM(a[0], a[1], p);
  for (ll i = 2; i < n; ++i) {
    lcm = LCM(lcm, a[i], p);
  }

  return lcm == prod;
}

void solve() {
  cin >> n;
  for (ll i = 0; i < n; ++i) cin >> a[i];

  for (ll i = 0; i < SZ; ++i) {
    if (!check(primes[i])) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
