class Solution {
public:
    string encode(vector<string>& strs) {
        string res;
        int len = strs.size();
        for (int i = 0; i < len; i++)
        {
            strs[i] += "/hix";
            res += strs[i];
        }
        return (res);
    }

    vector<string> decode(string s) {
        vector<string> res;
        string word;
        size_t len;
        int j = 0;
        while (s.find("/hix", j) != string::npos)
        {
            len = s.find("/hix", j);
            word = s.substr(j, len - j);
            res.push_back(word);
            j = len + std::strlen("/hix");
        }
        return (res);
    }
};