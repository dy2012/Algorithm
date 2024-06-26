class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        WHITE, GRAY = 0, 1
        res = []
        stack = [(WHITE, root)]
        while stack:
            color, node = stack.pop()
            if node is None: continue
            if color == WHITE:
                stack.push((WHITE, node.right))
                stack.push((GRAY, node))
                stack.push((WHITE, node.left))
            else:
                res.append(node.val)
        return res
