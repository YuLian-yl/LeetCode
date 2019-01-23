//
// Created by yulian on 2019-01-04.
//

#include "head.h"

/*合并两个有序链表
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
示例：
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
 * */

class Solution {
public:
    /*非递归写法*/
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *res,*ret;
        if (l1 == NULL)return l2;
        if (l2 == NULL)return l1;
        //定义两个指针分别指向l1,l2
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        //初始化头节点
        if (p1->val < p2->val)
        {
            res=p1;
            p1=p1->next;
        } else{
            res=p2;
            p2=p2->next;
        }
       ret=res;
        //当p1,p2都不为空
        while(p1&&p2) {
            //若p1的值小于p2,p1往后移动
            if(p1->val<p2->val)
            {
                res->next=p1;
                res=p1;
                p1=p1->next;
            } else
            {
                res->next=p2;
                res=p2;
                p2=p2->next;
            }
        }
        //ret=res;
        //当p1不为空
        while(p1)
        {
            res->next=p1;
            res=p1;
            p1=p1->next;
        }
        while(p2)
        {
            res->next=p2;
            res=p2;
            p2=p2->next;
        }
        return ret;
    }

    /*递归写法*/
    ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
        ListNode* node;
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        if(l1->val<l2->val)
        {
            node=l1;
            node->next=mergeTwoLists(l1->next,l2);
        }
        else
        {
            node=l2;
            node->next=mergeTwoLists(l1,l2->next);
        }
        return node;
    }
};

int main()
{
    Solution s;
    int a1[]={1,2,4};
    int a2[]={1,3,4};
    ListNode *n1=createList(a1,3);
    ListNode *n2=createList(a2,3);
    ListNode *reslultNode=s.mergeTwoLists(n1,n2);
    printList(reslultNode);
    return 0;
}
