//
// Created by yulian on 2019-01-24.
//

#include "head.h"
/*题目：
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
   示例:
   输入: [0,1,0,3,12]
   输出: [1,3,12,0,0]
   说明:
   必须在原数组上操作，不能拷贝额外的数组。
   尽量减少操作次数。
 *
 * */

class Solution {
public:
    //思路1：标记0的位置，遇到非0的数与其交换。时间复杂度为O(n)
    void moveZeroes(vector<int>& nums) {
        int len=nums.size();
        if(len==0||len==1)return;
        int index=0;
        for(int i=0;i<len;i++)
        {
            if(nums[i]!=0)
            {
                swap(nums[index],nums[i]);
                index++;
            }
        }
        for(int i=0;i<len;i++)
            cout<<nums[i]<<",";
    }

    //思路2：基于冒泡的思想。循环遍历数组，找到0，循环遍历后面的数，找到第一个非0，交换，时间复杂度为O(n*n)，效率低。
    void moveZeroes2(vector<int>& nums) {
        int len=nums.size();
        int index=0;
        for(int i=0;i<len;i++)
        {
            if(nums[i]==0)
            {
                for(int j=i+1;j<len;j++)
                {
                    if(nums[j]!=0)
                    {
                        swap(nums[i],nums[j]);
                        break;
                    }
                }
            }
        }
        for(int i=0;i<len;i++)
            cout<<nums[i]<<",";
    }

    //思路3：基于选择的方法。找到所有非0数按顺序赋给数组前面的元素，剩下的全部赋值为0。
    void moveZeroes3(vector<int>& nums) {
        int len=nums.size();
        if(len==0 ||len==1)return;
        int index=0;
        for(int i=0;i<len;i++)
        {
            if(nums[i]!=0)
            {
                //跟思路1的差别在这
                nums[index]=nums[i];
                index++;
            }
        }
        for(int i=index;i<len;i++)
            nums[i]=0;
        for(int i=0;i<len;i++)
            cout<<nums[i]<<",";
    }
};

int main()
{
    Solution s;
    int arr[]={3,0,0,2,-3,1,2,0,3};
    vector<int>number(begin(arr),end(arr));
    s.moveZeroes2(number);

}