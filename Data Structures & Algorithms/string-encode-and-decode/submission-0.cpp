class Solution {
public:

    /*encode a list of strings to a single string*/
    vector<int>string_sizes;
    int code;
    string encode(vector<string>& strs) {
        // what does uncode means
        // i could add a number to ascii character.
        // other alpha mirror.
        string coded_string;
        this->code = 17;
        for (int i = 0 ; i < strs.size() ; i++)
        {
            coded_string += strs[i];/*strjoin issue how to split back ? custom sepator. ?? */
            this->string_sizes.push_back(strs[i].size());
        }
        for (int i = 0 ; i < coded_string.size() ; i++)
            coded_string[i] += code;
        return (coded_string);
    }

    vector<string> decode(string s) {
    vector<string> output;
        //string word;
        int j = 0;
        int start = 0;
        for (int i = 0 ; i < s.size() ; i++)
            s[i] -= code;
        //phew now split the string
        for (int i = 0 ; i  < this->string_sizes.size() ; i++)
        {
            string word(s, start, string_sizes[i]);
            output.push_back(word);
            start += string_sizes[i];
        }
        return (output);
    }
};