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
  vector<pll> a(n);

  multiset<ll> st;

  for (ll i = 1; i <= n; ++i) {
    st.insert(i);
    st.insert(i);
  }

  bool valid = true;

  for (ll i = 0; i < n; ++i) {
    ll val;
    cin >> val;

    if (st.count(val) == 0) {
      valid = false;
    } else {
      st.erase(st.find(val));
    }

    a[i] = {val, i};
  }

  if (!valid) {
    cout << "NO\n";
    return;
  }

  sort(all(a));

  vector<ll> s1(n), s2(n);

  vector<bool> s1_ex(n + 5, false), s2_ex(n + 5, false);

  vector<vector<pair<ll, ll>>> G;
  G.resize(n + 1);

  for (auto [el1, idx] : a) {
    if (st.empty()) {
      cout << "NO\n";
      return;
    }

    ll el2 = *st.begin();
    if (el2 > el1) {
      cout << "NO\n";
      return;
    }

    st.erase(st.find(el2));
    if (el1 > el2) swap(el1, el2);

    G[el1].push_back({el2, idx});
    G[el2].push_back({el1, idx});
  }

  vector<bool> vis(n + 1, false);

  function<void(ll)> dfs = [&](ll el1) {
    for (auto [el2, idx] : G[el1]) {
      if (vis[idx]) continue;

      ll x = el1, y = el2;
      if (s1_ex[el1] || s2_ex[el2]) {
        swap(x, y);
      }

      dbg(el1, el2);

      if (s1_ex[el1] || s2_ex[el2]) {
        dbg(el1, el2);
        valid = false;
        return;
      }

      s1_ex[x] = true;
      s2_ex[y] = true;
      s1[idx] = x;
      s2[idx] = y;

      vis[idx] = true;
      dfs(el2);
    }

    // if (vis[el1] || !valid) return;
    // vis[el1] = true;
    //
    // for (auto [el2, idx] : G[el1]) {
    //   ll x = el1, y = el2;
    //   if (s1_ex[el1] || s2_ex[el2]) {
    //     swap(x, y);
    //   }
    //
    //   dbg(el1, el2);
    //
    //   if (s1_ex[el1] || s2_ex[el2]) {
    //     dbg(el1, el2);
    //     valid = false;
    //     return;
    //   }
    //
    //   s1_ex[x] = true;
    //   s2_ex[y] = true;
    //   s1[idx] = x;
    //   s2[idx] = y;
    //
    //   dfs(el2);
    // }
  };

  // dfs(1);

  for (ll i = 1; i <= n; ++i) dfs(i);

  if (!valid) {
    cout << "NO\n";
    return;
  }

  cout << "YES\n";
  for (ll i = 0; i < n; ++i) {
    cout << s1[i] << " \n"[i == n - 1];
  }
  for (ll i = 0; i < n; ++i) {
    cout << s2[i] << " \n"[i == n - 1];
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
