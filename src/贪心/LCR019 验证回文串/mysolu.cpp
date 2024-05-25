#include <string>
#include <stdio.h>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int count = 0;
        for(int i = 0; i < s.length() / 2; i++){
            if(s[i] == s[s.length() - i - 1]) count++;
        }
        if(count == s.length()/2) return true;

        for(int i = 0; i < s.length(); i++){
            string DelS = "";
            int index = 0;
            while(s[index] != '\0'){
                if(index != i){
                    DelS.push_back(s[index]);
                }
                index++;
            }
            count = 0;
            for(int j = 0; j < DelS.length() / 2; j++){
                if(DelS[j] == DelS[DelS.length() - j - 1]) count++;
            }
            if(count == DelS.length() / 2) return true;
        }
        
        return false;

    }
};

int main(){
    string s = "abc";
    Solution S;
    printf("%d",S.validPalindrome(s));
}
// 超出时间限制