////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/Physics
/// @file           Library/Physics/Time/Date.test.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        TBD

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Library/Physics/Time/Date.hpp>

#include <Global.test.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST (Library_Physics_Time_Date, Constructor)
{

    using library::physics::time::Date ;

    {

        EXPECT_NO_THROW(Date(2018, 1, 1)) ;
        
        EXPECT_NO_THROW(Date(1400, 1, 1)) ;
        EXPECT_NO_THROW(Date(2000, 1, 1)) ;
        EXPECT_NO_THROW(Date(9999, 12, 31)) ;

    }

    {

        EXPECT_ANY_THROW(Date(0, 1, 1)) ;
        EXPECT_ANY_THROW(Date(1399, 12, 31)) ;
        EXPECT_ANY_THROW(Date(10000, 1, 1)) ;
        
        EXPECT_ANY_THROW(Date(2018, 2, 29)) ;

        EXPECT_ANY_THROW(Date(2018, 0, 1)) ;
        EXPECT_ANY_THROW(Date(2018, 13, 1)) ;

        EXPECT_ANY_THROW(Date(2018, 1, 0)) ;
        EXPECT_ANY_THROW(Date(2018, 1, 32)) ;

    }

}

TEST (Library_Physics_Time_Date, EqualToOperator)
{

    using library::physics::time::Date ;

    {

        EXPECT_TRUE(Date(2018, 1, 1) == Date(2018, 1, 1)) ;
        EXPECT_TRUE(Date(1400, 1, 1) == Date(1400, 1, 1)) ;
        EXPECT_TRUE(Date(2018, 2, 3) == Date(2018, 2, 3)) ;

    }

    {

        EXPECT_FALSE(Date(2018, 2, 3) == Date(2019, 3, 3)) ;
        EXPECT_FALSE(Date(2018, 2, 3) == Date(2018, 3, 3)) ;
        EXPECT_FALSE(Date(2018, 2, 3) == Date(2018, 2, 4)) ;

    }

    {

        EXPECT_FALSE(Date::Undefined() == Date::Undefined()) ;

    }

}

TEST (Library_Physics_Time_Date, NotEqualToOperator)
{

    using library::physics::time::Date ;

    {

        EXPECT_TRUE(Date(2018, 2, 3) != Date(2019, 3, 3)) ;
        EXPECT_TRUE(Date(2018, 2, 3) != Date(2018, 3, 3)) ;
        EXPECT_TRUE(Date(2018, 2, 3) != Date(2018, 2, 4)) ;

    }

    {

        EXPECT_FALSE(Date(2018, 1, 1) != Date(2018, 1, 1)) ;
        EXPECT_FALSE(Date(1400, 1, 1) != Date(1400, 1, 1)) ;
        EXPECT_FALSE(Date(2018, 2, 3) != Date(2018, 2, 3)) ;

    }

    {

        EXPECT_TRUE(Date::Undefined() != Date::Undefined()) ;

    }

}

TEST (Library_Physics_Time_Date, StreamOperator)
{

    using library::physics::time::Date ;

    {

        testing::internal::CaptureStdout() ;

        EXPECT_NO_THROW(std::cout << Date(2018, 2, 3) << std::endl) ;

        EXPECT_FALSE(testing::internal::GetCapturedStdout().empty()) ;

    }

}

TEST (Library_Physics_Time_Date, IsDefined)
{

    using library::physics::time::Date ;

    {

        EXPECT_TRUE(Date(2018, 2, 3).isDefined()) ;
        
        EXPECT_TRUE(Date(1400, 1, 1).isDefined()) ;
        EXPECT_TRUE(Date(9999, 1, 1).isDefined()) ;

    }

    {
        
        EXPECT_FALSE(Date::Undefined().isDefined()) ;

    }

}

TEST (Library_Physics_Time_Date, GetYear)
{

    using library::physics::time::Date ;

    {

        EXPECT_EQ(2018, Date(2018, 2, 3).getYear()) ;
        
        EXPECT_EQ(1400, Date(1400, 1, 1).getYear()) ;
        EXPECT_EQ(9999, Date(9999, 1, 1).getYear()) ;

    }

    {
        
        EXPECT_ANY_THROW(Date::Undefined().getYear()) ;

    }

}

TEST (Library_Physics_Time_Date, GetMonth)
{

    using library::physics::time::Date ;

    {

        EXPECT_EQ(1, Date(2018, 1, 1).getMonth()) ;
        EXPECT_EQ(12, Date(2018, 12, 1).getMonth()) ;

    }

    {
        
        EXPECT_ANY_THROW(Date::Undefined().getMonth()) ;

    }

}

TEST (Library_Physics_Time_Date, GetDay)
{

    using library::physics::time::Date ;

    {

        EXPECT_EQ(1, Date(2018, 1, 1).getDay()) ;
        EXPECT_EQ(31, Date(2018, 1, 31).getDay()) ;

    }

    {
        
        EXPECT_ANY_THROW(Date::Undefined().getDay()) ;

    }

}

