//
// Created by yulian on 2019-01-03.
//
#include "head.h"
/*给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
 * */
class Solution {
public:
    //时间复杂度为n的3次
    vector<vector<int>> fourSum1(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size()<4)return res;
        //对数组进行排序，并创建哈希表
        sort(nums.begin(),nums.end());
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++)
            map[nums[i]]=i;
        //进行三层for循环
        //第一层找第一个数
        for(int i=0;i<nums.size()-3;i++)
        {
            //若第一个数比target大，则返回
            if(nums[i]>target)return res;
            if(i>0&&nums[i]==nums[i-1])continue;
            //第二层循环找第二个数
            for(int j=i+1;j<nums.size()-2;j++)
            {
                if(nums[i]+nums[j]>target)return res;
                if(j-1>i&&nums[j]==nums[j-1])continue;
                //第三层找第三个数
                for(int k=j+1;k<nums.size()-1;k++)
                {
                    if(nums[i]+nums[j]+nums[k]>target)return res;
                    if(k-1>j&&nums[k]==nums[k-1])continue;
                    int threeSums=nums[i]+nums[j]+nums[k];
                    int findNum=target-threeSums;
                    if(findNum<nums[k])break;
                    if(threeSums>target)return res;
                    auto it=map.find(findNum);
                    if(it!=map.end()&&it->second>k)
                    {
                        vector<int>r;
                        r.push_back(nums[i]);
                        r.push_back(nums[j]);
                        r.push_back(nums[k]);
                        r.push_back(findNum);
                        res.push_back(r);
                    }
                }
            }
        }
        return res;
    }


    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      //二分查找的思想
      vector<vector<int>> res;
      int len=nums.size();
      if(len<4)return res;
      //排序
      sort(nums.begin(),nums.end());
      for(int i=0;i<len-3;i++)
      {
          for(int j=i+1;j<len-2;j++)
          {
              int l=j+1;
              int r=len-1;
              while(l<r)
              {
                  int temp=nums[i]+nums[j]+nums[l]+nums[r];
                  if(temp<target)
                      l++;
                  else if(temp>target)
                      r--;
                  else{
                      res.push_back({nums[i],nums[j],nums[l],nums[r]});
                      l++;
                      r--;
                  }

              }
          }
      }
      sort(res.begin(),res.end());
      //去重
      res.erase(unique(res.begin(),res.end(),res.end()));
      return res;
    }
};

int main()
{
    Solution s;
    int arr[]={-4,4,0,1,0,0,-1};
    vector<int>number(begin(arr),end(arr));
    vector<vector<int>>r=s.fourSum(number,0);
    vector<vector<int>> ::iterator it;
    for(it=r.begin();it!=r.end();it++)
    {
        vector<int> temp=*it;
        for(int i=0;i<temp.size();i++)
            cout<<temp[i]<<" ";
        cout<<endl;
    }

}