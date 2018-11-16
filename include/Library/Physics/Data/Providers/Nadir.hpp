////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/Physics
/// @file           Library/Physics/Data/Providers/Nadir.hpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __Library_Physics_Data_Providers_Nadir__
#define __Library_Physics_Data_Providers_Nadir__

#include <Library/Physics/Environment/Objects/Celestial.hpp>
#include <Library/Physics/Environment.hpp>
#include <Library/Physics/Coordinate/Position.hpp>
#include <Library/Physics/Data/Direction.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace library
{
namespace physics
{
namespace data
{
namespace providers
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using library::physics::data::Direction ;
using library::physics::coord::Position ;
using library::physics::Environment ;
using library::physics::env::obj::Celestial ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Direction                       Nadir                                       (   const   Position&                   aPosition,
                                                                                const   Celestial&                  aCelestialObject,
                                                                                const   Environment&                anEnvironment                               ) ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////