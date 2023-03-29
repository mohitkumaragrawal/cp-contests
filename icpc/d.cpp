#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case " << T << ": "
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

lld dist(lld x1, lld y1, lld x2, lld y2) {
  return sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

const lld ep = 1e-15;

void solve(ll T) {
  ll ulx, uly, lrx, lry;
  cin >> ulx >> uly >> lrx >> lry;

  ll dx, dy, n;
  cin >> dx >> dy >> n;

  vector<tuple<ll, ll, lld>> v(n);
  vector<pair<lld, lld>> range;

  for (ll i = 0; i < n; ++i) {
    ll x, y;
    lld r;
    cin >> x >> y >> r;
    v.emplace_back(x, y, r);
    lld d = dist(x, y, dx, dy);

    if (abs(d - r) <= ep || d >= r) {
      range.emplace_back(d - r, d + r);
    } else {
      range.emplace_back(0, r + d);
    }
  }

  sort(all(range));

  vector<ll> dists = {abs(dy - lry), abs(uly - dy), abs(dx - ulx),
                      abs(lrx - dx)};

  ll max_radius = *min_element(all(dists));

  dbg(max_radius);

  vector<pll> range2;
  for (auto [x, y] : range) {
    bool x_int = (ceil(x) == floor(x));
    bool y_int = (ceil(y) == floor(y));

    dbg(x, y, x_int, y_int);

    ll s = x_int ? ceil(x) + 1 : ceil(x);
    ll e = y_int ? floor(y) - 1 : floor(y);

    range2.emplace_back(s, e);

    dbg(s, e);
  }

  vector<pll> range3;
  sort(all(range2));

  if (range2.size() > 0) range3.emplace_back(range2[0].first, range2[0].second);

  for (ll i = 1; i < range2.size(); ++i) {
    auto [x1, y1] = range3.back();
    auto [x2, y2] = range2[i];

    if (x2 > y1) {
      range3.emplace_back(x2, y2);
    } else {
      range3.back().second = max(y1, y2);
    }
  }

  vector<bool> invalid(max_radius + 1, false);

  for (auto [x, y] : range3) {
    for (ll i = x; i <= y; ++i) {
      if (i > max_radius) break;
      invalid[i] = true;
    }
  }

  ll cnt = 0;
  for (ll R = 1; R <= max_radius; ++R) {
    if (!invalid[R]) ++cnt;
  }

  OUT(T) << cnt << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  for (ll t = 1; t <= T; ++t) solve(t);
}
