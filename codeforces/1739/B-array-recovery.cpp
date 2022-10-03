#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a;

  int first;
  cin >> first;
  a.push_back(first);

  bool success = true;

  for (int i = 2; i <= n; ++i) {
    int x;
    cin >> x;

    if (x == 0) {
      a.push_back(a.back());
      continue;
    }

    if (a.back() - x >= 0) {
      // failed;
      success = false;
    }

    a.push_back(a.back() + x);
  }

  if (!success) {
    cout << -1 << endl;
  } else {
    for (int i : a) {
      cout << i << " ";
    }
    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}