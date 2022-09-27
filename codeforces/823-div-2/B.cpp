#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> T(N);

    for (ll &i : A) cin >> i;
    for (ll &i : T) cin >> i;

    ll a = 0;
    ll b = 0;
    for (ll i = 1; i < N; ++i) {
      if ((A[i] + T[i]) > (A[a] + T[a])) {
        a = i;
      }
      if ((A[i] - T[i]) < (A[b] - T[b])) {
        b = i;
      }
    }
    double ans = 0.5 * (A[a] + A[b] + T[a] - T[b]);
    cout << fixed << setprecision(6) << ans << endl;
  }
}