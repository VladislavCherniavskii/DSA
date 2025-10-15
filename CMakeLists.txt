cmake_minimum_required(VERSION 4.0)
project(DSA)

set(CMAKE_CXX_STANDARD 23)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})  # ← ДОБАВЬ ЭТУ СТРОКУ

add_executable(DSA
        main.cpp
        "DSA2/HW1/A. Depth-first search.cpp"
        "DSA2/HW1/B. Connected components.cpp"
        "DSA2/HW1/C. Cheating.cpp"
        "DSA2/HW1/D. Cycle detection.cpp"
        "DSA2/HW1/E. Which vertices can reach the first vertex.cpp"
        "DSA2/HW1/F. Subtree sizes.cpp"
        "DSA2/HW1/G. Transport system optimization.cpp"
        "DSA2/HW1/H. Room area.cpp"
        "DSA2/HW1/I. Byte Radio.cpp"
        "DSA2/HW1/J. Landing troops.cpp"
        "DSA2/HW2/A. Topological Sort.cpp"
        "DSA2/HW2/B. Bridges.cpp"
        "DSA2/HW2/C. Articulation points.cpp"
        "DSA2/HW2/D. Graph сondensation.cpp"
        "DSA2/HW2/E. One-Way traffic.cpp"
        "DSA2/HW2/F. Parts production.cpp"
        "DSA2/HW2/G. Apple from the apple tree.cpp"
        "DSA2/HW2/H. Study groups in Mahovniki.cpp"
        "DSA2/HW2/I. City in the Republic.cpp"
        "DSA2/HW2/J. Prime Minister.cpp"
        "DSA2/HW3/A. Shortest path length.cpp"
        "DSA2/HW3/B. Path in a graph.cpp"
        "DSA2/HW3/C. Spelunker's path.cpp"
        "DSA2/HW3/D. Fleas.cpp"
        "DSA2/HW3/E. Redundant edges.cpp"
        "DSA2/HW3/F. Metro.cpp"
        "DSA2/HW3/G. Toy Maze.cpp"
        "DSA2/HW3/H. Max and Pourings.cpp"
        "DSA2/HW3/I. Tsar Leonid on a tractor.cpp"
        "DSA2/HW3/J. Robots.cpp"
)