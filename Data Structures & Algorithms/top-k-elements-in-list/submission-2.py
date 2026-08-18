class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        #store the count
        count = {}
        for num in nums:
            count[num] = 1 + count.get(num, 0)
        #store in by frequency
        storage = [[] for i in range(len(nums) + 1)]
        for index, val in count.items():
            storage[val].append(index)
        #result
        res = []
        for i in range(len(nums), 0 , -1):
            for num in storage[i]:
                res.append(num)
                if (len(res) == k):
                    return res
        return res