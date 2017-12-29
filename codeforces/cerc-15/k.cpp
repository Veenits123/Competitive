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
const int N = 2e5 + 5;
int nxt[N], indeg[N] = {}, n, f[N], loc[N] = {};
int main() {
    SYNC
    cin >> n;
    FOR(i, 1, 2*n + 1) {
        cin >> nxt[i];
        indeg[nxt[i]]++;
    }
    queue<int> q;
    FOR(i, 1, 2*n + 1) if(!indeg[i]) q.push(i);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        loc[u] = 1;
        if(!loc[nxt[u]]) {
            loc[nxt[u]] = 2;
            indeg[nxt[nxt[u]]]--;
            if(!indeg[nxt[nxt[u]]]) q.push(nxt[nxt[u]]);
        }
    }
    int found = 0;
    FOR(i, 1, n + 1) {
        if(!loc[i]) {
            loc[i] = 1;
            found = 1;
        }
    }
    if(!found) {
        FOR(i, n + 1, 2*n + 1) {
            if(!loc[i]) {
                loc[i] = 1;
                found = 1;
            }
        }
    }
    FOR(i, 1, 2*n + 1) if(loc[i] == 1) cout << i << " ";
}