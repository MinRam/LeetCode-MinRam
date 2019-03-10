/**
 * @Problem https://leetcode.com/problems/valid-parentheses/
 * @Author  MinRam
 * @Date    03/10/2019
 * @tutorial none
 */

static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	bool isValid(string s) {
		int len = s.length();
		if (len == 0) return true;
		if ((len & 1) == 0) return false;

		stack<char> charStack;

		for (size_t i = 0; i < len); ++i) {
			switch (s[i]) {
				case ')':
					if (!charStack.empty() && charStack.top() == '(')
						charStack.pop();
					else
						return false;
					break;
				case '}':
					if (!charStack.empty() && charStack.top() == '{')
						charStack.pop();
					else
						return false;
					break;
				case ']':
					if (!charStack.empty() && charStack.top() == '[')
						charStack.pop();
					else
						return false;
					break;
				default: 
					charStack.push(s[i]);
			}
		}

		return charStack.empty();
	}
};