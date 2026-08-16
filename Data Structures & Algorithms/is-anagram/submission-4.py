class Solution:
    def isAnagram(self,s : String,t : String) -> bool :
        s_t = sorted(s)
        s_s = sorted(t)
        if (s_t == s_s):
            return True
        return False