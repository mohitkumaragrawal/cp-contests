#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

#ifdef _DEBUG
#define __dis cout << "\033[1;31m* (" << __LINE__ << "):\033[0m "
#define LOG(x) __dis << x << endl
#define __m(x) #x "=" << x << "\t"
#define DEBUG(x) __dis << __m(x) << endl
#define DEBUG2(x, y) __dis << __m(x) << __m(y) << endl
#define DEBUG3(x, y, z) __dis << __m(x) << __m(y) << __m(z) << endl
#define DEBUG4(x, y, z, w) __dis << __m(x) << __m(y) << __m(z) << __m(w) << end
#else
#define endl '\n'
#define LOG(X)
#define DEBUG(X)
#define DEBUG2(x, y)
#define DEBUG3(x, y, z)
#define DEBUG4(x, y, z, w)
#endif

// B is the given array, loc is the index of element in B;
ll loc[200005], B[200005], A[200005];

void solve() {
  ll N;
  cin >> N;

  for (ll i = 1; i <= N; ++i) loc[i] = -1;

  ll half = N / 2;

  for (ll i = 0; i < half; ++i) {
    cin >> B[i];
  }

  for (ll i = 0; i < half; ++i) {
    if (loc[B[i]] != -1) {
      cout << -1 << endl;
      return;
    }
    loc[B[i]] = i;
  }

  priority_queue<ll> q;
  for (ll i = N; i >= 1; --i) {
    if (loc[i] == -1) {
      if (q.empty()) {
        cout << -1 << endl;
        return;
      }

      ll idx = q.top();
      q.pop();

      A[idx] = i;
    } else {
      q.push(loc[i]);
    }
  }

  for (ll i = 0; i < half; ++i) {
    cout << A[i] << " " << B[i] << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
