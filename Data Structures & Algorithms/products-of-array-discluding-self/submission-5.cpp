using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1)
                return (nums);
        vector<int> postfix(nums.size());
        vector<int> prefix(nums.size());
        vector<int> result(nums.size());
        // fill postfix values
        // multipms nums by the product of last.
        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            prefix[i] =  prefix[i - 1] * nums[i];
        // fill postfix values
        postfix[nums.size() - 1] =  nums[nums.size() - 1];
        for (int j = nums.size() - 2 ; j >= 0 ; j--)
            postfix[j] = nums[j] * postfix[j + 1];
        //result[i] = prefix[i - 1] * posfix[ i + 1];
        result[0] = postfix[1];
        for (int i = 1 ; i < nums.size() - 1; i++)
            result[i] = prefix[i - 1] * postfix[i + 1];
        result[nums.size() - 1] = prefix[nums.size() - 2];
        return (result);
    }
};
