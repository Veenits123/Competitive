// Gear4        
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
template<typename T> using V = vector<T>;
template<typename T, typename U> using P = pair<T,U>;
using ld = long double;
using ll = long long;
#define endl '\n'
const int inf = 1e9, mod = 1e9 + 7;
const ll INF = 9e18;
const ld EPS = 1e-9, PI = acosl(-1.0);
const int N = 1e5 + 5;
int n, m;
ll curAns = INF;
P<int, int> a[N];
ll val(ll n, ll d) {
    return (n + d - 1)/d;
}
int main() {
    SYNC
    cin >> n >> m;
    FOR0(i, n) cin >> a[i].second >> a[i].first;
    sort(a, a+n, [&](auto l, auto r) {
        return l.first * 1LL * r.second < l.second * 1LL * r.first;
    });
    ll c = 0, p = 0;
    FOR0(i, n) {
        if(val(m+c+a[i].first, p+a[i].second) <= curAns) {
            c += a[i].first;
            p += a[i].second;
            curAns = val(m+c, p);
        }
    }
    cout << curAns;
}