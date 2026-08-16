class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        int max = 1;
        bool zerod = false;
        int zero_count = 0;
        for (int n : nums)
        {
            if (n == 0)
            {
                zerod = true;
                zero_count++;
                continue;
            }
            max *= n;
        }
        if (zero_count > 1)
        {
            for (int i = 0 ; i < nums.size(); i++)
                res[i] = 0;
            return (res);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (zerod)
            {
                if (nums[i] == 0)
                    res[i] = max;
            }
            else
                res[i] = max / nums[i];
        }
        return (res);
    }
};
