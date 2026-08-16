class Solution {
public:
    bool isalphanum(char c)
    {
        return ((c >= 'a' && c <= 'z')
                || (c >= 'A' && c <= 'Z')
                || (c >= '0' && c <= '9'));
    }
    bool isPalindrome(string s) {
        string s1;
        for (int i = 0 ; i < s.size(); i++)
        {
             if (isalphanum(s[i]))
                s1 += tolower(s[i]);
        }
        int len = s1.size() -1;
        for (int i = 0 ; i < s1.size() / 2;)
        {
            if (s1[i++] != s1[len--])
                return false;
        }
        return true; //hm one thing !! ? 
    }
};
