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

ll getSrc(ll i,vpll &num){
    if(num[i].first!=i){
        i=getSrc(num[i].first,num);
        num[i].first=i;
    }
    return i;
}

int main(){
    FASTIO;
    ll n,m,max=0;
    cin >>n>>m;
    vpll num;
    vll rank;
    for (int t = 0; t <n; t++)
    {
        int a;
        cin>>a;
        num.push_back(make_pair(t,a));
        rank.push_back(1);
        if(max<a)max=a;
    }
    for(int i=1;i<=m;i++){
        int src,dest;
        cin>>src>>dest;
        src--;dest--;
        src=getSrc(src,num);
        dest=getSrc(dest,num);
        //while(num[src].first!=src)src=num[src].first;
        //while(num[dest].first!=dest)dest=num[dest].first;
        if(src!=dest){
            if(rank[src]==rank[dest])rank[src]++;
            else if(rank[src]<rank[dest])swap(src,dest);
            num[dest].first=src;
            num[src].second+=num[dest].second;
            num[dest].second=0;
        }
        if(max<num[src].second)max=num[src].second;
        /*for(int j=0;j<n;j++)cout<<num[j].first<<" ";
        cout<<endl;
        for(int j=0;j<n;j++)cout<<rank[j]<<" ";*/
        cout<<max<<endl;
    }
    return 0;
}