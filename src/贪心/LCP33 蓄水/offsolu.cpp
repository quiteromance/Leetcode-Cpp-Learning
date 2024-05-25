class Solution {
public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        int n = bucket.size();
        priority_queue<pair<int, int>> q; //创建优先级队列，需要装水次数多的桶会排在前面
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (bucket[i] == 0 && vat[i]) { //如果有桶不能装水，必须要消耗一次升级桶
                ++cnt;
                ++bucket[i];
            }
            if (vat[i] > 0) { 
                // 如果缸需要装水，将[(vat[i] + bucket[i] - 1) / bucket[i], i]放入队列中
                //(vat[i] + bucket[i] - 1) / bucket[i]表示当前装满需要多少次，i表示是第几桶
                q.emplace((vat[i] + bucket[i] - 1) / bucket[i], i);
            }
        }
        if (q.empty()) {
            return 0;
        }
        int res = INT_MAX;
        while (cnt < res) { //进入循环
            auto [v, i] = q.top(); //取出队列的第一个值，即v次数最大的桶
            res = min(res, cnt + v);//跟新res = cnt + v 
            if (v == 1) { // 当次数只有一次的时候，退出循环
                break;
            }
            q.pop(); //弹出第一个值
            int t = (vat[i] + v - 2) / (v - 1); //要求是从v次装水变成v-1次装水，以此为依据来升级第i个桶。+ v - 2是为了向上取整
            cnt += t - bucket[i]; //t为升级之后的桶大小，减去原来的桶大小，得到升级的次数
            bucket[i] = t;//更新桶的大小
            q.emplace((vat[i] + bucket[i] - 1) / bucket[i], i);//再次放回队列
        }
        return res;
    }
};
