#include<bits/stdc++.h>
using namespace std;

class tree{
public:
    int id,height;
    vector<int> child;
    tree(int n=0){id=n;}
    void push(int i){
        child.push_back(i);
    }
};



int main(void){
    int n,root,height;
    vector<tree>nodes;
    cin>>n;
    queue<int>q;
    for(int i=0;i<n;i++){
        tree node(i);
        nodes.push_back(node);
    }
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a!=-1)nodes[a].push(i);
        else {
            q.push(i);
            nodes[i].height=1;
        }
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        height=nodes[node].height;
        for(int x:nodes[node].child){
            nodes[x].height=height+1;
            q.push(nodes[x].id);
        }
        //cout<<node<<" "<<height<<endl;
    }
    //for(auto x:nodes[root].child)cout<<nodes[x].id<<" "<<nodes[x].height(nodes)<<endl;
    cout<<height<<endl;
}