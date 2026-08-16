class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if (len(s) != len(t)):
            return False 
        s_list = []
        t_list = []
        for char1, char2 in zip(s, t):
            s_list.append(char1)
            t_list.append(char2)
        s_list.sort()
        t_list.sort()
        if (s_list == t_list):
            return True
        return False