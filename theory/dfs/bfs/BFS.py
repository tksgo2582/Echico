from collections import deque

def bfs(graph, start, visited):
    queue = deque([start])

    visited[start] = True

    while queue:
        v = queue.popleft()
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True

graph = [
    [],
    [1,2,3],
    [1,2],
    []
]

visited = [False] * 9

bfs(graph, 1, visited)
print(1);