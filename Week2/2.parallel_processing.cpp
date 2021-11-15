#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios::sync_with_stdio(0);cin.tie(0)
#define PB push_back
#define SZ 100005
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vp;
typedef vector<pll> vpll;

class CompareDist{
public:
    bool operator()(pll n1, pll n2) {
        if(n1.second!=n2.second)return n1.second>n2.second;
        else return n1.first>n2.first;
    }
};


int main(){
    FASTIO;
    ll n,m;
    cin >> n>>m;
    priority_queue<pll,vpll,CompareDist> pp;
    for(ll tt=0;tt<n;tt++){
        pp.push(make_pair(tt,0));
    }
    for (ll tt = 1; tt <= m; tt++)
    {
        ll cst;
        cin>>cst;
        auto a=pp.top();
        cout<<a.first<<" "<<a.second<<endl;
        a.second+=cst;
        pp.pop();
        pp.push(a);
    }
    return 0;
}