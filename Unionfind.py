class UnionFind:
    root = {}
    def Set_create(self, V):
        for a in V:
            self.root[a] = a
    def U_find(self, n):
        if self.root[n] == n:
            return n
        return self.U_find(self.root[n])
    def Union_fn(self, u, v):
        p = self.U_find(u)
        q = self.U_find(v)
        self.root[p] = q

def S(V, U):
    print([U.U_find(a)
           for a in V])

if __name__ == '__main__':

    V = [1, 3, 5, 6, 7, 9, 10]
    U = UnionFind()
    U.Set_create(V)
    S(V, U)
    U.Union_fn(7, 10)
    S(V, U)
    U.Union_fn(3, 6)
    S(V, U)
    U.Union_fn(1, 5)
    S(V, U)
    U.Union_fn(3, 5)
    S(V, U)
    U.Union_fn(9, 10)
    S(V, U)
    U.Union_fn(6, 5)
    S(V, U)


