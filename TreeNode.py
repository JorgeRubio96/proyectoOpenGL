import math

class Node:
    def __init__(self, newVal):
        self.value = newVal
        self.x = None
        self.y = None
        self.z = None
        self.left = None
        self.right = None

    def printCoords(self):
        print("Val: ",self.value)
        print("X: ",self.x,"\tY: ",self.y,"\tZ: ",self.z)

    def setX(self, parentX, degrees):
        self.x = parentX + math.cos(math.radians(degrees))

    def setY(self, parentY, degrees):
        self.y = parentY + math.sin(math.radians(degrees))

    def setZ(self, Z):
        self.z = Z

    def setValue(self, newVal):
        self.value = newVal

    def getValue(self):
        return self.value

    def addChild(self, newChild):
        if newChild.getValue() < self.value:
            if self.left:
                return self.left.addChild(newChild)
            else:
                self.left = newChild
                lol = (self, self.left)
                print(lol)
                return lol

        if newChild.getValue() > self.value:
            if self.right:
                return self.right.addChild(newChild)
            else:
                self.right = newChild
                lol = (self, self.right)
                print(lol)
                return lol

    def getChildren(self):
        children = []

        if self.left:
            children += [self.left]

        if self.right:
            children += [self.right]

        return children
