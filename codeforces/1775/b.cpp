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

  map<int, int> freq;

  vector<vector<int>> set_bits(n);
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;

    for (int j = 0; j < k; ++j) {
      int p;
      cin >> p;
      set_bits[i].push_back(p);

      freq[p]++;
    }
  }

  for (int i = 0; i < n; ++i) {
    bool ok = true;

    for (int pos : set_bits[i]) {
      if (freq[pos] == 1) {
        ok = false;
        break;
      }
    }

    if (ok) {
      cout << "YES\n";
      return;
    }
  }

  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
