class Solution {
public:
    vector<int> sol;
    int product;
    vector<int> productExceptSelf(vector<int>& nums) {
        for (int i = 0 ;i < nums.size();  i++)
        {
            product = 1;
            for (int j = 0 ; j < nums.size(); j++)
            {
                if (j != i) 
                    product *= nums[j];
            }
            sol.push_back(product);
        }
        return (sol);
    }
};