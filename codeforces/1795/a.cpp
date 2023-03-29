#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

bool isOk(string& str) {
  if (str.size() <= 1) return true;
  char prev = str[0];

  for (ll i = 1; i < str.size(); ++i) {
    if (str[i] == prev) return false;
    prev = str[i];
  }

  return true;
}

void solve() {
  ll m, n;
  cin >> m >> n;

  string a, b;
  cin >> a >> b;

  // move from to b;

  if (isOk(a) && isOk(b)) {
    cout << "YES" << endl;
    return;
  }

  for (ll i = 1; i < m; ++i) {
    string a_new = a.substr(0, i);

    string a_rev = a.substr(i);
    reverse(all(a_rev));

    string b_new = b + a_rev;

    if (isOk(a_new) && isOk(b_new)) {
      cout << "YES" << endl;
      return;
    }
  }

  for (ll i = 1; i < n; ++i) {
    string b_new = b.substr(0, i);

    string b_rev = b.substr(i);
    reverse(all(b_rev));

    string a_new = a + b_rev;

    if (isOk(a_new) && isOk(b_new)) {
      cout << "YES" << endl;
      return;
    }
  }

  cout << "NO" << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
