#include <bits/stdc++.h>

using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T, typename ComparatorFn = less<T>>
// using ordered_set = tree<T, null_type, ComparatorFn, rb_tree_tag,
//                          tree_order_statistics_node_update>;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll MOD = 1e9 + 7;

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

ll N;
ll A[200005];

void solve() {
  ll N, H;
  cin >> N >> H;

  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
  }
  sort(A, A + N);

  // Should check for every permutation of pills (there are only 3);

  vector<ll> x = {2, 2, 3};
  ll ans = 0;

  do {
    ll cnt = 0, idx = 0, h = H;

    for (ll i = 0; i < N; ++i) {
      ll val = A[i];

      while (h <= val && idx < 3) {
        h *= x[idx];
        idx++;
      }

      if (h > val) {
        h += val / 2;
        cnt++;
        continue;
      }

      break;
    }

    ans = max(ans, cnt);

  } while (next_permutation(all(x)));

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
