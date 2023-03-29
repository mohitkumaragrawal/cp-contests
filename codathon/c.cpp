#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

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

void solve() {
  ll n, m;
  cin >> n >> m;

  vector<ll> a(n);

  map<ll, ll> mp;

  for (ll i = 0; i < n; ++i) {
    cin >> a[i];

    mp[a[i]] = m + 1;
  }
  ll ans = m * n * (m + 1);

  for (ll i = 0; i < m; ++i) {
    ll p, v;
    cin >> p >> v;
    p--;

    ll prev = a[p];
    a[p] = v;

    mp[v] += (m - i);
    mp[prev] -= (m - i);
  }

  for (auto [v, f] : mp) {
    ans -= f * (f - 1) / 2;
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
