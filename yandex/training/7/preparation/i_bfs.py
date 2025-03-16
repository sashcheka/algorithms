from collections import deque


def main():
    n = int(input())
    
    # Build adjacency list for the graph
    graph = [[] for _ in range(n + 1)]
    for _ in range(n - 1):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)
    
    # Compute degrees (number of neighbors) for each node
    degrees = [0] * (n + 1)
    for i in range(1, n + 1):
        degrees[i] = len(graph[i])
    
    # Initialize subtree sizes
    sizes = [1] * (n + 1)  # Each node starts with size 1 (itself)
    visited = [False] * (n + 1)
    
    # Start BFS from leaves (nodes with degree 1)
    queue = deque()
    for i in range(1, n + 1):
        if degrees[i] == 1 and i != 1:  # Leaf nodes, excluding root if it’s a leaf
            queue.append(i)
            visited[i] = True
    
    # BFS: Process nodes bottom-up
    while queue:
        node = queue.popleft()
        
        # Find the parent (the unprocessed neighbor)
        for neighbor in graph[node]:
            if not visited[neighbor]:
                # Contribute this node's size to its parent
                sizes[neighbor] += sizes[node]
                degrees[neighbor] -= 1  # Decrease degree of parent
                
                # If parent’s degree drops to 1 (or 0 for root), it’s ready to process
                if degrees[neighbor] == 1 or (neighbor == 1 and degrees[neighbor] == 0):
                    queue.append(neighbor)
                    visited[neighbor] = True
    
    # Output sizes
    for i in range(1, n + 1):
        print(sizes[i], end=" ")


if __name__ == "__main__":
    main()