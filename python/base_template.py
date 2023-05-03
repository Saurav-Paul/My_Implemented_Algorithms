import sys
import math
from collections import deque, defaultdict
from typing import List, Tuple

# Set recursion limit to maximum value to avoid stack overflow
sys.setrecursionlimit(10**6)

# Define useful aliases
IntList = List[int]
StrList = List[str]
TupleInt = Tuple[int, int]
TupleStr = Tuple[str, str]

class Solve:
    def __init__(self):
        pass
    
    def solve(self) -> int:
        n: int = self.input_int()
        arr: IntList = self.input_int_list()
    
    @staticmethod
    def input_int() -> int:
        return int(input())

    @staticmethod
    def input_int_list() -> IntList:
        return list(map(int, input().split()))

    @staticmethod
    def input_str_list() -> StrList:
        return input().split()

    @staticmethod
    def input_tuple_int() -> TupleInt:
        return tuple(map(int, input().split()))

    @staticmethod
    def input_tuple_str() -> TupleStr:
        return tuple(input().split())

# Read input
t = 1
t = Solve.input_int()  # number of test cases
for _ in range(t):
    solver = Solve()
    solver.solve()
