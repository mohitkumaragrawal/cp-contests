#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>,
// rb_tree_tag,tree_order_statistics_node_update>

#define fi first
#define se second
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vl vector<long long>
#define mii map<int, int>
#define mll map<long long, long long>
#define qi queue<int>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int> >
#define mod 1000000007
#define inf INT_MAX
#define ninf INT_MIN
#define linf LLONG_MAX
#define lninf LLONG_MIN
#define ld long double
#define w(t) \
  int t;     \
  cin >> t;  \
  while (t--)
#define f(i, x) for (int i = 0; i < (int)x; i++)
#define f1(i, x) for (int i = 1; i <= (int)x; i++)
#define rep(i, a, b) for (int i = (int)a; i <= (int)b; i++)
#define yes() cout << "YES" << endl
#define no() cout << "NO" << endl
#define endl '\n'
#define all(arr) arr.begin(), arr.end()

void parr(vl arr) {
  for (auto it : arr) {
    cout << it << " ";
  }
  cout << endl;
}

void init_code() {
#ifndef ONLINE_JUDGE

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

#endif
}

// noob_coder becoming more noob.

int main() {
  // init_code();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  w(t) {
    ll n = 0, m = 0, i = 0, j = 0, k = 0, a = 0, b = 0, c = 0, d = 0, cnt = 0,
       ans = 0, sum = 0, sol = 0, flag = 0;
    string str[2], ttr;
    char ch;

    cin >> n >> str[0] >> str[1];

    for (i = 0; i < n; i++) {
      if (str[0][i] == 'B' && str[1][i] != 'B') {
        a = 0;
        break;
      } else if (str[0][i] != 'B' && str[1][i] == 'B') {
        a = 1;
        break;
      }
    }

    for (; i < n; i++) {
      if (str[a][i] != 'B' && str[a ^ 1][i] == 'B') {
        flag = 1;
        break;
      } else if (str[a][i] == 'B' && str[a ^ 1][i] == 'B') {
        a ^= 1;
      }
    }
    if (flag == 1)
      no();
    else
      yes();
  }

  return 0;
}
