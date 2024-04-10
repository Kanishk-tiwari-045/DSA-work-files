// from collections import deque

// def bfs(graph, start):
//     num_nodes = len(graph)
//     visited = [False] * num_nodes
//     queue = deque([start])
//     visited[start] = True
   
//     while queue:
//         node = queue.popleft()
//         print(node, end=" ")
       
//         for adjacent in range(num_nodes):
//             if graph[node][adjacent] == 1 and not visited[adjacent]:
//                 queue.append(adjacent)
//                 visited[adjacent] = True


// if _name_ == "_main_":
//     graph = [
//         [0, 1, 1, 0, 0],
//         [1, 0, 0, 1, 1],
//         [1, 0, 0, 0, 1],
//         [0, 1, 0, 0, 0],
//         [0, 1, 1, 0, 0]
//     ]
//     start_node = 0
//     print("BFS Traversal starting from node", start_node)
//     bfs(graph, start_node)