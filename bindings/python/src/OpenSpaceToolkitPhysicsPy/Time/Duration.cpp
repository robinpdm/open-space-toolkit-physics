////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Open Space Toolkit ▸ Physics
/// @file           bindings/python/src/OpenSpaceToolkitPhysicsPy/Time/Duration.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <OpenSpaceToolkit/Physics/Time/Duration.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline void                     OpenSpaceToolkitPhysicsPy_Time_Duration     (           pybind11::module&           aModule                                     )
{

    using namespace pybind11 ;

    using ostk::core::types::String ;

    using ostk::physics::time::Duration ;

    class_<Duration> duration_class(aModule, "Duration") ;

    duration_class.def(init<int>())

        .def(self == self)
        .def(self != self)

        .def(self < self)
        .def(self <= self)
        .def(self > self)
        .def(self >= self)

        .def(self + self)
        .def(self - self)
        .def(self * double())
        .def(self / double())

        .def(self += self)
        .def(self -= self)
        .def(self *= double())
        .def(self /= double())

        .def("__str__", &(shiftToString<Duration>))
        .def("__repr__", +[] (const Duration& aDuration) -> std::string { return aDuration.toString() ; })

        .def("is_defined", &Duration::isDefined)
        .def("is_zero", &Duration::isZero)
        .def("is_positive", &Duration::isPositive)
        .def("is_strictly_positive", &Duration::isStrictlyPositive)
        .def("is_near", &Duration::isNear)

        .def("get_nanoseconds", &Duration::getNanoseconds)
        .def("get_microseconds", &Duration::getMicroseconds)
        .def("get_milliseconds", &Duration::getMilliseconds)
        .def("get_seconds", &Duration::getSeconds)
        .def("get_minutes", &Duration::getMinutes)
        .def("get_hours", &Duration::getHours)
        .def("get_days", &Duration::getDays)
        .def("get_weeks", &Duration::getWeeks)
        .def("in_nanoseconds", &Duration::inNanoseconds)
        .def("in_microseconds", &Duration::inMicroseconds)
        .def("in_milliseconds", &Duration::inMilliseconds)
        .def("in_seconds", &Duration::inSeconds)
        .def("in_minutes", &Duration::inMinutes)
        .def("in_hours", &Duration::inHours)
        .def("in_days", &Duration::inDays)
        .def("in_weeks", &Duration::inWeeks)
        .def("in_unit", &Duration::in)
        .def("get_absolute", &Duration::getAbsolute)
        .def("to_string", +[] (const Duration& aDuration) -> String { return aDuration.toString() ; })
        .def("to_string", +[] (const Duration& aDuration, const Duration::Format& aFormat) -> String { return aDuration.toString(aFormat) ; })

        .def_static("undefined", &Duration::Undefined)
        .def_static("zero", &Duration::Zero)
        .def_static("nanoseconds", &Duration::Nanoseconds)
        .def_static("microseconds", &Duration::Microseconds)
        .def_static("milliseconds", &Duration::Milliseconds)
        .def_static("seconds", &Duration::Seconds)
        .def_static("minutes", &Duration::Minutes)
        .def_static("hours", &Duration::Hours)
        .def_static("days", &Duration::Days)
        .def_static("weeks", &Duration::Weeks)
        .def_static("between", &Duration::Between)

    ;

    enum_<Duration::Format>(duration_class, "Format")

        .value("Undefined", Duration::Format::Undefined)
        .value("Standard", Duration::Format::Standard)
        .value("ISO8601", Duration::Format::ISO8601)

    ;

    duration_class.def_static("parse", &Duration::Parse, "aString"_a, "aFormat"_a=Duration::Format::Undefined) ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
