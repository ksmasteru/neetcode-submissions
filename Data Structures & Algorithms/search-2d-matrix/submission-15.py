class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        mid = 0
        L = 0
        R = len(matrix) - 1
        found = False
        while (L <= R):
            mid = (L + R) // 2
            if (matrix[mid][0] == target):
                return True
            r = len(matrix[mid])
            if (r > 1 and matrix[mid][0] < target <= matrix[mid][r - 1]):
                found = True
                break
            if (target > matrix[mid][0]):
                L = mid + 1
            elif (target < matrix[mid][0]):
                R = mid - 1
        L = 0
        R = len(matrix[mid]) - 1
        while (L <= R):
            m_mid = (L + R) // 2
            if (matrix[mid][m_mid] > target):
                R = m_mid - 1
            elif (matrix[mid][m_mid] < target):
                L = m_mid + 1
            else:
                return True
        return False