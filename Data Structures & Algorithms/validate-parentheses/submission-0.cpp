#include <stack>
#include <string>

using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> a;
        string openers = "{([";
        string closers = "})]";
        for (char c : s)
        {
            if (openers.find(c, 0) != std::string::npos)
                a.push(c);
            else if (closers.find(c, 0) != std::string::npos)
            {
                if (a.empty())
                    return false;
                if ((c == '}' && a.top() == '{') || (c == ')' && a.top() == '(')
                            || ((c == ']') && (a.top() == '[')))
                    a.pop();
                else
                    return false;
            }
        }
        if (a.empty())
                return (true);
        return (false);
    }
};