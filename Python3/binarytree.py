class TreeNode():
    def __init__(self, value: int):
        self.LeftChild = None
        self.RightChild = None
        self.data = value

    def insertinto(self, value: int):
        if self.data > value:
            pass
