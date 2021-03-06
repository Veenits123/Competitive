
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define EPS (1e-9)
#define PI 3.1415926535
#define inf ((int)1e9)
#define INF ((ll)9e18)
#define mod (1000000000 + 7)
#define newl '\n'
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
inline int mult(int a, int b) {return (1LL * a * b) % mod;}
inline int add(int a, int b) {return (a + b) % mod;}
const int N = 1e5 + 5;
int n, p, x[N], dp[N][2] = {};
vvi g(N);
int modexp(int a, int b) {
  int res = 1;
  for(;b;b>>=1) {
    if(b & 1)
      res = mult(res, a);
    a = mult(a, a);
  }
  return res;
}
int inv(int a) {
  return modexp(a, mod - 2);
}
void dfs(int u) {
  dp[u][x[u]] = 1;
  for(int v : g[u]) {
    dfs(v);
    dp[u][x[u]] = mult(dp[u][x[u]], add(dp[v][0], dp[v][1]));
  }
  if(!x[u]) {
    for(int v : g[u]) {
      dp[u][1] = add(dp[u][1], mult(dp[u][0], mult(inv(dp[v][1] + dp[v][0]), dp[v][1])));
    }
  }
}

int main() {
  SYNC;
  cin >> n;
  FOR0(i, n-1) {
    cin >> p;
    g[p].pb(i+1);
  }
  FOR0(i, n) {
    cin >> x[i];
  }
  dfs(0);
  cout << dp[0][1];
}
