#include <bits/stdc++.h>

using namespace std;

class StackWithMax {
    vector<int> stak;
    vector<int> max_pos;
    int size=0,max=-1;
  public:

    void Push(int value) {
        stak.push_back(value);
        if(value>max)max=value;
        max_pos.push_back(max);
        size++;
    }

    void Pop() {
        assert(stak.size());
        stak.pop_back();
        size--;
    }

    int Max() const {
        assert(stak.size());
        return max_pos[size-1];
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}