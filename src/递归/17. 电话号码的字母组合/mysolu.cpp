class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return vector<string>();
        vector<string> res;
        string str = "";
        process(digits, 0, res, str);
        return res;

    }
    void process(string digits, int index, vector<string> &res, string str){
        if(index == digits.length()) {
            res.push_back(str);
            return;
        };

        for(int i = 0; i < reflect(digits[index]).length(); i++){
            string curStr = str;
            char cur = reflect(digits[index])[i];
            str = str + cur;
            process(digits, index + 1, res, str);
            str = curStr;
        }
    }

    string reflect(char digit){
        string str;
        if(digit - '0' < 7){
            for(int i = 0;i < 3;i++){
                char cur = (digit - '2') * 3 + 'a' + i;
                str = str + cur;
            }

            return str;
        }
        if(digit - '0' == 7){
            return "pqrs";
        }
        if(digit - '0' == 8){
            return "tuv";
        }
        if(digit - '0' == 9){
            return "wxyz";
        }
        return "";
        
    }
};