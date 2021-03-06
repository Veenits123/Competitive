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
struct node {
    int val, prior, size, sum, lsum, rsum, msum;
    node *l, *r;
} temp;
typedef node* pnode;
int sz(pnode t) { return t ? t->size: 0; }
void upd_sz(pnode t) { if(t) t->size = sz(t->l) + 1 + sz(t->r); }
void combine(pnode &t, pnode l, pnode r) {
    if(!l || !r) return void(t=l?l:r);
    temp.sum = l->sum + r->sum;
    temp.lsum = max(l->lsum, l->sum + r->lsum);
    temp.rsum = max(r->sum + l->rsum, r->rsum);
    temp.msum = max(max(l->msum, r->msum), l->rsum + r->lsum);
    t->sum=temp.sum,t->lsum=temp.lsum,t->rsum=temp.rsum,t->msum=temp.msum;
}
void reset(pnode t) {
    if(t) t->sum=t->msum=t->lsum=t->rsum=t->val;
}
void operation(pnode t) {
    if(!t) return;
    reset(t);
    combine(t,t->l,t); combine(t,t,t->r);
}
void split(pnode t, pnode& l, pnode &r, int pos, int add=0) {
    if(!t) return void(l=r=NULL);
    int cur_pos = sz(t->l) + add + 1;
    if(pos<cur_pos) split(t->l,l,t->l,pos,add),r=t;
    else split(t->r,t->r,r,pos,cur_pos),l=t;
    upd_sz(t); operation(t);
}
void merge(pnode& t, pnode l, pnode r) {
    if(!l||!r) t=l?l:r;
    else if(l->prior>r->prior) merge(l->r,l->r,r),t=l;
    else merge(r->l,l,r->l), t=r;
    upd_sz(t); operation(t);
}
pnode init(int x) {
    pnode ret = (pnode)malloc(sizeof(node));
    ret->val=x,ret->prior=rand(),ret->l=ret->r=NULL,ret->size=1;
    reset(ret);
    return ret;
}
void insert(pnode& t, pnode it, int pos) {
    pnode l;
    split(t,l,t,pos-1); merge(l,l,it); merge(t,l,t);
}
void del(pnode& t, int pos) {
    pnode l, mid;
    split(t,l,t,pos-1); split(t,mid,t,1); merge(t,l,t);
    free(mid);
}
void upd(pnode& t, int pos, int val) {
    pnode l, r;
    split(t, l, t, pos-1); split(t, t, r, 1);
    t->val = val;
    merge(t,l,t); merge(t,t,r);
}
int query(pnode& t, int lq, int rq) {
    pnode l, r;
    split(t, l, t, lq-1); split(t, t, r, rq-lq+1);
    int ans = t->msum;
    merge(t,l,t); merge(t,t,r);
    return ans;
}
int n, q, a;
pnode treap=NULL;
int main() {
    SYNC
    srand(time(0));
    cin >> n;
    FOR0(i, n) {
        cin >> a;
        insert(treap, init(a), i+1);
    }
    cin >> q;
    int x,y; char type;
    while(q--) {
        cin >> type;
        if(type=='D') {
            cin >> x;
            del(treap,x);
        } else {
            cin >> x >> y;
            if(type=='I') insert(treap,init(y), x);
            else if(type=='R') upd(treap, x, y);
            else cout << query(treap, x, y) << endl;
        }
    }
}