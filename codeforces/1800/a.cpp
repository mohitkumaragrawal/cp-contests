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
  string s;
  cin >> n >> s;

  reverse(all(s));

  string t = "meow";

  vector<ll> cnt(4);

  for (ll i = 0; i < 4; ++i) {
    while (!s.empty() && tolower(s.back()) == t[i]) {
      s.pop_back();
      cnt[i]++;
    }
  }
  if (!s.empty()) {
    cout << "NO\n";
    return;
  }

  ll mn = *min_element(all(cnt));
  if (mn == 0) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
