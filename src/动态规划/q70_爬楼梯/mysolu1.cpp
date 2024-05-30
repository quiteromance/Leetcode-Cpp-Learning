//递归
//时间太慢了
class Solution {
public:
    int climbStairs(int n) {
        int count = 0;
        process(n, 0, count);
        return count;
    }
    void process(int n, int index, int &count){
        if(index == n){
            count++;
            return;
        }
        if(index > n){
            return;
        }
        process(n, index+1, count);
        process(n, index+2, count);
    }
};