//
// Created by yulian on 2018-12-08.
//
#include "head.h"
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int record=x;
        int reverse=0;
        while(x)
        {
            reverse=reverse*10+x%10;
            x=x/10;
        }
        return reverse==record;
    }
};

int main()
{
    cout<<Solution().isPalindrome(23988);
    return 0;
}