#ifndef _BOOST_SERIALIZATION_NON_INVASIVE_HPP_
#define _BOOST_SERIALIZATION_NON_INVASIVE_HPP_

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

/** @brief gps coordinate */
class GPS_Position
{
public:
	// constructors
	GPS_Position(){};
	GPS_Position(int d, int m, float s)
		: degrees(d), minutes(m), seconds(s)
    {}

	// operators
	bool operator==(const GPS_Position &other) const
	{
		if (this == &other) return true;
		return (degrees == other.degrees &&
				  minutes == other.minutes &&
				  seconds == other.seconds);
	}

	bool operator!=(const GPS_Position &other) const
	{
		return !(*this == other);
	}

	// note that the members are all public
public:
    int		degrees;
    int		minutes;
    float	seconds;
};

namespace boost {
namespace serialization {

template<class Archive>
void serialize(Archive &ar, GPS_Position &g, const unsigned int version)
{
    ar & g.degrees;
    ar & g.minutes;
    ar & g.seconds;
}

} // namespace serialization
} // namespace boost

#endif