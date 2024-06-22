/*
给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。

在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。

返回 你能获得的 最大 利润 。

 

示例 1：

输入：prices = [7,1,5,3,6,4]
输出：7
解释：在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4。
随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6 - 3 = 3。
最大总利润为 4 + 3 = 7 。

示例 2：

输入：prices = [1,2,3,4,5]
输出：4
解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4。
最大总利润为 4 。

示例 3：

输入：prices = [7,6,4,3,1]
输出：0
解释：在这种情况下, 交易无法获得正利润，所以不参与交易可以获得最大利润，最大利润为 0。
*/

// 思路：一开始使用递归方法解决，但是时间复杂度太高了，没有全部通过测试

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int sum = 0;
        process(prices, 0, sum, profit,0);
        return profit;
    }

    void process(vector<int>& prices, int index, int sum, int &profit,int flag){
        if(index == prices.size()) {
            profit = max(sum,profit);
            return;
        };
        if(flag == 1){//假设手里有股票
            
            process(prices,index+1,sum+prices[index],profit,0);//选择卖掉          
            process(prices,index+1,sum,profit,1);//选择不卖

        }
        if(flag == 0){//假设手里没有股票
            process(prices,index+1,sum-prices[index],profit,1);//选择买
            process(prices,index+1,sum,profit,0);//选择不买

        }
    }
};