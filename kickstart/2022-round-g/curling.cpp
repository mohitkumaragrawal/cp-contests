#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "

using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

ll sq_dist(ll x, ll y) {
  return x * x + y * y;
}

void solve(ll T) {
  ll rs, rh;
  cin >> rs >> rh;

  ll N;
  cin >> N;
  vector<pair<ll, ll>> red;

  for (ll i = 0; i < N; ++i) {
    ll x, y;
    cin >> x >> y;
    red.push_back({x, y});
  }

  ll M;
  cin >> M;
  vector<pair<ll, ll>> yellow;
  for (ll i = 0; i < M; ++i) {
    ll x, y;
    cin >> x >> y;
    yellow.push_back({x, y});
  }
  
  ll th = rh + rs;
  th *= th;

  vector<ll> rd, yd;
  ll d;
  for (int i = 0; i < N; ++i) {
    d = sq_dist(red[i].first, red[i].second);

    if (d <= th) {
      rd.push_back(d);
    }
  }
  sort(all(rd));

  for (int i = 0; i < M; ++i) {
    d = sq_dist(yellow[i].first, yellow[i].second);

    if (d <= th) {
      yd.push_back(d);
    }
  }
  sort(all(yd));

  if (rd.size() == 0 || yd.size() == 0) {
    OUT(T) << rd.size() << " " << yd.size() << endl;
    return;
  }

  if (rd[0] < yd[0]) {
    ll red_ans = upper_bound(all(rd), yd[0]) - begin(rd);
    OUT(T) << red_ans << " 0" << endl;
  } else {
    ll yellow_ans = upper_bound(all(yd), rd[0]) - begin(yd);
    OUT(T) << "0 " << yellow_ans << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  
  ll T;
  cin >> T;

  for (ll i = 1; i <= T; ++i) solve(i);
}
