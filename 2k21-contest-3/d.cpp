#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll n, m, k, s;
vector<vector<ll>> G, cost, type;

const ll INF = 1e15;

void find_cost(ll t) {
  G[0].clear();
  for (auto nd : type[t]) {
    G[0].push_back(nd);
  }

  vector<ll> dist(n + 1, INF);
  vector<ll> vis(n + 1, false);

  dist[0] = 0;

  queue<ll> q;
  q.push(0);

  while (!q.empty()) {
    ll x = q.front();
    q.pop();

    if (vis[x]) continue;
    vis[x] = true;

    for (ll child : G[x]) {
      q.push(child);

      dist[child] = min(dist[child], 1 + dist[x]);
    }
  }

  for (ll i = 1; i <= n; ++i) {
    cost[i].push_back(dist[i] - 1);
  }
}

void solve() {
  cin >> n >> m >> k >> s;

  G.resize(n + 10);
  cost.resize(n + 10);
  type.resize(min(k + 10, n + 10));

  for (ll i = 1; i <= n; ++i) {
    ll t;
    cin >> t;

    type[t].push_back(i);
  }

  for (ll i = 0; i < m; ++i) {
    ll u, v;
    cin >> u >> v;

    G[u].push_back(v);
    G[v].push_back(u);
  }

  for (ll i = 1; i <= k; ++i) {
    find_cost(i);
  }

  vector<ll> ans(n + 1);
  for (ll i = 1; i <= n; ++i) {
    sort(all(cost[i]));

    ll sum = 0;
    for (ll j = 0; j < s; ++j) {
      sum += cost[i][j];
    }

    ans[i] = sum;
  }

  for (ll i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
