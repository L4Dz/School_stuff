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
        Classes/dates/Date1.h
        Classes/dates/date1.cpp
        Classes/dates/Date2.h
        Classes/dates/date2.cpp
        Classes/dates/Date3.h
        Classes/dates/date3.cpp
        Classes/fraction.cpp
        "Classes/Separate compilation & class templates/Color.h"
        "Classes/Separate compilation & class templates/Color.cpp"
        "Classes/Separate compilation & class templates/Date.h"
        "Classes/Separate compilation & class templates/Person.h"
        "Classes/Separate compilation & class templates/p2_main.cpp"
        "Classes/Separate compilation & class templates/Date.cpp"
        "Classes/Separate compilation & class templates/Person.cpp"
        "Classes/Separate compilation & class templates/Point.h"
        "Classes/Separate compilation & class templates/Point.cpp"
        "Classes/Separate compilation & class templates/Polygon.h"
        "Classes/Separate compilation & class templates/Polygon.cpp"
        "Classes/Separate compilation & class templates/Pair.cpp"
        "Classes/Separate compilation & class templates/stack.cpp"
        "Classes/Class inheritance/ResaleProduct.h"
        "Classes/Class inheritance/Product.h"
        "Classes/Class inheritance/Product.cpp"
        "Classes/Class inheritance/ResaleProduct.cpp"
        "Classes/Class inheritance/Person.h")
