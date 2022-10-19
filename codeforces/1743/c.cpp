#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "

using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

vector<pair<ll, ll>> islands(string& lid) {
  ll N = lid.size(); 

  vector<pair<ll, ll>> vpr;

  ll left = lid.find_first_of('1');
  ll right = left;

  while (right < N && left != lid.npos) {
    if (lid[right] == '0') {
      vpr.push_back({left, right-1});

      left = lid.find_first_of('1', right);
      right = left;

      if (left == lid.npos) {
        break;
      }
      continue;
    }

    right++;
  }
  if (left != lid.npos) {
    vpr.push_back({left, N-1});
  }

  return vpr;
}

void solve() {
  ll N;
  cin >> N;

  string lid;
  vector<ll> arr(N);

  cin >> lid;
  for (ll& i: arr) cin >> i;

  vector<ll> pre(N);
  pre[0] = arr[0];
  for (ll i = 1; i < N; ++i) pre[i] = pre[i-1] + arr[i];

  vector<pair<ll, ll>> vpr = islands(lid);



  ll ans = 0;

  ll left, right;
  for (auto pr: vpr) {
    left = pr.first - 1;
    right = pr.second;
    if (left < 0){ 
      left = 0;
      ans += pre[right];
      continue;
    }

    ll m_val = arr[left];
    ll s = arr[left];
    for (ll i = left + 1; i <= right; ++i) {
      m_val = min(m_val, arr[i]);
      s += arr[i];
    }

    ans += s - m_val;
  }


  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;

  while (T--) solve();
}
