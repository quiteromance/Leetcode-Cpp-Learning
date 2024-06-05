class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        int index = 0;
        vector<int> dp(len+1,0);
        if(s[0] == '0') 
            return 0;
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 1;i < len; i++){
            if(s[i] == '0'){ // 当s[i] == '0'
                if(s[i-1] == '0' || s[i-1]-'0' > 2) // 如果前一个数等于0或者大于2，说明不能和前一个数映射
                    return 0;
                else{
                        dp[i+1] = dp[i-1];// 和前一个数组合，结果dp[i] = dp[i-2];
                    }
            }      
            
            else if(s[i] - '0' > 0 && s[i] - '0' <= 6){ //说明s[i]可以单独组合也可以和前一个数组合
                if(s[i-1]-'0'> 2 || s[i-1] == '0')  //如果前一个数不给机会
                    dp[i+1] = dp[i]; 
                else    //如果给机会,dp[i]等于和单独映射和前一个数一起组合加起来的值
                    dp[i+1] = dp[i] + dp[i-1];
            }
            else  //s[i] - '0' > 6
            {
                if(s[i-1]-'0' == 1)  //前一个数等于1可以有两次组合机会
                    dp[i+1] = dp[i] + dp[i-1];
                else    
                    dp[i+1] = dp[i] ;
            }    

        }
        return dp[len];
    }

};