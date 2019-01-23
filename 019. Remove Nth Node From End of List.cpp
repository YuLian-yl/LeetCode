//
// Created by yulian on 2019-01-03.
//

#include "head.h"

/*给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？
 * */

/*
 * 思路：双指针解法，让第二个指针先向前走n步，然后两个指针同时走，当第二个指针达到链表尾部时，第一个指针后一个就
 *是要被删除的节点*/



class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode *p1=head;
        ListNode* p2=head;
        //先让 p2 走n步
        while(n>0)
        {
            p2=p2->next;
            n--;
        }
        //注意不要忽略了p2走了n步后为空的情况
        //若p2为空，则返回p1的下一个节点
        if(p2==NULL)
            return p1->next;
        //让p1,p2同时走，一直到链表尾部
        while(p2->next)
        {
            p1=p1->next;
            p2=p2->next;
        }
        //删除p1后的节点
        p1->next=p1->next->next;
        return head;

    }
};

int main()
{
    Solution s;
    //创建链表
    int arr[]={0,2,341,2,3,4,9};
    ListNode* node=createList(arr,7);
    ListNode* removeNode=s.removeNthFromEnd(node,2);
    printList(node);
    cout<<endl;
    printList(removeNode);
    return 0;
}
