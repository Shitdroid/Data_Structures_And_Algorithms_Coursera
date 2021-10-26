#include <bits/stdc++.h>

using namespace std;

void max_sliding_window(vector<int> const & A, int w) {
    for (size_t i = 0; i < A.size() - w + 1; ++i) {
        int window_max = A.at(i);
        for (size_t j = i + 1; j < i + w; ++j)
            window_max = max(window_max, A.at(j));

        cout << window_max << " ";
    }

    return;
}


int main() {
    int n = 0;
    cin >> n;
    deque<int> dq;
    deque<int> dq_pos;
    vector<int> A(n);
    vector<int> max;
    for (int i = 0; i < n; ++i)cin >> A[i];
    int m = 0;
    cin >> m;
    for(int i=0;i<n;i++){
        while(!dq.empty() && dq.back()<=A[i]){
            dq.pop_back();
            dq_pos.pop_back();
        }
        dq.push_back(A[i]);
        dq_pos.push_back(i);
        if(i>=m-1){
            if(i>=m && i-m==dq_pos[0]){
                dq.pop_front();
                dq_pos.pop_front();
            }
            max.push_back(dq[0]);
        }
    }
    for(int x: max)cout<<x<<" ";
    cout<<endl;
    return 0;
}
