class Solution:
    def valid(self, piles:List[int], h:int , k :int) -> int:
        #API that return if piles o bana can be earting in time
        total = 0
        for i in range(len(piles)):
            total +=  max(1, math.ceil(piles[i] / k))
        if total > h:
            return -1
        elif total <= h:
            return 0
    
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        ## sort then piles:
        ## try with a minimum value form [1 to h /4]
        ## api succedd shanhowa ? : k = piles[0] + piles[1] + plies..  > 2
        ## smallest is the one that has no prev : so if an api scccues and the
        ## prev value fails it is valid.
        piles.sort()
        l = 1
        r = piles[-1]
        while (l <= r): ##trying to find minium l
            mid = (l + r) // 2
            if (self.valid(piles, h, mid) == 0):
                if (mid != 1 and self.valid(piles, h, mid - 1) == -1):
                    return mid
                else:
                    r = mid - 1
            else:
                l = mid + 1
        return 1