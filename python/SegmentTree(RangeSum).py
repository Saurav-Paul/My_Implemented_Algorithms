class SegmentTree:
    def __init__(self, arr: List[int]):
        self.n:int = len(arr)
        self.tree = [0 for _ in range(self.n * 4)]
        self._build(arr, 1, 0, self.n-1)
    
    def _build(self, arr: List[int], t_id: int, low: int, high: int) -> None:
        if low == high:
            self.tree[t_id] = arr[low]
        else:
            mid = (low + high) // 2
            l_id, r_id = self._next_index(t_id)
            self._build(arr, l_id, low, mid)
            self._build(arr, r_id, mid + 1, high)
            self.tree[t_id] = self.tree[l_id] + self.tree[r_id]
    
    def update(self, index: int, value: int)->None:
        def update_helper(t_id: int, low: int, high: int) -> None:
            if low == index == high:
                self.tree[t_id] = value
            else:
                mid = (low + high) // 2
                l_id , r_id = self._next_index(t_id)
                if index <= mid:
                    update_helper(l_id, low, mid)
                else:
                    update_helper(r_id, mid+1, high)

                self.tree[t_id] = self.tree[l_id] + self.tree[r_id]
        
        update_helper(1, 0, self.n -1)
    
    def query(self, range_low: int, range_high: int) -> int:
        def query_helper(t_id: int, low: int, high: int) -> int:
            if range_low > high or range_high < low:
                return 0
            elif range_low <= low and high <= range_high:
                return self.tree[t_id]
            else:
                mid = (low + high) // 2
                l_id, r_id = self._next_index(t_id)
                l_sum = query_helper(l_id, low, mid)
                r_sum = query_helper(r_id, mid + 1, high)
                return l_sum + r_sum
        
        return query_helper(1, 0, self.n - 1)
    
    def _next_index(self, t_id: int) -> (int, int):
        return (t_id * 2, t_id * 2 + 1)
