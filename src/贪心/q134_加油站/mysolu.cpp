class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> count;
        for(int i = 0; i < gas.size(); i++){
            count.push_back(gas[i] - cost[i]);
        }
        int NumOfS = count.size();
        int Sum = 0;
        int index = 0;
        int num = 0;
        int countNum = 0;
        for(int i = 0; i < NumOfS; i++){
            for(int j = i; j < NumOfS + i; j++){
                Sum += count[j%NumOfS];               
                index ++;
                if(Sum <= 0) break;
            }
            if(index == NumOfS && Sum >= 0) {
                num = i;
                countNum++;
            }
            index = 0;
            Sum = 0;
        }
        if(countNum == 1) return num;
        else return -1;
    }

};
//遍历 究极耗时间