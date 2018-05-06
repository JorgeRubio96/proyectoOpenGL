from TreeNode import Node

def getDegrees(NumberOfChild, Brothers):
    return (360/Brothers) * NumberOfChild

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
        level_counter = 0
        currentLevel = [self.root]
        nextLevel = []

        while len(currentLevel) > 0:
            level_counter +=1
            vals = []

            for child in currentLevel:
                vals += [child.getValue()]
                num_of_childs = len(child.getChildren())
                child_count = 0
                for child_1 in child.getChildren():

                    degrees = getDegrees(child_count,num_of_childs)

                    child_1.setZ(level_counter)
                    child_1.setX(child.x,degrees)
                    child_1.setY(child.y,degrees)
                    child_1.printCoords()
                    child_count += 1
                    nextLevel += [child_1]

            print(vals)

            currentLevel = nextLevel
            nextLevel = []
