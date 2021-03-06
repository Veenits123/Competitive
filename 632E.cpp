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
#define INF ((int)1e9)
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef int ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const long double PI=acos(-1.0);
typedef long double ld;
typedef vector<ll> VL;
int bits(int x){
    int r=0;
    while(x){
        r++;
        x>>=1;
    }
    return r;
}
int reverseBits(int x,int b){
    int r=0;
    for(int i=0;i<b;i++){
        r<<=1;
        r|=(x&1);
        x>>=1;
    }
    return r;
}
class Complex{
    public:
    ld r,i;
    Complex(){r=0.0;i=0.0;}
    Complex(ld a,ld b){r=a;i=b;}
};
Complex operator*(Complex a,Complex b){
    return Complex(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);
}
Complex operator-(Complex a,Complex b){
    return Complex(a.r-b.r,a.i-b.i);
}
Complex operator+(Complex a,Complex b){
    return Complex(a.r+b.r,a.i+b.i);
}
Complex operator/(Complex a,ld b){
    return Complex(a.r/b,a.i/b);
}
Complex EXP(ld theta){
    return Complex(cos(theta),sin(theta));
}
typedef vector<Complex> VC;
void FFT(VC& A,int inv){
    int l=A.size();
    int b=bits(l)-1;
    VC a(A);
    for(int i=0;i<l;i++){
        A[reverseBits(i,b)]=a[i];
    }
    for(int i=1;i<=b;i++){
        int m=(1<<i);
        int n=m>>1;
        Complex wn=EXP((ld)inv*(ld)2.0*PI/(ld)m);
        for(int j=0;j<l;j+=m){
            Complex w(1.0,0.0);
            for(int k=j;k<j+n;k++){
                Complex t1=A[k]+w*A[k+n];
                Complex t2=A[k]-w*A[k+n];
                A[k]=t1;
                A[k+n]=t2;
                w=w*wn;
            }
        }
    }
    if(inv==-1){
        for(auto &i:A){
            i=i/(ld)l;
        }
    }
}
void Convolution(VL& a,VL& b){
    int l1=a.size()+b.size();
    int bit=bits(l1);
    int l=1<<bit;
    a.resize(l,0LL);
    b.resize(l,0LL);
    VC A,B,C;
    for(auto i:a){
        A.push_back(Complex((ld)i,0));
    }
    for(auto i:b){
        B.push_back(Complex((ld)i,0));
    }
    FFT(A,1);
    FFT(B,1);
    for(int i=0;i<l;i++){
        C.push_back(A[i]*B[i]);
    }
    FFT(C,-1);
    a.clear();
    for(auto i:C){
        a.push_back(!!(int)round(i.r));
    }
}

void polyexp(VL& p, int k) {
    VL ans(1, 1);
    for(;k;k>>=1) {
        if(k & 1) Convolution(ans, p);
        Convolution(p, p);
    }
    FOR0(i, SZ(ans)) {
        if(ans[i]) cout << i << " ";
    }
}
int main() {
    SYNC
    int n, k, a;
    VL p(1002, 0);
    cin >> n >> k;
    FOR0(i, n) {
        cin >> a;
        p[a] = 1;
    }
    polyexp(p, k);
}