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

#define endl '\n'

vector<ll> parent;
vector<ll> sz;

ll n, m;
ll n_sqrt;

ll find_set(ll v) {
  if (v == parent[v]) return v;
  return parent[v] = find_set(parent[v]);
}

void union_set(ll u, ll v) {
  u = find_set(u);
  v = find_set(v);
  if (u != v) {
    if (sz[u] < sz[v]) swap(u, v);
    parent[v] = u;
    sz[u] += sz[v];
  }
}

vector<vector<ll>> adj;
vector<ll> ans;
vector<ll> height;

void dfs(ll u, ll p) {
  ll mx_height = -1;

  for (auto v : adj[u]) {
    if (v == p) continue;
    dfs(v, u);

    mx_height = max(height[v], mx_height);
  }

  if (mx_height + 1 == n_sqrt) {
    ans.push_back(u);
    height[u] = -n_sqrt - 1;
  } else {
    height[u] = mx_height + 1;
  }
}

void solve() {
  cin >> n >> m;

  n_sqrt = ceil(sqrtl(n));
  while (n_sqrt * n_sqrt < n) n_sqrt++;

  dbg(n_sqrt);

  parent.resize(n + 1);
  sz.resize(n + 1);

  height.clear();
  height.assign(n + 1, 0);

  adj.clear();
  ans.clear();

  adj.resize(n + 1);

  for (int i = 1; i <= n; i++) {
    parent[i] = i;
    sz[i] = 1;
  }

  for (ll i = 0; i < m; ++i) {
    ll u, v;
    cin >> u >> v;

    if (find_set(u) == find_set(v)) {
      continue;
    }

    adj[u].push_back(v);
    adj[v].push_back(u);
    union_set(u, v);
  }

  if (n == 1) {
    cout << 1 << endl;
    cout << 1 << endl;
    return;
  }

  dfs(1, -1);

  if (height[1] >= 0) {
    ans.push_back(1);
  }

  cout << ans.size() << endl;
  for (auto x : ans) cout << x << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
