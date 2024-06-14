# 题目

小美的 MT
MT 是美团的缩写，因此小美很喜欢这两个字母。
现在小美拿到了一个仅由大写字母组成字符串，她可以最多操作k次，每次可以修改任意一个字符。小美想知道，操作结束后最多共有多少个'M'和'T'字符？

第一行输入两个正整数n,k，代表字符串长度和操作次数。
第二行输入一个长度为n的、仅由大写字母组成的字符串。
1\leq k \leq n \leq 10^5

输出描述：

输出操作结束后最多共有多少个'M'和'T'字符。

示例1
输入例子：

5 2
MTUAN

输出例子：

4

例子说明：

修改第三个和第五个字符，形成的字符串为 MTTAM，这样共有 4 个'M'和'T'。

## 代码

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n ,k;
    cin >> n >> k;

    string s;
    cin >> s;

    int count_MT = 0;
    int count_q = 0;
    for(int i = 0;i < n; i++){
        if(s[i] == 'M' || s[i] == 'T'){
            count_MT++;
        }
        else
            count_q++;        

    }

    if(count_q<=k)cout << count_q+count_MT << endl;
    else{
        cout << count_MT+k << endl;
    }
    
}
// 64 位输出请用 printf("%lld")