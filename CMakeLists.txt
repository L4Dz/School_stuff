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
        "Classes/Class inheritance/Person.h"
        "Classes/Class inheritance/Person.cpp"
        "Classes/Class inheritance/Student.h"
        "Classes/Class inheritance/Student.cpp"
        "Classes/Class inheritance/ErasmusStudent.h"
        "Classes/Class inheritance/ErasmusStudent.cpp"
        "Classes/Class inheritance/Solid.h"
        "Classes/Class inheritance/Solid.cpp"
        "Classes/Class inheritance/Cylinder.cpp"
        "Classes/Class inheritance/Cylinder.h"
        "Classes/Class inheritance/Operation.h"
        "Classes/Class inheritance/Operation.cpp"
        "Classes/Class inheritance/Sum.cpp"
        "Classes/Class inheritance/Sum.h"
        "Classes/Class inheritance/Power.h"
        "Classes/Class inheritance/Power.cpp"
        "Classes/Class inheritance/Shape.h"
        "Classes/Class inheritance/Shape.cpp"
        "Classes/Class inheritance/Circle.h"
        "Classes/Class inheritance/Circle.cpp"
        "Classes/Class inheritance/Rectangle.h"
        "Classes/Class inheritance/Rectangle.cpp"
        "STL & Operator overloading/map-romans.cpp"
        "STL & Operator overloading/count-words.cpp"
        "STL & Operator overloading/Point.cpp"
        "STL & Operator overloading/Point.h"
        "STL & Operator overloading/MovingAverage.h"
        "STL & Operator overloading/MovingAverage.cpp"
        "STL & Operator overloading/Iterators.cpp"
        "Using STL/replace.cpp"
        "Using STL/count-words.cpp"
        "Using STL/Date.h"
        "Using STL/dates.cpp"
        "Using STL/highest.cpp"
        "Using STL/books.cpp")
