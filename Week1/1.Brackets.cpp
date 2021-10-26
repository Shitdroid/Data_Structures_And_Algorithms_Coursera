#include<bits/stdc++.h>
using namespace std;
class Stack{
    vector<int> ara;
    vector<char> seq;
    int top;
public:
    Stack(string s){
        top=0;
    }
    void push(char s, int n){
        seq.push_back(s);
        ara.push_back(n);
        top++;
    }
    char pop(){
        seq.pop_back();
        ara.pop_back();
        return seq[--top]; 
    }
    bool isEmpty(){
        return top;
    }

    int error(){
        return ara[top-1];
    }
};

int main(void){
    string s;
    cin>>s;
    Stack al(s);
    int flag=-1;
    for(int i=0;i<s.length();i++){
        char c=s[i];
        if(c=='[' || c=='{' || c=='(')al.push(c,i+1);
        else if(c==']' || c=='}' || c==')'){
            if(!al.isEmpty()){
                flag=i+1;
                break;
            } 
            char ch=al.pop();
            if((ch=='[' && c==']')||(ch=='(' && c==')')||(ch=='{' && c=='}'))continue;
            else {
                flag=i+1;
                break;
            }
        }
    }
    if(flag==-1 && al.isEmpty())flag=al.error();
    if(flag==-1) cout<<"Success"<<endl;
    else cout<<flag<<endl;
}