#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

void solve() {
  string s;
  cin >> s;

  vector<int> f(26, 0);
  for (char ch : s) {
    f[ch - 'a']++;
  }

  int el = *max_element(all(f));
  bool ok = true;
  for (int i = 0; i < 26; ++i) {
    if (f[i] == 0) continue;

    if (f[i] != el) {
      ok = false;
      break;
    }
  }

  if (ok) {
    cout << "YES\n";
    return;
  }

  for (int i = 0; i < 26; ++i) {
    if (f[i] == 0) continue;

    f[i]--;

    el = *max_element(all(f));

    ok = true;

    for (int j = 0; j < 26; ++j) {
      if (f[j] == 0) continue;

      if (f[j] != el) {
        ok = false;
        break;
      }
    }

    if (ok) {
      cout << "YES\n";
      return;
    }

    f[i]++;
  }

  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();
  //
  solve();
}
