#include <bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

const ll MOD = 1e9 + 7;
ll binexp(ll a, ll b, ll p = MOD) {
  if (b < 0) return 0;
  ll res = 1;
  while (b > 0) {
    if (b & 1) b--, res = (res * a) % p;
    a = (a * a) % p;
    b >>= 1;
  }
  return res;
}

inline ll modinv(ll x, ll p = MOD) { return binexp(x, p - 2, p); }

ll prime1 = 999999929LL, prime2 = 999999937LL;

vector<ll> p31_prime1, p31_prime2;
vector<ll> p31_prime1_inv, p31_prime2_inv;

void init_powers(ll sz = 200005) {
  p31_prime1.resize(sz);
  p31_prime2.resize(sz);

  p31_prime1[0] = p31_prime2[0] = 1;

  for (ll i = 1; i < sz; ++i) {
    p31_prime1[i] = (p31_prime1[i - 1] * 31LL) % prime1;
    p31_prime2[i] = (p31_prime2[i - 1] * 31LL) % prime2;
  }

  p31_prime1_inv.resize(sz);
  p31_prime2_inv.resize(sz);

  ll inv1 = modinv(31LL, prime1);
  ll inv2 = modinv(31LL, prime2);

  p31_prime2_inv[0] = p31_prime1_inv[0] = 1;

  for (ll i = 1; i < sz; ++i) {
    p31_prime1_inv[i] = (p31_prime1_inv[i - 1] * inv1) % prime1;
    p31_prime2_inv[i] = (p31_prime2_inv[i - 1] * inv2) % prime2;
  }
}

vector<pair<ll, ll>> prefix_hash(const string& str) {
  ll n = str.size();
  vector<pair<ll, ll>> prefix(n);

  auto f = [](char ch) -> ll { return ch - 'a' + 1; };

  prefix[0].first = f(str[0]);
  prefix[0].second = f(str[0]);

  for (ll i = 1; i < n; ++i) {
    prefix[i].first =
        (prefix[i - 1].first + f(str[i]) * p31_prime1[i]) % prime1;
    prefix[i].second =
        (prefix[i - 1].second + f(str[i]) * p31_prime2[i]) % prime2;
  }
  return prefix;
}

pair<ll, ll> shift_hash(const pair<ll, ll>& hsh, ll amount) {
  if (amount < 0) {
    return {(hsh.first * p31_prime1_inv[-amount]) % prime1,
            (hsh.second * p31_prime2_inv[-amount]) % prime2};
  }
  return {(hsh.first * p31_prime1[amount]) % prime1,
          (hsh.second * p31_prime2[amount]) % prime2};
}

pair<ll, ll> operator-(const pair<ll, ll>& a, const pair<ll, ll>& b) {
  return {(a.first - b.first + prime1) % prime1,
          (a.second - b.second + prime2) % prime2};
}

void solve() {
  string T, P;
  cin >> T >> P;

  auto phash = prefix_hash(P).back();
  auto thash = prefix_hash(T);

  ll n = T.size();
  ll m = P.size();

  ll cnt = 0;
  for (ll i = 0; i < n; ++i) {
    ll j = i + m - 1;
    if (j >= n) break;

    auto hsh = thash[j];
    if (i > 0) hsh = hsh - thash[i - 1];

    if (hsh == shift_hash(phash, i)) {
      cnt++;
    }
  }
  cout << cnt << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  init_powers(1e6 + 20);

  ll T;
  cin >> T;
  while (T--) solve();

  // solve();
}
