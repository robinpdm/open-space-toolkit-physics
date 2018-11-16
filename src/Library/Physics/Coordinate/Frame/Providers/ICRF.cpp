////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/Physics
/// @file           Library/Physics/Coordinate/Frame/Providers/ICRF.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Library/Physics/Coordinate/Frame/Providers/ICRF.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace library
{
namespace physics
{
namespace coord
{
namespace frame
{
namespace provider
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                ICRF::ICRF                                  ( )
{

}

                                ICRF::~ICRF                                 ( )
{

}

ICRF*                           ICRF::clone                                 ( ) const
{
    return new ICRF(*this) ;
}

bool                            ICRF::isDefined                             ( ) const
{
    return true ;
}

Transform                       ICRF::getTransformAt                        (   const   Instant&                    anInstant                                   ) const
{

    (void) anInstant ;

    // return Transform(anInstant, Vector3d::Zero(), Vector3d::Zero()) ; // THIS IS WRONG
    return Transform::Undefined() ;
    
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////