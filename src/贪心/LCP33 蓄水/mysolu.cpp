#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 没有成功
class Solution {
public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        vector<int> Method1;
        vector<int> Method2;
        int count = 0;
        vector<int> bucket2;
        while(!isAllZeros(vat)){
            vector<int> bucket2(bucket.size(),0);
            Method1 = CountNum(bucket, vat);
            for(int i = 0;i < bucket.size();i++){
                bucket2[i] = bucket[i];
            }
            bucket2[Method1[0]] = bucket[Method1[0]] + 1;
            Method2 = CountNum(bucket2, vat);
            if(Method1[1] >= Method2[1]){
                bucket[Method1[0]]++; 
                printf("bucket++\n");          
            }
            else{
                for(int i = 0; i < vat.size(); i++){
                    vat[i] = vat[i] - bucket[i] > 0 ? vat[i] - bucket[i] : 0;
                }
                printf("vat-\n"); 

            }
            count++;
            printf("%d\n",count);
        }
        return count;
    }

    bool isAllZeros(const vector<int> arr){// 判断数组是否全部为0
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] != 0) return false;
        }
        return true;
    }

    vector<int> CountNum(const vector<int> bucket, const vector<int> vat){ // 记录需要多少次才能倒满
        int count = 0;
        int index = 0;
        for(int i = 0; i < bucket.size(); i++){
            if(bucket[i] != 0){
                if(vat[i]%bucket[i] != 0){
                    index = vat[i]/bucket[i]+1 > count ? i : index;
                    count = vat[i]/bucket[i]+1 > count ? vat[i]/bucket[i]+1 : count;
                } 
                else{
                    index = vat[i]/bucket[i] > count ? i : index;
                    count = vat[i]/bucket[i] > count ? vat[i]/bucket[i] : count;

                }
            }
            else {
                count = 10000;
                index = i;
                break;
            }
        }
        vector<int> arr = {index,count};
        return arr;
    }

};

int main(){
    vector<int> bucket = {9988,5017,5130,2445,9896,9151,3625,7801,608,3283,1386,979,5209,4182,8234,9870,8714,6435,3800,956,4006,5620,7474,1205,6993,3320,1201,7593,905,3816,4522,4560,8027,8219,6686,3779,2141,1240,6504,6612,6921,7329,8145,5745,7652,4340,7933,6246,5157,9447,107,9665,3653,2978,9832,4945,4312,2199,449,8432,3230,8163,800,6547,1110,1194,9384,632,3275,1229,7230,8643,7613,8256,5043,1288,3088,8997,4554,4755,7433,8146,9722,3469,8863,5831,7816,5058,4316,7946,8402,975,2450,4958,9811,9336,21,9309,8999,56};
    vector<int> vat = {9991,6973,7192,9876,9910,9549,3700,8814,1308,9981,9234,7292,7732,8458,8441,9939,9621,7285,7452,2718,6589,7555,8788,3202,7832,4781,8798,9299,2112,9963,8755,7240,9217,8587,6782,9703,8954,3759,6907,7218,7333,8020,8323,5750,9510,8571,8664,8510,9363,9741,8643,9825,4227,8530,9961,8511,8949,7486,9086,9690,5316,9581,9314,8817,7234,8998,9485,5394,7365,1501,7984,9802,9778,8314,7482,7117,5117,9609,8732,9728,9330,8800,9775,6210,8966,7700,8802,7607,8950,9730,9855,1231,5228,5329,9982,9532,3230,9951,9034,8299};
    Solution S;
    printf("%d",S.storeWater(bucket, vat));

}