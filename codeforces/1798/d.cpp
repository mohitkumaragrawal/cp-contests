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

  multiset<ll> st;
  for (ll i = 0; i < n; ++i) st.insert(a[i]);

  ll num = *(--st.end()) - *st.begin();

  if (num == 0) {
    if (a[0] >= 0) {
      cout << "No\n";
      return;
    }
  }

  vector<ll> ans;
  ll pre = 0;

  for (ll i = 0; i < n; ++i) {
    if (pre == 0) {
      auto it = st.end();
      it--;

      ans.push_back(*it);
      pre += *it;
      st.erase(it);
      continue;
    }

    if (pre > 0) {
      ll val = -pre;
      auto it = st.lower_bound(val);

      if (it != st.end()) {
        if (pre + *it >= num) {
          if (it != st.begin()) {
            it--;
          } else {
            cout << "No\n";
            return;
          }
        }
      } else {
        it = st.end();
        --it;
      }

      pre += *it;
      ans.push_back(*it);
      st.erase(it);
      continue;
    }

    if (pre < 0) {
      auto it = st.end();
      --it;

      pre += *it;
      ans.push_back(*it);
      st.erase(it);
      continue;
    }
  }

  cout << "Yes\n";
  for (ll i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
