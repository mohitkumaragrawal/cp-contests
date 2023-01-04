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

  vector<ll> a(n), b(m);
  for (ll i = 0; i < n; ++i) cin >> a[i];
  for (ll i = 0; i < m; ++i) cin >> b[i];

  priority_queue<pll> pq;

  for (ll i = 0; i < n; ++i) {
    pq.push({-a[i], i});
  }

  for (ll i = 0; i < m; ++i) {
    auto [el, idx] = pq.top();
    pq.pop();

    dbg(el, idx);

    a[idx] = b[i];
    pq.push({-b[i], idx});
  }

  ll sum = 0;
  for (ll i = 0; i < n; ++i) sum += a[i];
  cout << sum << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
