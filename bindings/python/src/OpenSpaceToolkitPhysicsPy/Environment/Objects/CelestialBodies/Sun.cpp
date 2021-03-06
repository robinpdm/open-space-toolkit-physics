////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Open Space Toolkit ▸ Physics
/// @file           bindings/python/src/OpenSpaceToolkitPhysicsPy/Environment/Objects/CelestialBodies/Sun.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <OpenSpaceToolkit/Physics/Environment/Objects/CelestialBodies/Sun.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline void                     OpenSpaceToolkitPhysicsPy_Environment_Objects_CelestialBodies_Sun (        pybind11::module& aModule                            )
{

    using namespace pybind11 ;

    using ostk::core::types::Shared ;

    using ostk::physics::time::Instant ;
    using ostk::physics::env::Ephemeris ;
    using ostk::physics::env::obj::Celestial ;
    using ostk::physics::env::obj::celest::Sun ;

    {

        class_<Sun, Shared<Sun>, Celestial>(aModule, "Sun")

            .def(init<const Shared<Ephemeris>&, const Instant&>())

            .def_readonly_static("gravitational_parameter", &Sun::GravitationalParameter)
            .def_readonly_static("equatorial_radius", &Sun::EquatorialRadius)
            .def_readonly_static("flattening", &Sun::Flattening)

            .def("__str__", &(shiftToString<Sun>))
            .def("__repr__", &(shiftToString<Sun>))

            .def_static("default", &Sun::Default)

        ;

    }

    {

        // Create "sun" python submodule
        auto sun = aModule.def_submodule("sun") ;

        // Add __path__ attribute for "moon" submodule
        sun.attr("__path__") = "ostk.physics.environment.objects.celestial_bodies.sun" ;

    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
