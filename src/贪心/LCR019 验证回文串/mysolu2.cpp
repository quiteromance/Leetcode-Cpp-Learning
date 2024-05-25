#include <string>
#include <stdio.h>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int count = 0;
        bool flag1 = true;
        bool flag2 = true;
        while(count < s.length() / 2){
            if(s[count] != s[s.length() -1 - count]){
                break;
            } 
            count++;
        }
        if(count == s.length() / 2) return true;
        else{
            if(s[count + 1] != s[s.length() - count - 1] && s[count] != s[s.length() -2 - count])
            return false;
            
          
            if(s[count + 1] == s[s.length() - count -1] && s[count] != s[s.length() -2 - count]){
                for(int i = count + 1; i < s.length()/2 + 1; i++){
                    if(s[i] != s[s.length() - i]) return false;
                }
                return true;
            }
            if(s[count + 1] != s[s.length() - count -1] && s[count] == s[s.length() - count -2]){
                for(int i = count; i < s.length()/2 ;i++){
                    if(s[i] != s[s.length() - 2- i]) return false;
                }    
                return true;           
            }

            if(s[count + 1] == s[s.length() - count -1] && s[count] == s[s.length() - count -2]){
                for(int i = count + 1; i < s.length()/2 + 1; i++){
                    if(s[i] != s[s.length() - i]) flag1 = false;
                }

                for(int i = count; i < s.length()/2 ;i++){
                    if(s[i] != s[s.length() - 2- i]) flag2 = false;
                } 
                flag1=flag1||flag2;
                return flag1;
            }
            
        }
        
    }
    
};

int main(){
    string s = "eeccccbebaeeabebccceea";
    Solution S;
    printf("%d",S.validPalindrome(s));
}