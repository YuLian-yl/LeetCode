//
// Created by yulian on 2019-01-03.
//

#include "head.h"

/*
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
 * */

/*思路：将数组排序，设置三个指针left,mid,right。left为0，mid=left1,right为最右边。
 * 对left,mid,right三个指针所指对数求和，记为 sum
 * 设置min_gap记录最小差。
 * 当mid<right时，若sum-target绝对值小于min_gap,则更新min_gap
 * 否则，若sum-target>0,right左移动；若小于0，mid右移。
 * left右移动，mid=left+1;
 * */

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result=accumulate(nums.begin(),nums.begin()+3,0);
        //设置min_gap
        int min_gap=abs(result-target);
        //排序
        sort(nums.begin(),nums.end());
        int left,mid,right;
        for(left=0;left<nums.size();left++)
        {
            right=nums.size()-1;
            mid=left+1;
            while(mid<right)
            {
                int sum_val=nums[left]+nums[mid]+nums[right];
                if(abs(sum_val-target)<min_gap)
                {
                    min_gap=abs(sum_val-target);
                    result=sum_val;
                }

                else if(sum_val-target>0)
                    right--;
                else
                    mid++;

            }
        }

        return result;
    }
};

int main()
{
    Solution s;
    int arr[]={-1,2,1,-4};
    vector<int>number(begin(arr),end(arr));
    cout<<s.threeSumClosest(number,1);
}