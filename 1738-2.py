import sys
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')
N, M = map(int,input().split())
lst = [0, 0] + [float('inf')] * (N - 1)


class Graph:
    def __init__(self, root) -> None:
        self.change = False
    
class Node:
    def __init__(self, node) -> None:
        self.val = node
        self.relate = None

