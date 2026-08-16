class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max = 0;
        int streak = 0;
        int to_find;
        std::unordered_set<int> b (nums.begin(), nums.end());
        // iterate the vector : if the elememnth a previous elememnt expand the sequence
        // use a set to O(1) finding the prev/next.
        for (int i = 0; i < nums.size(); i++)
        {
            // if the element has no prev element then it is a start of sequence
            streak = 1;
            if (b.find(nums[i] - 1) == b.end())
            {
                to_find = nums[i];
                while (b.find(++to_find) != b.end()) // start of a sequence;
                    streak++;
            }
            if (streak > max) max = streak;
        }
        return (max);
    }
};
