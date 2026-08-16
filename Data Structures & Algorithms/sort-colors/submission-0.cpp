class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> _sort = {0, 0 , 0};
        for (int i = 0; i < nums.size(); i++)
            _sort[nums[i]] += 1; 
        int j = 0;
        for (int i = 0; i < _sort.size(); i++)
        {
            while (_sort[i]-- > 0)
                 nums[j++] = i;
        }
    }
};