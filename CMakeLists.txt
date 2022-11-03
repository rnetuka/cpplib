cmake_minimum_required(VERSION 3.19)
project(CPPLIB)

set(CMAKE_CXX_STANDARD 20)

add_executable(main main.cpp
        geometry/all.h
        geometry/point.h geometry/point.cpp
        geometry/line_segment.h geometry/line_segment.cpp
        geometry/vector.h geometry/vector.cpp
        geometry/rectangle.h geometry/rectangle.cpp
        geometry.h
        grid.h grid.cpp
        string.h string.cpp
        containers/vector.h
        containers/set.h
        containers/queue.h
        containers/stack.h
        containers/map.h
        file.h file.cpp
        graph/graph.h
        iostream.h
        all.h
        graph/graph.cpp
        hash.h
        graph/path.h
        graph/path.cpp
        graph/node.h
        graph/edge.h graph/edge.cpp
        algorithm.h
        optional.h
        number.h number.cpp 
        exception.h 
        regex.h regex.cpp 
        scanner.h scanner.cpp)
