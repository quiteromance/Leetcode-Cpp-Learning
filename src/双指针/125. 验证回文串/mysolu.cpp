#include <string>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

/*****************************************以上是include**************************************/
class Solution {
public:
    bool isPalindrome(string s) {
         int i = 0;
        while(s[i] != '\0'){
            s[i] = tolower(s[i]);
            i++;
        }
        
        int first = 0;
        int last = s.length() - 1;
        
        if(s.empty()) return true;
        while(last >= first){
            while((s[first] - 'a' >= 26 || s[first] - 'a' < 0) && (s[first] - '0' >= 10 || s[first] - '0' < 0)){
                first++;
            }

            while((s[last] - 'a' >= 26 || s[last] - 'a' < 0) && (s[last] - '0' >= 10 || s[last] - '0' < 0)){
                last--;
            }
            if(last < 0 || first > s.length()-1) return true;
            if(s[first] != s[last]) return false;
            first++;
            last--;
        }
        return true;
    }
};

int main(){
    // vector<int> A = {0,0,0,0,0};
    string s = ",.";
    Solution S;
    S.isPalindrome(s);
    printf("%d", S.isPalindrome(s));
}