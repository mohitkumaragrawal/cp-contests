#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;

  while (T--) {
    int N;
    cin >> N;

    string s;
    cin >> s;

    string done = s;

    ll ans = 0;
    for (ll i = 1; i <= N; ++i) {
      for (ll j = i; j <= N; j += i) {
        if (s[j - 1] == '1') break;
        if (done[j - 1] == '0') {
          ans += i;
          done[j - 1] = '1';
        }
      }
    }

    cout << ans << endl;
  }
}