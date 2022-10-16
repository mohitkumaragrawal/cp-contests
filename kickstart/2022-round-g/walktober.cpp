#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "

using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

void solve(ll T) {
  ll M, N, P;
  cin >> M >> N >> P;
  P--;

  vector<vector<ll>> data(M, vector<ll>(N));

  for (ll i = 0; i < M; ++i) {
    for (ll j = 0; j < N; ++j) {
      cin >> data[i][j];
    }
  }

  // find the maximum in each column;
  vector<ll> mx(N);
  for (ll j = 0; j < N; ++j) {
    ll t = data[0][j];

    for (ll i = 1; i < M; ++i) {
      t = max(t, data[i][j]);
    }

    mx[j] = t;
  }

  ll ans = 0;
  for (ll j = 0; j < N; ++j) {
    ans += mx[j] - data[P][j];
  }

  OUT(T) << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;

  for (ll i = 1; i <= T; ++i) solve(i);
}
