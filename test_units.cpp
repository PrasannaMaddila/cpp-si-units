#include <sstream>
#include <utility>
#include <gtest/gtest.h>
#include "units.hpp"

TEST(TestUnits, TestCreation){
    Unit<meter> m1(1.0); 
    std::ostringstream os; 

    os << m1; 
    EXPECT_EQ(os.str(), "Unit< 1, 0, 0, 0, 0, 0, 0 >1");      
}

TEST(TestUnits, TestAddition){
    Unit<meter> m1(1.0), m2(2.0);
    auto m3 = m1 + m2;  
    std::ostringstream os; 

    os << m3; 
    EXPECT_EQ(os.str(), "Unit< 1, 0, 0, 0, 0, 0, 0 >3");      
}


TEST(TestUnits, TestSubtraction){
    Unit<meter> m1(1.0), m2(2.0);
    auto m3 = m1 - m2;  
    std::ostringstream os; 

    os << m3; 
    EXPECT_EQ(os.str(), "Unit< 1, 0, 0, 0, 0, 0, 0 >-1");      
}

TEST(TestUnits, TestMultiplication){
    Unit<meter> m1(1.0), m2(2.0);
    auto m_sq = m1 * m2;  
    std::ostringstream os; 

    os << m_sq; 
    EXPECT_EQ(os.str(), "Unit< 2, 0, 0, 0, 0, 0, 0 >2");      
}

TEST(TestUnits, TestDivision){
    Unit<meter> m1(1.0), m2(2.0);
    Unit<dimless> m_dl = m1 / m2;  
    std::ostringstream os; 

    os << m_dl; 
    EXPECT_EQ(os.str(), "Unit< 0, 0, 0, 0, 0, 0, 0 >0.5");      
}

TEST(TestUnits, TestMultiplicationConstant){
    Unit<meter> m(1.0);
    m = m * 2;  
    std::ostringstream os; 

    os << m; 
    EXPECT_EQ(os.str(), "Unit< 1, 0, 0, 0, 0, 0, 0 >2");      
}

TEST(TestUnits, TestDivisionConstant){
    Unit<meter> m(1.0);
    m = m / 2;  
    std::ostringstream os; 

    os << m; 
    EXPECT_EQ(os.str(), "Unit< 1, 0, 0, 0, 0, 0, 0 >0.5");      
}

/*
 * This test will not even compile, 
 * which is expected behaviour.
 */
/*
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
*/
int main( int argc, char * argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}

