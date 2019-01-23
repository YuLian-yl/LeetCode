//
// Created by yulian on 2018-12-08.
//
#include "head.h"
/*
 *创建哈希表，将I，V，X，M，D，C，L，V对应的数字存入
 * 遍历字符串，如果当前字符为最后一个或者当前字符数字大于后一个，则相加
 * 否则相减
 * */

class Solution {
public:
    int romanToInt(string s) {
        int romanToInt(string s) {
            int res=0;
            //将字母对应的数字存入哈希表
            unordered_map<char,int> m{{'I',1},{'V',5},{'X',10},{'L',50},{'L',50},{'C',100},{'D',500},{'M',1000}};
            //循环遍历字符串
            for(int i=0;i<s.size();++i)
            {
                int val=m[s[i]];
                //如果当前字符为最后一位或者当前字符大于等于后面的字符，结果加上对应数字
                if(i==s.size()-1||m[s[i]]>=m[s[i+1]])
                    res+=val;
                else
                    res-=val;
                //否则，结果减去当前数字
            }
            return res;
        }
};

 int main()
 {
     Solution s;
     cout<<s.romanToInt("IV");
 }