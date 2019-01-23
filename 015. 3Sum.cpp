//
// Created by yulian on 2019-01-03.
//


#include "head.h"
/*给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
 */
/* 思路：
 * 对已有数组进行排序，然后创建哈希表
 * 两层循环遍历，第一层循环遍历第一个数，若第一个数大于0，则停止
 * 第二层遍历，从第一个数后面开始遍历第二个数，将前两个数相加，在哈希表找负的前两个数之和
 * 若能找到，将三个数存入vector
 * */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
           vector<vector<int>> res;
           //若数组长度为0，返回
           if(nums.size()==0)return res;
           //对数组进行排序
           sort(nums.begin(),nums.end());
           //建立哈希表
           unordered_map<int,int> map;
           for(int i=0;i<nums.size();i++)
               map[nums[i]]=i;

           //外层遍历找第一个数
           for(int i=0;i<nums.size()-2;i++)
           {
               if(nums[i]>0)break;
               //若该数与前面的数相等，则退出继续
               if(i>0&&nums[i]==nums[i-1])continue;
               //第二层循环找第二个数
               for(int j=i+1;j<nums.size()-1;j++)
               {
                   //若该数与前面第数相等，退出继续
                   if(j-1>i&&nums[j]==nums[j-1])continue;
                   //求两数之和
                   int twoNums=nums[i]+nums[j];
                   if(-twoNums<nums[j])break;
                   if(twoNums>0)return res;//这两行顺序不能换，不然会出错
                   auto it=map.find(-twoNums);
                   //如果在哈希表中找到第三个数，并且下标大于j,则把三个数存如数组
                   if(it!=map.end()&&it->second>j)
                   {
                       vector<int> r;
                       r.push_back(nums[i]);
                       r.push_back(nums[j]);
                       r.push_back(-twoNums);
                       res.push_back(r);
                   }
               }
           }
           return res;
    }
};

int main()
{
    Solution s;
    int arr[]={-4,4,0,1,0,0,-1};
    vector<int>number(begin(arr),end(arr));
    vector<vector<int>>r=s.threeSum(number);
    vector<vector<int>> ::iterator it;
    for(it=r.begin();it!=r.end();it++)
    {
        vector<int> temp=*it;
        for(int i=0;i<temp.size();i++)
            cout<<temp[i]<<" ";
        cout<<endl;
    }

}