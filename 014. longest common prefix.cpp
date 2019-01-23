//
// Created by yulian on 2019-01-02.
//
#include "head.h"

/*编写一个函数来查找字符串数组中的最长公共前缀。如果不存在公共前缀，返回空字符串 ""。
示例 1:

输入: ["flower","flow","flight"]
输出: "fl"

示例 2:
输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。
 * */

class Solution {
public:
    /*1 横向扫描法
     * 先比较前两个字符串找到最长公共前缀，然后将其结果与第三个字符串找公共前缀。。。直到比较完最后一个字符串。
     * 所得到的结果为最长公共前缀*/
    string longestCommonPrefix1(vector<string>& strs) {

        //若输入数组长度为0，返回空
        if(strs.size()==0)return "";
        if(strs.size()==1)return strs[0];
        //遍历数组
        string prefix=strs[0];
        for(int i=1;i<strs.size();++i)
        {
            //比较最后位置为两个字符串的最短长度
            int lastIndex=min(prefix.length(),strs[i].length());
            //求两个字符串的最长公共前缀
            for(int j=0;j<lastIndex;j++)
            {
                //如果字符串的某个下标字符不等，停止遍历
                if(prefix[j]!=strs[i][j])
                {
                    lastIndex=j;
                    break;
                }
            }
            prefix=prefix.substr(0,lastIndex);
        }
        return prefix;
    }

    /*2 纵向扫描法
     * 比较所有字符串的下标为0的字符，若相等 ，继续比较下标为1的字符，直到所有字符串的某一下标的字符不全相等时停止。*/
    string longestCommonPrefix2(vector<string>& strs) {

    }
    /*3 分治法
    * 比较所有字符串的下标为0的字符，若相等 ，继续比较下标为1的字符，直到所有字符串的某一下标的字符不全相等时停止。*/
    string longestCommonPrefix3(vector<string>& strs) {

    }
    /*4 二分查找
    * 比较所有字符串的下标为0的字符，若相等 ，继续比较下标为1的字符，直到所有字符串的某一下标的字符不全相等时停止。*/
    string longestCommonPrefix4(vector<string>& strs) {

    }
};

int main()
{
    Solution s;
    //s.longestCommonPrefix1();
    string s1="fagejigji";
    string s2="fagijeieee";
    string s3="fagiejiw";
    vector<string> st;
    st.push_back(s1);
    st.push_back(s2);
    st.push_back(s3);
    cout<<s.longestCommonPrefix1(st);
    return 0;
}
