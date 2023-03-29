#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

void solve() {
  ll n, ans;
  cin >> n;
  ans = (sqrtl(n));
  if (ans * ans == n) {
    cout << ans - 1 << endl;
    return;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll test;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
