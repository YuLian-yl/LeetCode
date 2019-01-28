//
// Created by yulian on 2019-01-28.
//
/*题目：
 * 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。
   不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
   示例 1:
   给定 nums = [1,1,1,2,2,3],
   函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。
   你不需要考虑数组中超出新长度后面的元素。
   示例 2:
   给定 nums = [0,0,1,1,1,1,2,3,3],
   函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。
   你不需要考虑数组中超出新长度后面的元素
 *
 * */
/*思路：
 * 用index标记调整后的一个位置，i循环遍历数组。 count记录重复数字个数。
 * 当当前数字与标记数字当等，count+1,当重复个数达到2，标记+1，交换标记数字和当前数字
 * 标记后移1，交换标记+1，count=1。
 * 这个过程其实不太好理解，我开始写的代码也一直有问题，单步运行调试几遍看看过程就能懂了。
 * */
#include "head.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)return 0;
        //标记重复位置
        int index=0;
        //标记重复个数
        int count=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[index])
            {
                count++;
                if(count==2)
                {
                    nums[++index]=nums[i];
                }
            }
            else
            {
                nums[++index]=nums[i];
                count=1;
            }

        }
        for(int i=0;i<index+1;i++)
            cout<<nums[i]<<" ";
        cout<<endl;
        return index+1;
    }
};

int main()
{
    Solution s;
    int arr[]={0,0,1,1,1,1,2,3,3};
    vector<int>number(begin(arr),end(arr));
    int new_len=s.removeDuplicates(number);
    cout<<"删除后数组长度为"<<new_len<<endl;
    return 0;
}
