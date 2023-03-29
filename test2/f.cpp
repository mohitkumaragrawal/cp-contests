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

ll round_div(ll a, ll b) {
  ll d = b / 2;
  if (a < 0) d = -d;
  return (a + d) / b;
}

ll n;
ll a[300005];
ll pre[300005];
ll pre_sq[300005];

ll calc_sum(ll idx) {
  ll m1 = round_div(pre[idx], idx + 1);
  ll m2;

  ll sum = pre[n - 1] - pre[idx];
  ll sq_sum = pre_sq[n - 1] - pre_sq[idx];

  m2 = round_div(sum, (n - idx - 1));

  ll ans1 = (idx + 1) * m1 * m1 + pre_sq[idx] - 2 * m1 * pre[idx];
  ll ans2 = (n - idx - 1) * m2 * m2 + sq_sum - 2 * m2 * sum;

  return ans1 + ans2;
}

void solve() {
  cin >> n;
  for (ll i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);

  pre[0] = a[0];
  for (ll i = 1; i < n; ++i) pre[i] = pre[i - 1] + a[i];

  pre_sq[0] = a[0] * a[0];
  for (ll i = 1; i < n; ++i) pre_sq[i] = pre_sq[i - 1] + a[i] * a[i];

  ll ans = 1e17;

  for (ll i = 0; i < n - 1; ++i) ans = min(ans, calc_sum(i));
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
