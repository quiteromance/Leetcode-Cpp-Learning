#include <string>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

/*****************************************以上是include**************************************/
class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        int size = A.size();
        process(size, A, B, C);
    }

    void process(int size, vector<int>& from, vector<int>& other, vector<int>& to){
        if(size == 1) {
            to.push_back(from.back());
            from.pop_back();
            return;
        }
        process(size-1, from, to, other);
        to.push_back(from.back());
        from.pop_back();
        process(size-1, other, from, to);

    }
};

int main(){
    vector<int> A = {2, 1, 0};
    vector<int> B;
    vector<int> C;
    Solution S;
    S.hanota(A,B,C);
    for (int i = 0; i < C.size(); ++i) {
        std::cout << C[i] << " ";
    }
    std::cout << std::endl;
}