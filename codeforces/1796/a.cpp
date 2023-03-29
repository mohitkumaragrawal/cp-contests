#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

string text;

void solve() {
  ll n;
  cin >> n;
  string s;
  cin >> s;

  if (text.find(s) != text.npos) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  for (ll i = 1; i <= 100000; ++i) {
    if (i % 3 == 0) text.push_back('F');
    if (i % 5 == 0) text.push_back('B');
  }

  ll T;
  cin >> T;
  while (T--) solve();
}
