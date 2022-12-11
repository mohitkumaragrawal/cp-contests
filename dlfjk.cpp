#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007
#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);

const int N = 1e5 + 10;

void solve() {
  ll n;
  cin >> n;

  vector<ll> arr(n);
  for (ll i = 0; i < n; ++i) cin >> arr[i];

  vector<vector<ll>> ans;
  for (ll i = 0; i < n - 1; i += 2) {
    vector<ll> tmp;
    ll m = min(arr[i], arr[i + 1]);
    arr[i] = m;
    arr[i + 1] = mod;

    tmp.push_back(i + 1);
    tmp.push_back(i + 2);
    tmp.push_back(m);
    tmp.push_back(mod);

    ans.push_back(tmp);
  }

  cout << ans.size() << endl;
  for (auto v : ans) {
    for (auto x : v) {
      cout << x << " ";
    }
    cout << endl;
  }
}

int main() {
  fast;
  int t = 1;
  cin >> t;

  // while (t--) solve();

  stringstream sout;

  for (int testcase = 1; testcase <= t; ++testcase) {
    if (testcase == 10) {
      int n;
      cin >> n;
      int arr[n];
      for (int i = 0; i < n; i++) {
        cin >> arr[i];
      }
      for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
      }
      cout << endl;
    }

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    vector<vector<int>> v;
    bool flag = 1;
    for (int i = 1; i < n; i++) {
      vector<int> temp;
      if (__gcd(arr[i - 1], arr[i]) != 1 && flag == 1) {
        temp.push_back(i);
        temp.push_back(i + 1);
        temp.push_back(mod);
        temp.push_back(min(arr[i], arr[i - 1]));
        arr[i] = min(arr[i], arr[i - 1]);
        arr[i - 1] = mod;
        v.push_back(temp);
        flag = 0;
      } else if (__gcd(arr[i - 1], arr[i]) != 1 && flag == 0) {
        temp.push_back(i);
        temp.push_back(i + 1);
        temp.push_back(min(arr[i], arr[i - 1]));
        temp.push_back(mod);
        arr[i - 1] = min(arr[i], arr[i - 1]);
        arr[i] = mod;
        v.push_back(temp);
      }
    }
    sout << v.size() << "\n";
    for (auto it : v) {
      for (auto m : it) {
        sout << m << " ";
      }
      sout << "\n";
    }
    for (int i = 0; i < n; i++) {
      sout << arr[i] << " ";
    }
    sout << "\n";
  }
  cout << sout.str() << endl;
  return 0;
}
