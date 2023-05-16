#tree structure
from collections import deque


class Tree:
    def __init__(self,val):
        self.val = val
        self.left = None
        self.right = None

class Solution:
    def __init__(self) -> None:
        pass
    def buildTree(self) -> Tree:
        print("enter node value(enter -1 for null)")
        nodeVal = int(input())
        if(nodeVal==-1):
            return None
        node = Tree(nodeVal)
        print("For left")
        node.left = self.buildTree()
        print("For right")
        node.right = self.buildTree()
        return node
    def bfs_level_order_traversal(self,root:Tree)->None:
        q = deque()
        q.append(root)
        while(len(q)!=0):
            size = len(q)
            for i in range(size):
                curr = q.popleft()
                print(curr.val,end=",")
                if(curr.left!=None):
                    q.append(curr.left)
                if(curr.right!=None):
                    q.append(curr.right)
            print()
    def preOrder(self,root:Tree) -> None:
        if(root==None):
            return
        print(root.val)
        self.preOrder(root.left)
        self.preOrder(root.right)
    def search(self,root:Tree,val:int) ->bool:
        if(root==None):
            return False
        if(root.val==val):
            return True
        left = self.search(root.left,val)
        right = self.search(root.right,val)
        return left or right

soln = Solution()
root = soln.buildTree()
print("pre order traversal(DFS)")
soln.preOrder(root)
print("level order traversal(BFS)")
soln.bfs_level_order_traversal(root)
print("searching for value 4 in the tree")
print(soln.search(root,4))