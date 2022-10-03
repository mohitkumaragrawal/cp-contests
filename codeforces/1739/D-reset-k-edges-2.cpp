#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> parent(n + 1);
  for (int i = 2; i <= n; ++i) {
    cin >> parent[i];
  }

  int low = 1, high = n - 1;

  while (low <= high) {
    int mid = (low + high) / 2;

    vector<int> height(n + 1, 0);
    int count = 0;

    for (int i = n; i >= 2; --i) {
      if (height[i] == mid - 1 && parent[i] != 1) {
        count++;
      } else {
        height[parent[i]] = max(height[parent[i]], height[i] + 1);
      }
    }

    if (count <= k) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  cout << low << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) solve();
}