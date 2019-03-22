/**
 * @Problem https://leetcode.com/problems/generate-parentheses/
 * @Author  xxxx
 * @Date    03/12/2019
 * @tutorial none
 */
 
static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();
class Solution {
public:
    unordered_map<int, vector<string>> generatedParentheses;
    vector<string> generateParenthesis(int n) {
        auto mapFind = generatedParentheses.find(n);
        if(mapFind != generatedParentheses.end())   return mapFind->second;
        vector<string> result;
        if(n == 0)
        {
            return result;
        }
        if(n == 1)
        {
            result.push_back("()");
        }
        else
        {
            int i;
            vector<string> prefixes, suffixes;
            for(i = 1; i < n; i++)
            {
                prefixes = generateParenthesis(i);
                if(i == n - 1)
                {
                    suffixes.clear();
                    suffixes.push_back("");
                }
                else
                {
                    suffixes = generateParenthesis(n - i - 1);
                }
                for(string prefix : prefixes)
                {
                    for(string suffix : suffixes)
                    {
                        result.push_back(prefix + "(" + suffix + ")" );
                    }
                    if(i == n - 1)
                    {
                        result.push_back("(" + prefix + ")");
                    }
                }
            }
        }
        generatedParentheses[n] = result;
        return result;
    }
};