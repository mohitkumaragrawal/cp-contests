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

bool all_equal(vector<ll>& a) {
  for (ll i = 1; i < a.size(); ++i) {
    if (a[i] != a[0]) return false;
  }
  return true;
}

void solve() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  for (ll i = 0; i < n; ++i) cin >> a[i];

  if (all_equal(a)) {
    cout << "0\n";
    return;
  }

  ll min_el = *min_element(all(a));

  if (min_el == 1) {
    cout << "-1\n";
    return;
  }

  vector<pll> ans;

  while (!all_equal(a)) {
    for (ll x = 1; x < n; ++x) {
      while (a[x] != a[0]) {
        ll i = 0, j = x;
        if (a[i] > a[j]) swap(i, j);

        a[j] = (a[j] + a[i] - 1) / a[i];
        ans.emplace_back(j, i);
      }
    }
  }

  cout << ans.size() << "\n";
  for (auto [x, y] : ans) {
    cout << x + 1 << " " << y + 1 << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
