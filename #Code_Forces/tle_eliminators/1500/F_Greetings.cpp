#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define MOD 1000000007
typedef long long ll;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i].second >> v[i].first;
  sort(v.begin(), v.end());
  ordered_set<int> s;
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    int x = (ll)s.size() - (ll)s.order_of_key(v[i].second);
    ans += x;
    s.insert(v[i].second);
  }
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}