//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/rotate-list/description/
 题目大意：
 
 
 题目解析：
 右移k步，假设链表有sum个节点；
 先对k处理，k=k%sum，保证k<sum，然后
 找到从左到右第k-1个节点p和第k个节点ans，使得p->next=NULL;
 然后找到最后一个节点，使得其next等于head；
 最后返回ans就好。
 
 
 复杂度解析：
 时间复杂度是O(N)
 空间复杂度是O(N)
 
 
 
 其他解法：
 
 
 
 ************************* 题解 ***********************/
#include<cstdio>
#include<cmath>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<string>
#include<utility>
#include<sstream>
#include<cstring>
#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
using namespace std;
#define LYTEST  1


struct Node {
    int first, second;
    Node(){}
    Node(int f, int s) {
        first = f;
        second = s;
    }
    bool operator < (const Node tmp) const {
        if (first != tmp.first) {
            return first > tmp.first;
        }
        else {
            return second > tmp.second;
        }
    }
};

typedef long long lld;
const int N = 50000;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int sum = 0;
        ListNode *p = head;
        while (p) {
            p = p->next;
            ++sum;
        }
        if (sum) {
            k = k % sum;
            if (k) { // 保险起见
                k = sum - k; // 从左到右第k个
                p = head;
                ListNode *last = NULL;
                while (k--) {
                    last = p;
                    p = p->next;
                }
                ListNode *ans = p;
                while (p && p->next) {
                    p = p->next;
                }
                if (last) {
                    last->next = NULL;
                }
                if (p) {
                    p->next = head;
                }
                head = ans;
            }
        }
        return head;
    }
}leetcode;


int main(int argc, const char *argv[]) {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    
    
    return 0;
}
