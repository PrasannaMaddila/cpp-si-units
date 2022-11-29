/*
 * Header file to implement the SI units in C++, 
 * using templates.
 * Author: Prasanna M.S.S
 * Date  : 27 November, 2021. 
 * */
#ifndef UNITS_H // #include guards
#define UNITS_H

#include <ostream>

struct UnitTuple{
    int pow_meter; 
    int pow_second;
    int pow_mole; 
    int pow_ampere;  
    int pow_temperature; 
    int pow_candela; 
    int pow_kg; 

    void print(std::ostream& out) const {
        out << "< " << pow_meter << ", " << pow_second 
            << ", " << pow_mole  << ", " << pow_ampere
            << ", " << pow_temperature << ", " << pow_candela
            << ", " << pow_kg 
            << " >" ;   
    }
}; 

// Overloading operator<< to define a print. 
// Note that we always use a const UnitTuple
// over regular UnitTuple's, since a UnitTuple's
// main use-case is always as a const.
std::ostream& operator<< (std::ostream& out, const UnitTuple& utup){
    utup.print(out); 
    return out;
}

constexpr const UnitTuple operator+ (const UnitTuple& left, const UnitTuple& right){
    return UnitTuple{
        left.pow_meter       + right.pow_meter, 
        left.pow_second      + right.pow_second, 
        left.pow_mole        + right.pow_mole, 
        left.pow_ampere      + right.pow_ampere,
        left.pow_temperature + right.pow_temperature, 
        left.pow_candela     + right.pow_candela,
        left.pow_kg          + right.pow_kg 
    }; 
}

constexpr const UnitTuple operator- (const UnitTuple& left, const UnitTuple& right){
        return UnitTuple{
            left.pow_meter       - right.pow_meter, 
            left.pow_second      - right.pow_second, 
            left.pow_mole        - right.pow_mole, 
            left.pow_ampere      - right.pow_ampere,
            left.pow_temperature - right.pow_temperature, 
            left.pow_candela     - right.pow_candela,
            left.pow_kg          - right.pow_kg 
        }; 
}        

template<UnitTuple utup>
class Unit {
    public:
        double value; 
        
        // ctors 
        explicit Unit(double _val) : value{_val} {}; 

        // operators 
        Unit<utup> operator+ (const Unit<utup>& other) const {
            return Unit<utup>(this->value + other.value); 
        } 
        Unit<utup> operator- (const Unit<utup>& other) const {
            return Unit<utup>(this->value - other.value); 
        }
       
        // defining multiplication of Units
        template<UnitTuple o_utup>
        Unit<utup+o_utup> operator* (const Unit<o_utup>& other) const {
            return Unit<utup+o_utup> (this->value * other.value); 
        }
        // and division of units
        template<UnitTuple o_utup>
        Unit<utup-o_utup> operator/ (const Unit<o_utup>& other) const {
            return Unit<utup-o_utup> (this->value / other.value); 
        }
        
        // then multiplication of constants 
        Unit<utup> operator* (const double& constant) const {
            return Unit<utup> (this->value * constant); 
        }

        // and division by constants 
        Unit<utup> operator/ (const double& constant) const {
            return Unit<utup> (this->value / constant); 
        }
        // filling out the print screen        
        virtual void print(std::ostream& out) const {
            out << "Unit" << utup << this->value;  
        }        
}; 

template<UnitTuple utup>
std::ostream& operator<<(std::ostream& out, Unit<utup>& unit) {
    unit.print(out); 
    return out;
}

constexpr UnitTuple meter      {1,0,0,0,0,0,0}; 
constexpr UnitTuple second     {0,1,0,0,0,0,0}; 
constexpr UnitTuple mole       {0,0,1,0,0,0,0}; 
constexpr UnitTuple ampere     {0,0,0,1,0,0,0}; 
constexpr UnitTuple temperature{0,0,0,0,1,0,0}; 
constexpr UnitTuple candela    {0,0,0,0,0,1,0}; 
constexpr UnitTuple kg         {0,0,0,0,0,0,1}; 
constexpr UnitTuple dimless    {0,0,0,0,0,0,0}; 
#endif
