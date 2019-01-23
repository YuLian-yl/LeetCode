//
// Created by yulian on 2019-01-04.
//

#include "head.h"
/*括号生成
 * 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
 * */

/*回朔法：
 * 选择：加左括号或者右括号
 * 限制：如果左括号用完，不加左括号；如果有括号和左括号一样多，不能加右括号
 * 结束条件：左右括号都用完
 *
 *    if(若左右括号用完)
 *    加入解返回，
 *    if(还有左括号)加左括号，继续递归

 *    if（右括号大于左括号）加右括号，继续递归
 * */

class Solution {
public:
    void backtrackParethesis(string sublist,vector<string>&res,int left,int right)
    {
        if(left==0&&right==0)
        {
            res.push_back(sublist);
            return;
        }

        if(left>0)
        {
            cout<<"1"<<sublist<<endl;
            backtrackParethesis(sublist+"(",res,left-1,right);
        }
        if(left<right)
        {
            cout<<"2"<<sublist<<endl;
            backtrackParethesis(sublist+")",res,left,right-1);
        }

        if(right>0)
            return;

    }
    vector<string> generateParenthesis(int n) {
        //结果
        vector<string> res;
        backtrackParethesis("",res,n,n);
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> str=s.generateParenthesis(3);
    for(int i=0;i<str.size();i++)
    {
        cout<<str[i]<<endl;
    }
    return 0;
}