class Solution {
public:
    string encode(vector<string>& strs) {
        string res;
        for (string str : strs)
        {
            res += to_string(str.size());
            res+= ",";
        }
        res += '#';
        for (string str : strs)
             res += str;
        cout << "encoded string is " << res << endl;
        return (res);
    }
    vector<string> decode(string s) {
        int i = 0;
        int pos = 0;
        string num;
        vector<int> sizes;
        vector<string> res;
        while (s[i] && s[i] != '#')
        {
            num = s.substr(i, s.find(',', i) - i);
            sizes.push_back(stoi(num));
            i = s.find(',', i) + 1;
        }
        i++;
        for (int size : sizes)
        {
            res.push_back(s.substr(i, size));
            i += size;
        }
        return res;
    }
};