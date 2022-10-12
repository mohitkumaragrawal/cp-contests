#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  if (s.size() & 1) {
    cout << "YES" << endl;
    return;
  }

  int ec = 0;
  for (char ch: s) {
    if (ch == '1') ++ec;
  }

  if (ec & 1) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
}