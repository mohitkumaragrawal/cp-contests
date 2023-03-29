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
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (ll i = 0; i < n; ++i) cin >> a[i];

  vector<ll> sorted = a;
  sort(all(sorted));

  set<pll> indices;
  for (ll i = 0; i < n; ++i) {
    indices.insert({a[i], i});
  }

  vector<pll> ans;

  for (ll i = 0; i < n; ++i) {
    auto itr1 = indices.lower_bound({sorted[i], -1});

    ll j = itr1->second;
    if (sorted[i] == a[i]) {
      indices.erase(itr1);
      continue;
    }

    auto itr2 = indices.lower_bound({a[i], i});

    indices.erase(itr2);
    indices.erase(itr1);

    indices.insert({a[i], j});
    swap(a[i], a[j]);

    ans.push_back({i, j});
    ans.push_back({j, i});
    ans.push_back({i, j});
  }

  cout << ans.size() << '\n';
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
