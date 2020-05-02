/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

#include <gtest/gtest.h>

// @lc code=start
#include <string>
#include <stack>
using namespace std;
class Solution
{
private:
    static const char BRACKET_SMALL_CHAR_LEFT = '(';
    static const char BRACKET_SMALL_CHAR_RIGHT = ')';

    static const char BRACKET_MIDDLE_CHAR_LEFT = '[';
    static const char BRACKET_MIDDLE_CHAR_RIGHT = ']';

    static const char BRACKET_BIG_CHAR_LEFT = '{';
    static const char BRACKET_BIG_CHAR_RIGHT = '}';

public:
    bool isValid(string s)
    {
        stack<char> brackets;
        for (auto i = 0; i < s.size(); ++i)
        {
            if (!brackets.empty())
            {
                if ((brackets.top() == BRACKET_SMALL_CHAR_LEFT && s[i] == BRACKET_SMALL_CHAR_RIGHT) ||
                    (brackets.top() == BRACKET_MIDDLE_CHAR_LEFT && s[i] == BRACKET_MIDDLE_CHAR_RIGHT) ||
                    (brackets.top() == BRACKET_BIG_CHAR_LEFT && s[i] == BRACKET_BIG_CHAR_RIGHT))
                {
                    brackets.pop();
                } else {
                    brackets.push(s[i]);
                }
            }
            else
            {
                brackets.push(s[i]);
            }
        }

        if (brackets.empty())
        {
            return true;
        }

        return false;
    }
};
// @lc code=end

TEST(XieXing, GanSi)
{
    EXPECT_TRUE(Solution().isValid("()"));
    EXPECT_TRUE(Solution().isValid("()[]{}"));
    EXPECT_FALSE(Solution().isValid("(]"));
    EXPECT_FALSE(Solution().isValid("([)]"));
    EXPECT_TRUE(Solution().isValid("{[]}"));
    EXPECT_FALSE(Solution().isValid("([)"));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}