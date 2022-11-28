# C++Units 

This is an implementation of the SI units in C++. The header file ```units.cpp``` provides compile-time units i.e. the types of all units are determined at compile time. This makes it so that expressions like ``` Units<1> + Units<2> ``` __do not compile__, so no calculations are ever done using erroneuous unit, ever !
