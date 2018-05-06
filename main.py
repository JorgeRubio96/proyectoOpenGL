from TreeSturcture import *

def main():
    Edges = []
    newTree = Tree(5)
    Edges += newTree.addChild(Node(8))
    Edges += newTree.addChild(Node(7))
    Edges += newTree.addChild(Node(3))
    Edges += newTree.addChild(Node(6))
    Edges += newTree.addChild(Node(12))
    Edges += newTree.addChild(Node(10))
    Edges += newTree.addChild(Node(13))
    Edges += newTree.addChild(Node(11))
    Edges += newTree.addChild(Node(2))
    newTree.levelPrint()

if __name__ == "__main__":
    main()