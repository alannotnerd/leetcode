/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (33.84%)
 * Likes:    1323
 * Dislikes: 1718
 * Total Accepted:    591.7K
 * Total Submissions: 1.7M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */
#include "common.h"
// @lc code=start
class Solution {
 public:
  int gap(char c, const string& pattern){
    auto pos = pattern.rfind(c);
    if(pos == string::npos){
      pos = -1;
    }
    return pattern.size() - pos;
  }
  int strStr(const string& haystack, const string& needle) {
    if(needle.size() == 0) return 0;
    if(haystack.size() < needle.size()) return -1;
    int pos = 0;
    while(pos <= haystack.size() - needle.size()){
      bool matched = true;
      for(int shift=0; shift < needle.size(); shift++){
        if(haystack[pos+shift] != needle[shift]){
          pos += gap(haystack[pos+needle.size()], needle); 
          matched = false;
          break;
        }
      }
      if(matched){
        return pos;
      }
    }
    return -1;
  }
};
// @lc code=end
int main() {
  put(Solution().strStr("hlllo ooo", "ll"));
  return 0;
}
