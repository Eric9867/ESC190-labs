# Lab 6

#
# We'll define a node of a binary tree and introduce some features of Python
# classes along the way

import random


class BST:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

    def insert(self, value):
        '''
        node.insert(5) is the same as BST.insert(node, 5)
        We use this when recursively calling, e.g. self.left.insert
        '''
        if value < self.value:
            if self.left == None:
                self.left = BST(value)
            else:
                self.left.insert(value)
        else:
            if self.right == None:
                self.right = BST(value)
            else:
                self.right.insert(value)

    def __repr__(self):
        '''The string representation of a node.
        Here, we convert the value of the node to a string and make that
        the representation.
        We can now use
        a = Node(4)
        print(a) # prints 4
        '''
        return str(self.value)



a = BST(4)
a.insert(2)
a.insert(5)
a.insert(10)
a.insert(3)
a.insert(15)

# Problem 1
# Draw (manually) the binary tree rooted in a.

        #    4
        #   / \
        #  2   5
        #   \   \
        #    3   10
        #         \ 
        #          15


# Problem 2
# Write code to find the height of a Binary Search Tree

def bst_height_recursive(tree):
    if tree == None:
        return 0
    else:
        return 1 + max(bst_height_recursive(tree.left), bst_height_recursive(tree.right))

# Write
def bst_height(root):
    max_depth = 0
    visited = [root]
    next_layer = []
    while visited:
        # cur = visited.pop(0)
        for node in visited:
            if node.left != None: next_layer.append(node.left)
            if node.right != None: next_layer.append(node.right)

        visited = next_layer
        next_layer = []
        max_depth += 1

    return max_depth



# Problem 3

# Write code to print out the nodes of the BST using
# Breadth-First Search. How would you get the Breadth-First Traversal
# from the tree you've drawn?
# (Modify the BFS function from lecture for this problem)

def BFS_tree_v2(node):
    visited = [node]

    while visited:
        cur = visited.pop(0)
        print(cur)
        if cur.left != None:  visited.append(cur.left)
        if cur.right != None: visited.append(cur.right)

def BFS_tree_v1(node):
    depth = 0
    working_nodes = []
    children_nodes = []
    working_nodes.append(node)

    while(working_nodes):
        for node in working_nodes:
            print(node, end= " ")
            if(node.left):
                children_nodes.append(node.left)
            if(node.right):
                children_nodes.append(node.right)
        print("")
        working_nodes = children_nodes
        children_nodes = []

# The BF traversal of a tree prints nodes level-by-level

# Problem 4

# Empirically investigate the relationship between the number of nodes in the
# tree and the height of the tree when inserting nodes with values generated
# using random.random()


def make_random_tree(n_nodes):
    '''
    Make a tree with n_nodes nodes by inserting nodes with values
    drawn using random.random()
    '''
    if not n_nodes:
        return None

    tree = BST(random.random()) 
    for i in range(n_nodes-1):
        tree.insert(random.random())
    return tree

def height_random_tree(n_nodes):
    '''
    Generate a random tree with n_nodes nodes, and return its height
    '''
    tree = make_random_tree(n_nodes)
    return bst_height_recursive(tree)

def make_data(max_nodes):
    '''
    Make two lists representing the empirical relationship between
    the number of nodes in a random tree and the height of the tree.
    Generate N_TREES = 40 trees with each of
    n_nodes = 5, int(1.2*5), int(1.2^2*5), .....
    return n (a list of values of n_nodes) and h (a list of heights)
    '''

    ''' loop for N_TREES iters:
            n.append(int(n_nodes))
            h.append(height_random_tree(int(n_nodes)))
            n_nodes *= 1.1
            
    '''
    N_TREES = 80
    n_nodes = 5.0

    n = []
    h = []

    for i in range(N_TREES):
        n.append(int(n_nodes))
        h.append(height_random_tree(int(n_nodes)))
        n_nodes *= 1.2 # increase to 1.2 to plot less points
        if n_nodes > max_nodes:
            break

    return n, h


print("BFS 1")
BFS_tree_v1(a)
print("\nBFS 2")
BFS_tree_v2(a)
print("\n")
print(bst_height_recursive(a))
print(bst_height(a))

draw = True

if draw:
    n, h = make_data(1000)
    import matplotlib.pyplot as plt
    import numpy as np
    plt.scatter(n, h)
    # x = np.linspace(1,1000, 100)
    # y = 2* np.log2(x)
    # plt.plot(x,y,'r')
    plt.show()
    # plt.savefig("trees.png")

            # logarithmic relationship

            # as the tree grows in size, the number of incomplete branches grows ???
            # How come its not log_2???
            #