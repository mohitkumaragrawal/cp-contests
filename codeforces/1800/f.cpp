#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#ifdef _DEBUG
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void solve() {
  dbg("input");
  ll n;
  cin >> n;

  vector<string> vs(n);
  for (ll i = 0; i < n; ++i) cin >> vs[i];

  vector<vector<bool>> contains(n, vector<bool>(26, false));
  for (ll i = 0; i < n; ++i) {
    for (char ch : vs[i]) {
      contains[i][ch - 'a'] = true;
    }
  }

  dbg("done");

  auto f = [](string& s) {
    vector<ll> cnt(26);
    for (char ch : s) {
      cnt[ch - 'a']++;
    }

    ll ans = 0;
    for (ll i = 0; i < 26; ++i) {
      if (cnt[i] % 2 == 1) {
        ans |= (1 << i);
      }
    }

    return ans;
  };

  vector<ll> v(n);
  for (ll i = 0; i < n; ++i) v[i] = f(vs[i]);

  dbg("done pre");

  ll ans = 0;

  ll num = (1 << 26) - 1;

  unordered_map<ll, ll> mp;
  for (ll i = 0; i < 26; ++i) {
    mp.clear();
    ll k = num ^ (1 << i);

    for (ll j = 0; j < n; ++j) {
      if (contains[j][i]) continue;

      ll x = v[j] ^ k;
      ans += mp[x];

      mp[v[j]]++;
    }
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
