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

class heap{
    vi ara;
    int size;
    int cnt=0;
public:
    vp sp;
    void siftDown(int i){
        if(i*2+1>=size)return;
        else if(ara[i]>ara[i*2+1] || (i*2+2<size && ara[i]>ara[i*2+2])){
            if(i*2+2>=size || ara[i*2+1]<ara[i*2+2]){
                pii a(i,i*2+1);
                sp.push_back(a);
                swap(ara[i],ara[i*2+1]);
                i=i*2+1;
            }
            else{
                pii a(i,i*2+2);
                sp.push_back(a);
                swap(ara[i],ara[i*2+2]);
                i=i*2+2;
            }
            siftDown(i);
            cnt++;
            return;
        }
    }
    void makeHeap(int n){
        size=n;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            ara.push_back(a);
        }
        for(int i=n/2-1;i>=0;i--)siftDown(i);
    }
};

int main(){
    FASTIO;
    int tc;
    cin >> tc;
    heap hp;
    hp.makeHeap(tc);
    cout<<hp.sp.size()<<endl;
    for(auto x:hp.sp)cout<<x.first<<" "<<x.second<<endl;
    return 0;
}