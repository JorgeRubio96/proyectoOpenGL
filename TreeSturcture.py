from TreeNode import Node

class Tree:
    def __init__(self, rootVal):
        self.root = Node(rootVal)

    def addChild(self, newNode):
        kek = self.root.addChild(newNode)
        # print(kek)
        return kek

    def levelPrint(self):
        self.root.x = 0
        self.root.y = 0
        self.root.z = 0
        currentLevel = [self.root]
        nextLevel = []

        while len(currentLevel) > 0:
            vals = []

            for child in currentLevel:
                vals += [child.getValue()]
                nextLevel += child.getChildren()

            print(vals)

            currentLevel = nextLevel
            nextLevel = []
