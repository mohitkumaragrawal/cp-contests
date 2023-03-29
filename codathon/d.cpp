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

//
ll msb(string& a) {
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] == '1') return i;
  }
  return -1;
}

void do_op(string& a, ll k) {
  string shift(a.size(), '0');
  for (int i = 0; i < a.size(); ++i) {
    int j = i + k;
    if (j < a.size() && j >= 0) shift[i] = a[j];
  }

  for (int i = 0; i < a.size(); ++i) {
    if (shift[i] == '1') {
      if (a[i] == '0')
        a[i] = '1';
      else
        a[i] = '0';
    }
  }
}

void solve() {
  ll n;
  cin >> n;

  string a, b;
  cin >> a >> b;

  if (msb(b) == -1) {
    if (msb(a) == -1) {
      cout << "0\n";
    } else {
      cout << "-1\n";
    }
    return;
  }

  vector<int> ans;

  bool fix_msb = false;

  for (int i = 0; i < n; ++i) {
    if (a[i] == b[i]) continue;

    int j = msb(a);
    if (j == -1) {
      cout << "-1\n";
      return;
    }

    if (j == i) {
      fix_msb = true;
      continue;
    }

    int op = j - i;
    do_op(a, op);
    ans.push_back(op);

    dbg(i, j, op, a);
  }

  if (fix_msb) {
    int lsb = -1;
    for (int i = n - 1; i >= 0; --i) {
      if (a[i] == '1') {
        lsb = i;
        break;
      }
    }

    if (lsb == -1) {
      cout << "-1\n";
      return;
    }

    int j = msb(a);

    for (ll k = j; k >= 0; --k) {
      if (a[k] == b[k]) continue;

      int op = lsb - k;
      ans.push_back(op);
      do_op(a, op);
    }
  }

  cout << ans.size() << '\n';
  for (int i : ans) cout << i << ' ';
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
