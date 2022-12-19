#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  string s;
  cin >> s;

  ll a = s[0] - '0';
  ll b = s[2] - '0';

  cout << a + b << endl;
}

int main() {
#ifdef _MOHIT
  cout << "mohit" << endl;
#endif

  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
