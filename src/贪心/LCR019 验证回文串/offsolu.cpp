class Solution {
public:
    bool checkPalindrome(const string& s, int low, int high) {
        for (int i = low, j = high; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int low = 0, high = s.size() - 1;
        while (low < high) {
            char c1 = s[low], c2 = s[high];
            if (c1 == c2) {
                ++low;
                --high;
            } else {
                return checkPalindrome(s, low, high - 1) || checkPalindrome(s, low + 1, high);
            }
        }
        return true;
    }
};

/*
我们换一种想法。首先考虑如果不允许删除字符，如何判断一个字符串是否是回文串。常见的做法是使用双指针。定义左右指针，初始时分别指向字符串的第一个字符和最后一个字符，每次判断左右指针指向的字符是否相同，如果不相同，则不是回文串；如果相同，则将左右指针都往中间移动一位，直到左右指针相遇，则字符串是回文串。

在允许最多删除一个字符的情况下，同样可以使用双指针，通过贪心实现。
初始化两个指针 low\textit{low}low 和 high\textit{high}high 分别指向字符串的第一个字符和最后一个字符。
每次判断两个指针指向的字符是否相同，如果相同，则更新指针，将 low\textit{low}low 加 1，high\textit{high}high 减 1，
然后判断更新后的指针范围内的子串是否是回文字符串。
如果两个指针指向的字符不同，则两个字符中必须有一个被删除，此时我们就分成两种情况：即删除左指针对应的字符，留下子串 s[low+1:high]s[\textit{low} + 1 : \textit{high}]s[low+1:high]，或者删除右指针对应的字符，留下子串 s[low:high−1]s[\textit{low} : \textit{high} - 1]s[low:high−1]。当这两个子串中至少有一个是回文串时，就说明原始字符串删除一个字符之后就以成为回文串。

作者：力扣官方题解
链接：https://leetcode.cn/problems/RQku0D/solutions/1398918/zui-duo-shan-chu-yi-ge-zi-fu-de-dao-hui-30b55/
*/

//和我的想法一样，就是使用了双指针要注意一下
