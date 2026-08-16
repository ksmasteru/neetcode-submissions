class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>res;
        int element = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            element = 1;
            for (int j = 0; j < nums.size();j++)
            {
                if (j == i)
                    continue;
                element *= nums[j];
            }
            res.push_back(element);
        }
        return (res);
    }
};
