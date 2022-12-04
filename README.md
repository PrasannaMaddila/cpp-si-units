# C++Units 

This is an implementation of the SI units in C++. The header file ```units.cpp``` provides compile-time units i.e. the types of all units are determined at compile time. This makes it so that expressions like ``` Units<1> + Units<2> ``` __do not compile__, so no calculations are ever done using erroneuous unit, ever !

## Usage 

```
# include <units.h>
```

exposes the header file `units.h` to your file. This includes the Unit class to your file. This is a wrapper of `double`, taking a compile-time parameter of a `UnitTuple`. The `UnitTuple` can be overridden to provide a new Unit system. 


The Unit class has the following operations defined. 

- Instantiation 
    - by `double`
    - Copy-constructor defined on other doubles.`
- Binary Operations
    - Between same-dimensions (Between two instances of `Unit<UnitTuple utup>`)
         - Addition/Subtraction 
    - Between distinct dimensioned `Unit`s. 
         - Multiplication/Division 
         - Multiplication/Division by regular constants    


## Compile-time errors 

For example, the following test to add a Unit of type `meter` and a dimensionless constant will not even compile.

```
TEST(TestUnits, TestAdditionConstant){
    Unit<meter> m(1.0);
    std::ostringstream out; 
    try{ 
        m = m + 2;  
    } catch (const auto& e) {
        out << "Operation failed successfully."; 
    }

    EXPECT_EQ(os.str(), "Operation failed successfully.");
}
```