TEST (Library_Physics_Time_Date, GetString)
{

    using library::physics::time::Date ;

    {

        EXPECT_EQ("2000-01-01", Date(2000, 1, 1).getString()) ;
        EXPECT_EQ("2018-12-31", Date(2018, 12, 31).getString()) ;

        EXPECT_EQ("1400-01-01", Date(1400, 1, 1).getString()) ;
        EXPECT_EQ("9999-12-31", Date(9999, 12, 31).getString()) ;

    }

    {
        
        EXPECT_ANY_THROW(Date::Undefined().getString()) ;

    }

}

TEST (Library_Physics_Time_Date, SetYear)
{

    using library::physics::time::Date ;

    {

        Date date(2018, 1, 1) ;

        EXPECT_EQ(2018, date.getYear()) ;

        EXPECT_NO_THROW(date.setYear(2019)) ;

        EXPECT_EQ(2019, date.getYear()) ;

    }

    {
        
        EXPECT_ANY_THROW(Date::Undefined().setYear(2018)) ;

    }

}

TEST (Library_Physics_Time_Date, SetMonth)
{

    using library::physics::time::Date ;

    {

        Date date(2018, 1, 1) ;

        EXPECT_EQ(1, date.getMonth()) ;

        EXPECT_NO_THROW(date.setMonth(2)) ;

        EXPECT_EQ(2, date.getMonth()) ;

    }

    {
        
        EXPECT_ANY_THROW(Date::Undefined().setMonth(1)) ;
        
        EXPECT_ANY_THROW(Date(2018, 1, 1).setMonth(0)) ;
        EXPECT_ANY_THROW(Date(2018, 1, 1).setMonth(13)) ;

    }

}

TEST (Library_Physics_Time_Date, SetDay)
{

    using library::physics::time::Date ;

    {

        Date date(2018, 1, 1) ;

        EXPECT_EQ(1, date.getDay()) ;

        EXPECT_NO_THROW(date.setDay(2)) ;

        EXPECT_EQ(2, date.getDay()) ;

    }

    {
        
        EXPECT_ANY_THROW(Date::Undefined().setDay(1)) ;
        
        EXPECT_ANY_THROW(Date(2018, 1, 1).setDay(0)) ;
        EXPECT_ANY_THROW(Date(2018, 1, 1).setDay(32)) ;

    }

}

TEST (Library_Physics_Time_Date, Undefined)
{

    using library::physics::time::Date ;

    {

        EXPECT_NO_THROW(Date::Undefined()) ;

        EXPECT_FALSE(Date::Undefined().isDefined()) ;

    }

}

TEST (Library_Physics_Time_Date, J2000)
{

    using library::physics::time::Date ;

    {

        EXPECT_EQ(Date(2000, 1, 1), Date::J2000()) ;

    }

}

TEST (Library_Physics_Time_Date, GPSEpoch)
{

    using library::physics::time::Date ;

    {

        EXPECT_EQ(Date(1980, 1, 6), Date::GPSEpoch()) ;

    }

}

TEST (Library_Physics_Time_Date, UnixEpoch)
{

    using library::physics::time::Date ;

    {

        EXPECT_EQ(Date(1970, 1, 1), Date::UnixEpoch()) ;

    }

}

TEST (Library_Physics_Time_Date, ModifiedJulianDateEpoch)
{

    using library::physics::time::Date ;

    {

        EXPECT_EQ(Date(1858, 11, 17), Date::ModifiedJulianDateEpoch()) ;

    }

}

TEST (Library_Physics_Time_Date, Parse)
{

    using library::physics::time::Date ;

    {

        EXPECT_EQ(Date(2000, 1, 1), Date::Parse("2000-01-01")) ;
        EXPECT_EQ(Date(1980, 1, 6), Date::Parse("1980-01-06")) ;
        EXPECT_EQ(Date(1970, 1, 1), Date::Parse("1970-01-01")) ;
        EXPECT_EQ(Date(1858, 11, 17), Date::Parse("1858-11-17")) ;
        
        EXPECT_EQ(Date(1400, 1, 1), Date::Parse("1400-01-01")) ;
        EXPECT_EQ(Date(9999, 12, 31), Date::Parse("9999-12-31")) ;

    }

    {

        EXPECT_ANY_THROW(Date::Parse("")) ;
        EXPECT_ANY_THROW(Date::Parse("abc")) ;
        EXPECT_ANY_THROW(Date::Parse("2018")) ;
        EXPECT_ANY_THROW(Date::Parse("2018-01")) ;
        EXPECT_ANY_THROW(Date::Parse("2018-1-01")) ;
        EXPECT_ANY_THROW(Date::Parse("2018-01-1")) ;
        EXPECT_ANY_THROW(Date::Parse("2018-1-1")) ;
        EXPECT_ANY_THROW(Date::Parse("+2018-01-01")) ;
        EXPECT_ANY_THROW(Date::Parse("2018 01 01")) ;
        EXPECT_ANY_THROW(Date::Parse("-2000-01-01")) ;
        EXPECT_ANY_THROW(Date::Parse("-32769-01-01")) ;
        EXPECT_ANY_THROW(Date::Parse("32768-01-01")) ;

    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////