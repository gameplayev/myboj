import sys
sys.setrecursionlimit(20000)

def tarjan_scc(v):
    global id_counter, scc_counter
    ids[v] = low[v] = id_counter
    id_counter += 1
    stack.append(v)
    on_stack[v] = True

    for next in adj[v]:
        if ids[next] == -1:
            tarjan_scc(next)
            low[v] = min(low[v], low[next])
        elif on_stack[next]:
            low[v] = min(low[v], ids[next])

    if ids[v] == low[v]:
        scc = []
        while True:
            node = stack.pop()
            on_stack[node] = False
            scc.append(node)
            low[node] = ids[v]
            if node == v:
                break
        sccs.append(sorted(scc))

def main():
    input = sys.stdin.read
    data = input().split()
    
    V = int(data[0])
    E = int(data[1])
    
    global id_counter, scc_counter, ids, low, stack, on_stack, adj, sccs
    id_counter = 0
    scc_counter = 0
    ids = [-1] * (V + 1)
    low = [0] * (V + 1)
    stack = []
    on_stack = [False] * (V + 1)
    adj = [[] for _ in range(V + 1)]
    sccs = []

    index = 2
    for _ in range(E):
        A = int(data[index])
        B = int(data[index + 1])
        adj[A].append(B)
        index += 2

    for i in range(1, V + 1):
        if ids[i] == -1:
            tarjan_scc(i)

    sccs.sort(key=lambda x: x[0])

    print(len(sccs))
    for scc in sccs:
        print(" ".join(map(str, scc)) + " -1")

if __name__ == "__main__":
    main()
