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

void solve() {
  ll N;
  cin >> N;

  vector<string> vs(N);
  for (ll i = 0; i < N; ++i) {
    cin >> vs[i];
  }

  vector<vector<ll>> ans(N);
  for (ll i = 0; i < N; ++i) {
    ll x = i + 1;
    ans[i].push_back(x);

    for (ll j = 0; j < N; ++j) {
      if (vs[i][j] == '1') {
        ans[j].push_back(x);
      }
    }
  }

  for (ll i = 0; i < N; ++i) {
    cout << ans[i].size() << " ";
    for (ll j = 0; j < ans[i].size(); ++j) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
