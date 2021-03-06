//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：https://leetcode.com/problems/median-of-two-sorted-arrays/
 题目大意：
 两个有有序数组，找到两个数组合并后的中位数。
 nums1 = [1, 3]
 nums2 = [2]
 The median is 2.0
 
 nums1 = [1, 2]
 nums2 = [3, 4]
 The median is (2 + 3)/2 = 2.5
 
 题目解析：
 每次从两个数组中找到一个最小的，直到中间即可；
 为了实现方便，把取下一个的操作用函数封装起来；
 
 复杂度解析：
 时间复杂度
 O(N+M) N、M是两个数组的长度；
 空间复杂度
 O(1)；
 代码量
 从两个数组返回最小值，并指向下一个可以用函数getNext封装；
 
 其他解法：
 直接合并两个数组，然后排序，取中位数；
 优劣：代码量更小，但时间较长。
 
 
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
#include<algorithm>
using namespace std;
#define LYTEST  1



typedef long long lld;
const int N = 50000;
class Solution {
public:
    int x, y;
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        float ret = 0.0;
        int n = nums1.size(), m = nums2.size();
        int mid = (n + m + 1) / 2, k = 0;
        while (k < mid) {
            ret = getNext(nums1, nums2);
            ++k;
        }
        if ((n + m) % 2 == 0) {
            ret = (ret + getNext(nums1, nums2)) / 2.0;
        }
        return ret;
    }
    
    int getNext(vector<int>& nums1, vector<int>& nums2) {
        if (x == nums1.size()) {
            return nums2[y++];
        }
        if (y == nums2.size()) {
            return nums1[x++];
        }
        if (nums1[x] < nums2[y]) {
            return nums1[x++];
        }
        else {
            return nums2[y++];
        }
    }
}leetcode;


int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << leetcode.findMedianSortedArrays(nums1, nums2) << endl;
    
    return 0;
}
