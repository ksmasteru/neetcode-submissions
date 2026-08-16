# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        level = 0
        queue = deque()
        current = root
        if root:
            queue.append(root)
        while len(queue) > 0:
            size = len(queue)
            for i in range(size):
                current = queue[0]
                queue.popleft()
                if current.left:
                    queue.append(current.left)
                if current.right:
                    queue.append(current.right)
            level += 1
        return level