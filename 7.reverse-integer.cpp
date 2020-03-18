/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.63%)
 * Likes:    2964
 * Dislikes: 4678
 * Total Accepted:    985.4K
 * Total Submissions: 3.8M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 *
 * Example 1:
 *
 *
 * Input: 123
 * Output: 321
 *
 *
 * Example 2:
 *
 *
 * Input: -123
 * Output: -321
 *
 *
 * Example 3:
 *
 *
 * Input: 120
 * Output: 21
 *
 *
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 0 when the reversed
 * integer overflows.
 *
 */
#include "common.h"
// @lc code=start
class Solution {
 public:
  int reverse(int x) {
    bool positive = x >= 0;
    long abs_v = abs(static_cast<long>(x));
    queue<char> q;
    while(abs_v){
      q.push(abs_v % 10);
      abs_v /= 10;
    }
    long ret = 0; 
    while(!q.empty()){
      ret += q.front();
      q.pop();
      if(!q.empty()) ret *= 10;
    }
    ret = positive? ret: -ret;
    if(ret < INT32_MIN || ret > INT32_MAX){
      return 0;
    }else{
      return static_cast<int>(ret);
    }
  }
};
// @lc code=end
int main() {
  put(Solution().reverse(1534236469));
  return 0;
}
