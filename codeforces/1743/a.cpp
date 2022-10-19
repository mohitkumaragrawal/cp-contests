#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "

using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

void solve() {
  int n;
  cin >> n;

  set<int> s;
  for (int i = 0; i <  n; ++i) {
    int x; cin >> x;
    s.insert(x);
  }

  ll sz = 10 - s.size();

  ll ans = (sz * (sz - 1)) / 2;
  ans *= 6;
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  
  int T;
  cin >> T;

  while (T--) {
    solve();
  }
}
