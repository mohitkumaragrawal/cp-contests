#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

void solve() {
  int n;
  cin >> n;

  int box1[n];
  for (int i = 0; i < n; ++i) cin >> box1[i];

  int m;
  cin >> m;

  int box2[m];
  for (int i = 0; i < m; ++i) cin >> box2[i];

  int max_el;

  {
    // Compressing..
    vector<int> arr;
    for (int i = 0; i < n; ++i) arr.push_back(box1[i]);
    for (int i = 0; i < m; ++i) arr.push_back(box2[i]);

    sort(all(arr));
    arr.erase(unique(all(arr)), arr.end());

    max_el = arr.size();

    map<int, int> mp;
    for (int i = 0; i < arr.size(); ++i) {
      mp[arr[i]] = i;
    }

    for (int i = 0; i < n; ++i) box1[i] = mp[box1[i]];
    for (int i = 0; i < m; ++i) box2[i] = mp[box2[i]];
  }

  bool exists[max_el];
  for (int i = 0; i < max_el; ++i) exists[i] = false;

  for (int i = 0; i < m; ++i) {
    exists[box2[i]] = true;
  }

  vector<vector<int>> dp(n, vector<int>(max_el + 1, INT_MAX));

  for (int j = 0; j < max_el; ++j) {
    if (j == box1[0]) {
      dp[0][j] = 0;
    } else if (exists[j]) {
      dp[0][j] = 1;
    }
  }

  for (int i = 1; i < n; ++i) {
    int prefix_min[max_el];
    prefix_min[0] = dp[i - 1][0];

    for (int j = 1; j < max_el; ++j) {
      prefix_min[j] = min(prefix_min[j - 1], dp[i - 1][j]);
    }

    for (int j = 1; j < max_el; ++j) {
      int prev = prefix_min[j - 1];

      if (prev == INT_MAX) {
        dp[i][j] = INT_MAX;
      } else if (j == box1[i]) {
        dp[i][j] = prev;
      } else if (exists[j]) {
        dp[i][j] = 1 + prev;
      } else {
        dp[i][j] = INT_MAX;
      }
    }
  }

  int ans = INT_MAX;
  for (int j = 0; j < max_el; ++j) {
    ans = min(ans, dp[n - 1][j]);
  }
  if (ans == INT_MAX)
    cout << -1 << endl;
  else
    cout << ans << endl;
}

#define all(x) begin(x), end(x)

int makeIncreasing(vector<int>& b1, vector<int>& b2) {
  int n = b1.size();
  int m = b2.size();

  int box1[n];
  for (int i = 0; i < n; ++i) box1[i] = b1[i];

  int box2[m];
  for (int i = 0; i < m; ++i) box2[i] = b2[i];

  map<int, bool> exists;

  int max_el;

  {
    // Compressing..
    vector<int> arr;
    for (int i = 0; i < n; ++i) arr.push_back(box1[i]);
    for (int i = 0; i < m; ++i) arr.push_back(box2[i]);

    sort(all(arr));
    arr.erase(unique(all(arr)), arr.end());

    max_el = arr.size();

    map<int, int> mp;
    for (int i = 0; i < arr.size(); ++i) {
      mp[arr[i]] = i;
    }

    for (int i = 0; i < n; ++i) box1[i] = mp[box1[i]];
    for (int i = 0; i < m; ++i) box2[i] = mp[box2[i]];

    for (int i = 0; i < m; ++i) {
      exists[box2[i]] = true;
    }
  }

  vector<vector<int>> dp(n, vector<int>(max_el + 1, INT_MAX));

  for (int j = 0; j < max_el; ++j) {
    if (j == box1[0]) {
      dp[0][j] = 0;
    } else if (exists[j]) {
      dp[0][j] = 1;
    }
  }

  for (int i = 1; i < n; ++i) {
    int prefix_min[max_el];
    prefix_min[0] = dp[i - 1][0];

    for (int j = 1; j < max_el; ++j) {
      prefix_min[j] = min(prefix_min[j - 1], dp[i - 1][j]);
    }

    for (int j = 1; j < max_el; ++j) {
      int prev = prefix_min[j - 1];

      if (prev == INT_MAX) {
        dp[i][j] = INT_MAX;
      } else if (j == box1[i]) {
        dp[i][j] = prev;
      } else if (exists[j]) {
        dp[i][j] = 1 + prev;
      } else {
        dp[i][j] = INT_MAX;
      }
    }
  }

  int ans = INT_MAX;
  for (int j = 0; j < max_el; ++j) {
    ans = min(ans, dp[n - 1][j]);
  }
  if (ans == INT_MAX)
    cout << -1 << endl;
  else
    cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
