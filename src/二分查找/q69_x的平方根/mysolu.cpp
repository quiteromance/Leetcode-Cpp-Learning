class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        int first = 0, last = x;
        while(first <= last ){
            long long mid = first + (last - first)/ 2;
            if(mid * mid < x){
                first = mid + 1;
            }
            else if(mid * mid > x){
                last = mid - 1;
            }
            else 
                return mid; 
        }
        return last;
    }
};