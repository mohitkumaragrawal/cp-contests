#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  ll n;
  cin >> n;
  string s;
  cin >> s;

  vector<vector<bool>> ex(26, vector<bool>(26, false));
  for (int i = 1; i < n - 1; ++i) {
    int x1 = s[i] - 'a';
    int x2 = s[i + 1] - 'a';

    if (ex[x1][x2]) {
      cout << "YES\n";
      return;
    }

    ex[s[i - 1] - 'a'][s[i] - 'a'] = true;
  }
  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
