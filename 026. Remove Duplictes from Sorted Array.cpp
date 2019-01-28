//
// Created by yulian on 2019-01-28.
//
/*题目：
 * 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
   不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
   示例 1:
   给定数组 nums = [1,1,2],
   函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。
   你不需要考虑数组中超出新长度后面的元素。
   示例 2:
   给定 nums = [0,0,1,1,1,2,2,3,3,4],
   函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
   你不需要考虑数组中超出新长度后面的元素。
   说明:
   为什么返回数值是整数，但输出的答案是数组呢?
   请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
 *
 * */

#include "head.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //边界条件不能漏
        if(nums.size()==0)return 0;
        //标记需要删除的位置，和删除的元素值
        int index=0,val=nums[0];
        //循环遍历数组
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=nums[index])
            {
                nums[++index]=nums[i];
            }
        }
        for(int i=0;i<index;i++)
            cout<<nums[i]<<" ";
        cout<<endl;
        return index+1;

    }
};

int main()
{
    Solution s;
    int arr[]={1,1,2};
    vector<int>number(begin(arr),end(arr));
    int new_len=s.removeDuplicates(number);
    cout<<"删除后数组长度为"<<new_len<<endl;
    return 0;
}
