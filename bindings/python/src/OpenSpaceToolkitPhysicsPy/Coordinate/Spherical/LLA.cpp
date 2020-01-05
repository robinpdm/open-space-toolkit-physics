////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Open Space Toolkit ▸ Physics
/// @file           bindings/python/src/OpenSpaceToolkitPhysicsPy/Coordinate/Spherical/LLA.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <OpenSpaceToolkit/Physics/Coordinate/Spherical/LLA.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline void                     OpenSpaceToolkitPhysicsPy_Coordinate_Spherical_LLA   ( )
{

    using namespace boost::python ;

    using ostk::physics::units::Length ;
    using ostk::physics::units::Angle ;
    using ostk::physics::coord::spherical::LLA ;

    scope in_LLA = class_<LLA>("LLA", init<const Angle&, const Angle&, const Length&>())

        .def(self == self)
        .def(self != self)

        .def(self_ns::str(self_ns::self))
        .def(self_ns::repr(self_ns::self))

        .def("isDefined", &LLA::isDefined)

        .def("getLatitude", &LLA::getLatitude)
        .def("getLongitude", &LLA::getLongitude)
        .def("getAltitude", &LLA::getAltitude)
        .def("toVector", &LLA::toVector)
        .def("toCartesian", &LLA::toCartesian)
        .def("toString", &LLA::toString)

        .def("Undefined", &LLA::Undefined).staticmethod("Undefined")
        .def("Vector", &LLA::Vector).staticmethod("Vector")
        .def("Cartesian", &LLA::Cartesian).staticmethod("Cartesian")

    ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////