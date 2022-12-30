#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll n;
vector<vector<ll>> G;
vector<ll> indegree;
vector<bool> vis, vis_dfs, in_stack;
ll bought;

bool has_cyle = false;

vector<ll> later;

void dfs(ll x) {
  vis_dfs[x] = true;
  in_stack[x] = true;

  for (auto child : G[x]) {
    if (in_stack[child]) {
      has_cyle = true;
      break;
    }

    if (!vis_dfs[child]) {
      dfs(child);
    }
  }

  in_stack[x] = false;
}

void process() {
  queue<ll> q;

  for (auto el : later) {
    q.push(el);
  }

  later.clear();

  while (!q.empty()) {
    ll x = q.front();
    vis[x] = true;

    q.pop();

    for (ll ch : G[x]) {
      --indegree[ch];
      if (indegree[ch] != 0) continue;

      if (ch >= x) {
        q.push(ch);
      } else {
        later.push_back(ch);
      }
    }
  }
}

void solve() {
  G.clear();
  indegree.clear();
  vis.clear();
  vis_dfs.clear();
  in_stack.clear();
  bought = 0;
  has_cyle = false;

  cin >> n;

  G.resize(n + 1);
  indegree.assign(n + 1, 0);
  vis.assign(n + 1, false);
  vis_dfs.assign(n + 1, false);
  in_stack.assign(n + 1, false);

  for (ll i = 1; i <= n; ++i) {
    ll dep;
    cin >> dep;

    for (ll j = 0; j < dep; ++j) {
      ll x;
      cin >> x;

      G[x].push_back(i);
    }
  }

  for (ll i = 1; i <= n; ++i) {
    if (has_cyle) break;
    if (!vis_dfs[i]) dfs(i);
  }

  for (ll i = 1; i <= n; ++i) {
    for (auto nd : G[i]) {
      indegree[nd]++;
    }
  }

  if (has_cyle) {
    cout << "-1\n";
    return;
  }

  later.clear();
  for (ll i = 1; i <= n; ++i) {
    if (indegree[i] == 0) {
      later.push_back(i);
    }
  }

  ll ans = 0;
  while (!later.empty()) {
    ans++;
    sort(all(later));
    process();
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T = 1;
  cin >> T;
  while (T--) solve();
}
