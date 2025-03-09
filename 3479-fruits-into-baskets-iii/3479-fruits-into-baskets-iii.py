class SegmentTree:
    def __init__(self, data):
        self.n = len(data)
        self.size = 1
        while self.size < self.n:
            self.size <<= 1
        self.min_tree = [float('inf')] * (2 * self.size)
        for i in range(self.n):
            self.min_tree[self.size + i] = data[i]
        for i in range(self.size - 1, 0, -1):
            self.min_tree[i] = min(self.min_tree[2 * i], self.min_tree[2 * i + 1])
    
    def update(self, pos, value):
        pos += self.size
        self.min_tree[pos] = value
        pos >>= 1
        while pos >= 1:
            new_val = min(self.min_tree[2 * pos], self.min_tree[2 * pos + 1])
            if self.min_tree[pos] == new_val:
                break
            self.min_tree[pos] = new_val
            pos >>= 1
            
    def query_range(self, l, r):
        res = float('inf')
        l += self.size
        r += self.size
        while l <= r:
            if l % 2 == 1:
                res = min(res, self.min_tree[l])
                l += 1
            if r % 2 == 0:
                res = min(res, self.min_tree[r])
                r -= 1
            l >>= 1
            r >>= 1
        return res
class Solution(object):
    
    def numOfUnplacedFruits(self, fruits, baskets):
        # Preprocess baskets into a sorted list by capacity and original index
        sorted_baskets = sorted([(b, i) for i, b in enumerate(baskets)], key=lambda x: (x[0], x[1]))
        capacities = [b for b, _ in sorted_baskets]
        original_indices = [i for _, i in sorted_baskets]
        pos_map = {i: pos for pos, (_, i) in enumerate(sorted_baskets)}
        
        # Initialize segment tree with original indices
        st = SegmentTree(original_indices)
        
        unplaced = 0
        
        for f in fruits:
            # Find the first basket with capacity >= f
            start = bisect.bisect_left(capacities, f)
            if start >= len(capacities):
                unplaced += 1
                continue
            # Query the range [start, len(capacities)-1] for min original index
            min_idx = st.query_range(start, len(capacities)-1)
            if min_idx == float('inf'):
                unplaced += 1
                continue
            # Find the position in sorted_baskets for this original index
            pos = pos_map[min_idx]
            # Update the segment tree at pos to infinity
            st.update(pos, float('inf'))
        
        return unplaced
        