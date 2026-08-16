class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap; // ket value storing.
        vector<vector<int>>elems(nums.size() + 1);
        // hasmap number : frequency
        for (int n : nums)
            umap[n] = umap[n] + 1;
        // now sort this value index into the vect index value
        for (const auto& entry : umap)
            elems[entry.second].push_back(entry.first);
        // now we get our desired result
        // we start from the end  "biggest value"
        vector<int> res;
        for  (int i = elems.size() - 1; i > 0; --i)
        {
            for (int n : elems[i])
            {
                res.push_back(n);
                if (res.size() == k)
                    return res;
            }
        }
        return (res);
    }
};