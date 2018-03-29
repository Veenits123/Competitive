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
void rot(string& s) {
    int sum = 0;
    for(char c: s) sum += c-'A';
    for(char& c : s) {
        c = ((c - 'A' + sum) % 26) + 'A';
    }
}
int main() {
    SYNC
    string s, s1, s2; cin >> s;
    int n = ((int)s.length())/2;
    s1 = s.substr(0, n), s2 = s.substr(n, n);
    rot(s1); rot(s2);
    FOR0(i, n) {
        s1[i] = ((s1[i] - 'A' + (s2[i] - 'A')) % 26) + 'A';
    }
    cout << s1;
}