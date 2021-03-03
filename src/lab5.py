import numpy as np
import heapq

################################################################################
# 
# Graph framework using bidirectional non-weighted linking edges
#
#
################################################################################

class Node:
    def __init__(self, name):
        self.name = name
        self.connections = []
        self.visited = False

    def __lt__(self, node):
        '''
        Node is less than other node if the distance
        '''
        pass

class Graph:
    def __init__(self, node_list=[]):
        self.nodes = {}
        
        # NOTE: watch out! nodes should not be named alike
        # dictionary ?
        for node in node_list:
            self.nodes[node.name] = node
    
    def link(self, name_1, name_2, weight):
        '''
        add a weighted edge between two nodes
        Node labels:
            - name_1
            - name_2
        '''
        self.nodes[name_1].connections.append({"node": self.nodes[name_2], "weight": weight})
        self.nodes[name_2].connections.append({"node": self.nodes[name_1], "weight": weight})

    def add_node(self, name):
        self.nodes[name] = Node(name)

    def remove_node(self, name):
        self.nodes.pop(name) # is pop even a good method of removing a key-value pair from a dict

    def breadth_first_search(self, name):
        '''
        print the set of all nodes connected to a node
        prints those that are connected to the specified node
        by the smallest number of edges
        '''
        queue = [self.nodes[name]]
        queue[0].visited = True
        while len(queue) > 0:
            current_node = queue.pop(0)
            print(current_node.name)
            for neighbor in current_node.connections:
                if not neighbor['node'].visited:
                    queue.append(neighbor['node'])
                    neighbor['node'].visited = True

    ################################################################################
        
    def get_all_nodes(self, name):
        '''
        Return a list of the nodes in the graph of nodes connected to node
        (N.B., the nodes can be indirectly connected as well)
        '''
        nodes_list = []
        queue = [self.nodes[name]]
        queue[0].visited = True
        while len(queue) > 0:
            current_node = queue.pop(0)
            nodes_list.append(current_node)
            for neighbor in current_node.connections:
                if not neighbor['node'].visited:
                    queue.append(neighbor['node'])
                    neighbor['node'].visited = True
        return nodes_list

    ################################################################################

    def unvisit_all(self, name):
        '''
        Change all n.visited to False in all the nodes in the graph of nodes
        connected to node. Use BFS to find all the nodes
        '''
        # nodes = self.get_all_nodes(node)
        # for node in nodes:
        #     node.visited = False
        # pass
        queue = [self.nodes[name]]
        queue[0].visited = False
        while len(queue) > 0:
            current_node = queue.pop(0)
            for neighbor in current_node.connections:
                if neighbor['node'].visited:
                    queue.append(neighbor['node'])
                    neighbor['node'].visited = False
        
    ###############################################################################

    def dfs_rec(self, name): # depth_first_search
        self.nodes[name].visited = True
        cur = self.nodes[name]
        print(f'Node: {cur.name}')
        for con in cur.connections:
            if con["node"].visited == False:
                self.dfs_rec(con["node"].name)  

    ################################################################################

    def dfs_nonrec(self, name):
        '''
        Print out the names of all nodes connected to node using a non-recursive
        version of DFS. Make it so that the nodes are printed in the same order
        as in DFS_rec
        '''
        current_node = self.nodes[name]
        current_node.visited = True
        stack = [current_node]
        while len(stack) > 0:
            current_node = stack.pop()
            print(f'Node: {current_node.name}')
            for neighbor in current_node.connections:
                if not neighbor['node'].visited:
                    stack.append(neighbor['node'])
                    neighbor['node'].visited = True

    ################################################################################
    #
    # OPTIONAL
    #

    def dijsktra_slowish(self, node):
        '''
        Implement Dijkstra's algorithm as discussed in class (i.e., you don't
        need to use a priority queue
        '''
        S = [node]
        d = {node.name: 0}

        unexplored = get_all_nodes(node)
        unexplored.remove(node)

        while len(unexplored) > 0:
            # your code here
            pass

        return d


if __name__ == '__main__':
    graph = Graph()
    graph.add_node('TO')
    graph.add_node('NYC')
    graph.add_node('DC')
    graph.add_node('CDMX')
    graph.add_node('SF')

    # TO = Node("TO")
    # NYC = Node("NYC")
    # DC = Node("DC")
    # CDMX = Node("CDMX")
    # SF = Node("SF")

    graph.link('TO', 'NYC', 3)
    graph.link('TO', 'SF', 6)
    graph.link('TO', 'CDMX', 7)
    graph.link('NYC', 'DC', 2)
    graph.link('SF', 'DC', 5)
    
    graph.dfs_rec('SF')
    graph.unvisit_all('SF')
    print()
    graph.dfs_nonrec('SF')

    # L = get_all_nodes(TO)
    # DFS(TO)
    # #DFS_rec(TO)
    # unvisit_all(TO)
    # DFS(TO)
    # print(dijsktra_slowish(TO))