class Solution {
public:
//Input: s = "11Was it a car or a cat I saw?55"
    bool isalphanum(char c)
    {
        return ((c >= 'A' && c <= 'Z')
                || (c >= 'a' && c <= 'z')
                || (c >= '0' && c <= '9'));
    }
    bool isPalindrome(string s) {
        int i = 0;
        int e = s.size() - 1;
        while (i < e)
        {
            while (!isalphanum(s[i]))
                i++;
            while(!isalphanum(s[e]))
                e--;
            if (i < e)
            {
                if (tolower(s[i++]) != tolower(s[e--]))
                    return false;
            }
        }
        return true;
    }
};
