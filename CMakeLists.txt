cmake_minimum_required(VERSION 3.30)
project(untitled7)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled7 main.cpp
        Test_Stuff/median.cpp
        Test_Stuff/median.h
        Test_Stuff/duplicate.cpp
        Test_Stuff/alist.h
        Test_Stuff/append.cpp
        Test_Stuff/longest.cpp
        Test_Stuff/longest.h
        Test_Stuff/pangram.h
        "Test_Stuff/pangram.cpp"
        Streams/word_count.cpp
        Test_Stuff/Airport.cpp
        Test_Stuff/Submarine.h
        Test_Stuff/print_grades.cpp
        Test_Stuff/string-split.cpp
        Test_Stuff/normalise-vector.cpp
        Test_Stuff/longest-common-prefix.cpp
        Streams/count-words.cpp
        Streams/wc.cpp
        Streams/wc.h
        Streams/normalise.cpp
        Streams/maximum.cpp
        Streams/median-values.cpp
        Classes/Point2d.h
        Classes/point2d.cpp
        Classes/date1.h
        Classes/date1.cpp
        Classes/Date2.h
        Classes/date2.cpp
        Classes/Date3.h
        Classes/date3.cpp
        Classes/fraction.cpp)
