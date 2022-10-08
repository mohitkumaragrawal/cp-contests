#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

ll r[3], c[3];

void solve() {
  ll N;
  cin >> N;

  for (int i = 0; i < 3; ++i) {
    cin >> r[i] >> c[i];
  }

  ll x, y;
  cin >> x >> y;

  for (int i = 0; i < 3; ++i) {
    if (r[i] == 1 && c[i] == 1) {
      if (x == 1 || y == 1) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
      return;
    }

    if (r[i] == N && c[i] == N) {
      if (x == N || y == N) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
      return;
    }

    if (r[i] == 1 && c[i] == N) {
      if (x == 1 || y == N) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
      return;
    }

    if (r[i] == N && c[i] == 1) {
      if (x == N || y == 1) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
      return;
    }
  }

  ll p = (x + y) % 1;

  int oc = 0, ec = 0;
  for (int i = 0; i < 3; ++i) {
    ll s = r[i] + c[i];
    if (s % 2 == 0) {
      ec++;
    } else {
      oc++;
    }
  }

  if (ec > oc) {
    if (p == 0) {
      cout << "YES" << endl;
      return;
    }

    ll x1, y1;
    for (int i = 0; i < 3; ++i) {
      if ((r[i] + c[i]) % 2 == 1) {
        x1 = r[i];
        y1 = c[i];
        break;
      }
    }

    if (((x & 1) == (x1 & 1)) && (y & 1) == (y1 & 1)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else {
    if (p == 1) {
      cout << "NO" << endl;
      return;
    }

    ll x1, y1;
    for (int i = 0; i < 3; ++i) {
      if ((r[i] + c[i]) % 2 == 0) {
        x1 = r[i];
        y1 = c[i];
        break;
      }
    }

    if (((x & 1) == (x1 & 1)) && (y & 1) == (y1 & 1)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) solve();
}