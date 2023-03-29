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

ll find_val(ll n, function<ll(ll)> f) {
  ll low = 1, high = 1e9;
  ll ans = 1e9;

  while (high >= low) {
    ll mid = (low + high) / 2;
    if (f(mid) >= n) {
      ans = min(ans, mid);
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return ans;
}

void solve() {
  ll n;
  cin >> n;

  if (n == 1) {
    cout << 0 << endl;
    return;
  }

  ll ans = 1e17;

  {
    ll t = find_val(n - 1, [](ll x) { return 4 * x * (x + 1); });
    ans = min(ans, 2 * t);
  }

  {
    ll t = find_val(n, [](ll x) { return 4 * x * (x + 1) - 4 * x; });
    dbg(t);
    ans = min(ans, 2 * t - 1);
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
