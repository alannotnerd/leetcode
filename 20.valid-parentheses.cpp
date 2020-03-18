/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (38.15%)
 * Likes:    4284
 * Dislikes: 201
 * Total Accepted:    882.2K
 * Total Submissions: 2.3M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 *
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 *
 *
 * Note that an empty string is also considered valid.
 *
 * Example 1:
 *
 *
 * Input: "()"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: "()[]{}"
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: "(]"
 * Output: false
 *
 *
 * Example 4:
 *
 *
 * Input: "([)]"
 * Output: false
 *
 *
 * Example 5:
 *
 *
 * Input: "{[]}"
 * Output: true
 *
 *
 */
#include "common.h"
// @lc code=start
class Solution {
 public:
  bool isValid(string s) {
    stack<char> char_s;
    for(auto c: s){
      switch(c){
        case '(':
        case '[':
        case '{':
          char_s.push(c);
          break;
        case ')':
          if(char_s.empty() || char_s.top() != '(') return false;
          char_s.pop();
          break;
        case ']':
          if(char_s.empty() || char_s.top() != '[') return false;
          char_s.pop();
          break;
        case '}':
          if(char_s.empty() || char_s.top() != '{') return false;
          char_s.pop();
          break;
      }
    }
    return char_s.empty();
  }
};
// @lc code=end
int main() {
  put(Solution().isValid("[(){}]"));
  return 0;
}