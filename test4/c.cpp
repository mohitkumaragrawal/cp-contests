#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#define endl '\n'

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

ll choose2(ll p) { return (p * (p - 1) / 2) + p; }

ll calc(ll k) {
  if (k == 0) return 0;

  for (ll i = 1; i <= 30; ++i) {
    if (choose2(i) <= k && k < choose2(i + 1)) return i;
  }
  return -1;
}

void solve() {
  ll n, k;
  cin >> n >> k;

  vector<ll> a(n, -2);

  ll idx = 0;

  while (k > 0) {
    a[idx] = min(k, n - idx) * 2;
    k -= a[idx] / 2;

    a[idx]--;

    idx++;
  }

  for (ll i = 0; i < n; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
