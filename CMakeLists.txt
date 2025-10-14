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
)