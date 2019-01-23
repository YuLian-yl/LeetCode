//
// Created by yulian on 2019-01-04.
//

#include "head.h"
/*全排列
 * 给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
 * */
/* 选择，1，2，3，分为单一元素和子集
 * 结束：nums为空
 * 限制：输入参入的容量不小于2个
 *具体的实现思路如下：

设立递归的返回条件：输入集合元素数量小于等于 1，则立即返回；
遍历输入集合所有元素：
将集合分为两部分：挑选集合中任一个元素，以及剩余元素组成的子集；
对子集进行递归，返回一个集合；
将先前挑出来的元素放置在递归后返回的集合中；
 * */
class Solution {
public:

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res,dst;
        if(nums.size()<=1)
        {
            dst.push_back(nums);
            return dst;
        }
        // 遍历所有元素
         for(int i=0;i<nums.size();i++) {
             //遍历取出一个数字，剩下的作为一个子集递归
             int num = nums[i];
             vector<int> set=nums;
             set.erase(set.begin() + i);
             res = permute(set);

             //f
             for (int j = 0; j < res.size(); j++)
             {
                 //将开始取出的数字放入自己后，加入结果中。
                 vector<int>sub=res[j];
                 sub.push_back(num);
                 dst.push_back(sub);
             }
         }
        return dst;
    }
};
