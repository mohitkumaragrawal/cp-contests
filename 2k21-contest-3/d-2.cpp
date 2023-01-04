#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  ll n;

  cin >> n;
  vector<vector<ll>> G(n + 1);
  vector<vector<ll>> deps(n + 1);

  for (ll i = 1; i <= n; ++i) {
    ll dep_cnt;
    cin >> dep_cnt;

    for (ll j = 0; j < dep_cnt; ++j) {
      ll x;
      cin >> x;

      G[x].push_back(i);
      deps[i].push_back(x);
    }
  }

  vector<ll> indegree(n + 1);
  for (ll i = 1; i <= n; ++i) {
    for (ll child : G[i]) {
      indegree[child]++;
    }
  }

  vector<ll> toposort;
  queue<ll> q;

  for (ll i = 1; i <= n; ++i) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    ll x = q.front();
    q.pop();

    toposort.push_back(x);

    for (ll child : G[x]) {
      indegree[child]--;

      if (indegree[child] == 0) {
        q.push(child);
      }
    }
  }

  if (toposort.size() < n) {
    cout << "-1\n";
    return;
  }

  vector<ll> index_topo(n + 1);
  for (ll i = 0; i < n; ++i) {
    index_topo[toposort[i]] = i;
  }

  vector<ll> dp(n);
  dp[0] = 1;

  for (ll i = 1; i < n; ++i) {
    ll max_round = 0;
    ll item = toposort[i];

    if (deps[item].empty()) {
      dp[i] = 1;
      continue;
    }

    for (ll d : deps[item]) {
      ll idx = index_topo[d];
      max_round = max(max_round, dp[idx]);
    }

    bool possible = true;

    for (ll d : deps[item]) {
      ll idx = index_topo[d];
      ll round = dp[idx];

      if (round != max_round) continue;

      if (d > item) {
        possible = false;
        break;
      }
    }

    if (possible) {
      dp[i] = max_round;
    } else {
      dp[i] = max_round + 1;
    }
  }

  cout << *max_element(all(dp)) << '\n';
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T = 1;
  cin >> T;
  while (T--) solve();
}
