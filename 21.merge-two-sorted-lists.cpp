/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (51.57%)
 * Likes:    3476
 * Dislikes: 514
 * Total Accepted:    872.9K
 * Total Submissions: 1.7M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 *
 * Example:
 *
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 *
 *
 */
#include "common.h"
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    auto head = new ListNode(0);
    auto cur = head; 
    head = _merge(head, cur, l1, l2);
    return head->next;
  }

  ListNode* _merge(ListNode* head, ListNode* cur, ListNode* l1, ListNode* l2){
    if(l1 == NULL && l2 == NULL) return head;
    if(l1 == NULL){
      cur->next = l2;
      return head;
    }
    if(l2 == NULL){
      cur->next = l1;
      return head;
    }
    if(l1->val < l2->val){
      cur->next = new ListNode(l1->val);
      cur = cur->next;
      l1 = l1->next;
      return _merge(head, cur, l1, l2);
    }else{
      cur->next = new ListNode(l2->val);
      cur = cur->next;
      l2 = l2->next;
      return _merge(head, cur, l1, l2);
    }
  }
};
// @lc code=end
int main() {
  auto l1 = new ListNode(1);
  l1->next = new ListNode(2);
  l1->next->next = new ListNode(4);
  auto l2 = new ListNode(1);
  l2->next = new ListNode(3);
  l2->next->next = new ListNode(4);
  Solution().mergeTwoLists(l1, l2);
  return 0;
}