//
// Created by yulian on 2019-01-04.
//

#include "head.h"

/*有效的括号
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
 */

class Solution {
public:
    bool isValid(string s) {
        if(s=="")return true;
        //获取字符串长度
        int len=s.length();
        //创建vector 模拟栈操作
        vector<char> stack;
        //循环遍历字符串
        for(int i=0;i<len;i++) {
            if (s[i] == '(')
                stack.push_back(s[i]);
            else if (s[i] == ')') {
                if (0 != stack.size() && stack.back() == '(')
                    stack.pop_back();
                else
                    return false;
            } else if (s[i] == '[')
                stack.push_back(s[i]);
            else if (s[i] == ']') {
                if (0 != stack.size() && stack.back() == '[')
                    stack.pop_back();
                else
                    return false;
            } else if (s[i] == '{')
                stack.push_back(s[i]);
            else if (s[i] == '}') {
                if (0 != stack.size() && stack.back() == '{')
                    stack.pop_back();
                else
                    return false;
            } else
                return false;
        }
            if(0==stack.size())
                return true;
            else
                return false;

    }

    bool isValid1(string s) {
        //利用栈的简洁写法
        int len=s.size();
        //如果长度不为偶数，返回false
        if(len%2!=0) return false;
        //创建栈
        stack<char> stacks;
        for(int i=0;i<len;i++)
        {
            //若栈为空，入栈
            if(stacks.empty())
                stacks.push(s[i]);
            //否则，
            // 若栈顶为（，当前字符为），或者栈顶为【，当前字符为】或者栈顶为{，当前字符为}则出栈
                //否则，入栈
            else
            {
                if((stacks.top()=='(' && s[i]==')') ||(stacks.top()=='[' && s[i]==']') ||(stacks.top()=='{' && s[i]=='}') )
                    stacks.pop();
                else
                    stacks.push(s[i]);
            }

        }
        //返回结果判断栈是否为空
        return stacks.empty();
    }
};

int main()
{
    Solution s;
    cout<<s.isValid1("{}");
    return 0;
}