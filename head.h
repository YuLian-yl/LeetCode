//
// Created by yulian on 2018-12-08.
//

#ifndef LEETCODE300_HEAD_H
#define LEETCODE300_HEAD_H

#endif //LEETCODE300_HEAD_H

#include<sstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <stack>
#include <unordered_map>
#include <set>
#include <numeric>

using namespace std;


void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

/**
 * 链表节点定义。
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * 打印一个链表的所有元素。
 * @param p 链表。
 */
void print_list(ListNode *p) {
    int i = 1;
    while (p != nullptr) {
        printf("第 %d 个结点的取值 val = %d\n", i, p->val);
        p = p->next;
        i++;
    }
}

/*
 * 创建链表
 * */
ListNode *createList(int arr[],int n)
{
    ListNode* head=new ListNode(NULL);
    //head->next=NULL;
    ListNode *p=head;

    for(int i=0;i<n;i++)
    {
        ListNode* node=new ListNode(arr[i]);
        node->next=NULL;
        p->next=node;
        p=node;
    }
    head=head->next;
    //p->next=NULL;
    return head;
}

/*
 * 打印单链表
 * */
void printList(ListNode *p)
{
    while (p)
    {
        cout<<p->val<<" ";
        p=p->next;
    }
}
/**
 * 获取链表的长度。
 * @param p 链表。
 * @return 长度。
 */
int getLength(ListNode *p) {
    int i = 0;
    while (p) {
        i++;
        p = p->next;
    }
    return i;
}