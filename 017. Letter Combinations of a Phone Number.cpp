//
// Created by yulian on 2019-01-03.
//

#include "head.h"

/*给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。


 * */

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        //若字符串为空，或者为01或者10返回res
        if(digits.size()==NULL || digits=="01" ||digits=="10")
            return res;
        //定义字符串数组存储数字对应的字母
        string s[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        res.push_back("");
        //外循环遍历字符串
        for(int i=0;i<digits.size();i++)
        {
            vector<string>temp;
            //取出对应数字对应的字母
            string s0=s[digits[i]-'0'];
            //遍历字符串的每一个字符
            for(int c=0;c<s0.size();c++)
                for(int j=0;j<res.size();j++)//将结果的字符与当前每个字符组合
                {
                   temp.push_back(res[j]+s0[c]);
                }
            res=temp;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string>str=s.letterCombinations("23");
    vector<string> ::iterator it;
    for(it=str.begin();it!=str.end();it++)
    {
        cout<<*it<<",";
    }
    return 0;
}