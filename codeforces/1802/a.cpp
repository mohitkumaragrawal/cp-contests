#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);

  for (ll i = 0; i < n; ++i) cin >> a[i];

  vector<ll> pos, neg;
  for (ll i = 0; i < n; ++i) {
    if (a[i] > 0)
      pos.push_back(a[i]);
    else
      neg.push_back(a[i]);
  }

  ll st = 0;
  for (ll i = 0; i < pos.size(); ++i) {
    cout << ++st << " ";
  }

  for (ll i = 0; i < neg.size(); ++i) {
    cout << --st << " ";
  }
  cout << '\n';

  set<ll> s(all(pos));

  st = 1;

  for (ll i = 0; i < neg.size(); ++i) {
    cout << "1 0 ";
    s.erase(neg[i]);
  }

  for (ll i = 0; i < pos.size() - neg.size(); ++i) {
    cout << i + 1 << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
