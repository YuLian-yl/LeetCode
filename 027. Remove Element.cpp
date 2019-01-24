//
// Created by yulian on 2019-01-23.
//
/*题目：
 * 给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
示例 1:

给定 nums = [3,2,2,3], val = 3,

函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。

你不需要考虑数组中超出新长度后面的元素。
示例 2:

给定 nums = [0,1,2,2,3,0,4,2], val = 2,

函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。

注意这五个元素可为任意顺序。

你不需要考虑数组中超出新长度后面的元素。
 * */

/*思路：
 *循环遍历数组，用一个变量标记数组中值为val的标志，把删除的数字往后面的交换，相当于把移除元素往后移。
 * */
#include "head.h"

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //数组长度
        int len = nums.size();
        //标记找到val的下标
        int index=0;
        //遍历数组，若该值不为val,则将该值赋值给index位置的数，并且index加1
        for(int i=0;i<len;i++)
        {
            if(nums[i]!=val)
            {
                nums[index]=nums[i];
                index++;
            }

        }
        for(int i=0;i<index;i++)
            cout<<nums[i]<<" ";
        cout<<endl;
        return index;

    }
};

int main()
{
    Solution s;
    int arr[]={3,2,2,3};
    vector<int>number(begin(arr),end(arr));
    int new_len=s.removeElement(number,3);
    cout<<"删除后数组长度为"<<new_len<<endl;
    return 0;
}
