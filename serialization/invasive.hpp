#ifndef _BOOST_SERIALIZATION_INVASIVE_HPP_
#define _BOOST_SERIALIZATION_INVASIVE_HPP_

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

/** @brief gps coordinate */
class GPS_Position_Invasive
{
public:
	// constructors
	GPS_Position_Invasive(){};
	GPS_Position_Invasive(int d, int m, float s)
		: degrees(d), minutes(m), seconds(s)
    {}

	// operators
	bool operator==(const GPS_Position_Invasive &other) const
	{
		if (this == &other) return true;
		return (degrees == other.degrees &&
				  minutes == other.minutes &&
				  seconds == other.seconds);
	}

	bool operator!=(const GPS_Position_Invasive &other) const
	{
		return !(*this == other);
	}

private:
    friend class boost::serialization::access;

    // When the class Archive corresponds to an output archive, 
    // the & operator is defined similar to <<.
    // Likewise, when the class Archive is a type of input archive,
    // the & operator is defined similar to >>.
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & degrees;
        ar & minutes;
        ar & seconds;
    }

    int		degrees;
    int		minutes;
    float	seconds;
};

#endif