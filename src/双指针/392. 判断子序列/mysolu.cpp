class Solution {
public:
    bool isSubsequence(string s, string t) {
        int indexOfs = 0;
        int indexOft = 0;
        while(t[indexOft] != '\0' && s[indexOfs] != '\0'){
            if(s[indexOfs] == t[indexOft]){
                indexOfs++;
                indexOft++;
            }
            else{
                indexOft++;
            }
        }
        if(indexOfs == s.length()) return true;
        return false;
    }
};