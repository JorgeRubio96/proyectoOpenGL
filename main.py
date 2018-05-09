from TreeSturcture import *
import random


def main():
    Edges = []
    newTree = Tree(50)

    for x in range(0,100):
        Edges.append(newTree.addChild(Node(random.randint(0, 100)))) 

    newTree.levelPrint()

if __name__ == "__main__":
    main()