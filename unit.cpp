/*
 * This is a test implementation of compile-time units in C++. 
 * We take only one unit, say meter, and compute. The idea is 
 * that expressions of the type Unit<a> + Unit<b> will fail
 * !at compile-time! whenever a != b. 
 *
 * Author: Prasanna M.S.S
 * Date  : 28 November, 2022.
 *
 * This code is not licensed, use it at your own risk :)  
 * */

#include <iostream>
using namespace std; 

template <int pow>
class Unit{
    public: 
        double value; 

        // defining the constructors 
        Unit<pow>(double _val): value{_val} {};
        Unit<pow>( Unit& other): value{other.value}{}; 

        // now the operators 
        // addition ...
        Unit<pow> operator+ (Unit<pow>& other){
            return Unit<pow>(value + other.value); 
        }
        
        // subtraction 
        Unit<pow> operator- (Unit<pow>& other){
            return Unit<pow>(value - other.value); 
        }
        
        // then multiplication ... 
        // This needs to be templatized for each 
        // possible value of the other operand. 
        // This allows meter * meter^2 = meter^3. 
        template<int opow>
        Unit<opow + pow> operator* (Unit<opow>& other){
            return Unit<opow + pow>(other.value * value);
        }

        // and similarly division. 
        template<int opow>
        Unit<pow - opow> operator/ (Unit<opow>& other){
            return Unit<pow - opow> (value / other.value); 
        }
        
        // helper function to overload operator<<
        void print(std::ostream& out){
            out << "unit<" << pow << "> : value = " << value; 
        }
}; 

// overloading the operator<< using templates to 
// define how to print the unit. 
// NOTE: It expects a reference, so rvalues are
//       NOT ALLOWED !!! 
template<int pow>
std::ostream& operator<< (std::ostream& out, Unit<pow>& unit){
    unit.print(out); 
    return out; 
}

int main(){
    Unit<1> u1(1), u2(2); 
    auto umul = u1 * u2;            // meter^2 
    auto udiv = u1 / u2;            // dimensionless constant. 
    std::cout << umul << std::endl; 
    std::cout << udiv << std::endl; 
}
