class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        l = 0
        r = len(matrix) - 1
        mid = 0
        found = False
        while (l <= r):
            mid = (l + r) // 2
            if (target == matrix[mid][0] or target == matrix[mid][-1]):
                return True
            if (matrix[mid][0] < target < matrix[mid][-1]):
                found = True
                break
            elif (target > matrix[mid][0]):
                l = mid + 1
            elif (target < matrix[mid][0]):
                r = mid - 1
        if (not found):
            return False
        m_mid = 0
        l = 0
        r = len(matrix[mid]) - 1
        while (l <=r ):
            m_mid = (l + r) // 2
            if (target > matrix[mid][m_mid]):
                l = m_mid + 1
            elif (target < matrix[mid][m_mid]):
                r = m_mid - 1
            else:
                return True
        return False