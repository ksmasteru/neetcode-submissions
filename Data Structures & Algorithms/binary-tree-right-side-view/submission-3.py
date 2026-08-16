# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        # dfs push the last node of the level to the llist.
        res = []
        buff = []
        queue = deque()
        if root:
            queue.append(root)
        while len(queue) > 0:
            size = len(queue)
            for i in range(size):
                current = queue[0]
                queue.popleft()
                buff.append(current.val)
                if current.left:
                    queue.append(current.left)
                if current.right:
                    queue.append(current.right)
            res.append(buff[-1])
        return res