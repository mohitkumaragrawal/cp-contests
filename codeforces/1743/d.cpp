#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "

using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

string take_or(string a, string b) {
  string res = a;

  for (ll i = 1; i <= b.size(); ++i) {
    if (b[b.size() - i] == '1') {
      res[res.size() - i] = '1';
    }
  }
  return res;
}

// a < b ?
bool compare(string a, string b) {
  if (a.size() < b.size()) {
    return true;
  } else if (a.size() > b.size()) {
    return false;
  }

  for (ll i = 0; i < a.size(); ++i) {
    if (a[i] == b[i]) continue;

    if (a[i] == '1') {
      return false;
    } else {
      return true;
    }
  }

  return true;
}


void solve() {
  ll N;
  cin >> N;

  string s;
  cin >> s;

  s.erase(s.begin(), find(all(s), '1'));
  N = s.size();

  ll z = s.find('0');
  ll length = N - z;

  string ans = s;

  for (ll i = 0; i < z;  ++i) {
    string s2 = s.substr(i, length);

    string res = take_or(s, s2);
    if (compare(ans, res)) {
      ans = res;
    }
  }

  if (ans.empty()) {
    cout << "0" << endl;
    return;
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  solve();
}
