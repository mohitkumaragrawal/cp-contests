#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  ll n, k;
  cin >> n >> k;

  set<ll> ans;
  ll last_el = 1;
  ll diff = 1;
  ans.insert(1);

  while (ans.size() < n) {
    ll new_el = last_el + diff;
    if (new_el <= k) {
      ans.insert(new_el);
      last_el = new_el;
      diff++;
    } else {
      break;
    }
  }

  for (ll i = k; i >= 0; --i) {
    if (ans.size() < n) {
      if (!ans.count(i)) ans.insert(i);
    } else
      break;
  }

  for (ll x : ans) {
    cout << x << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
