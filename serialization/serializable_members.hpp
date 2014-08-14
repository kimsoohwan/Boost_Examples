#ifndef _BOOST_SERIALIZATION_SERIALIZABLE_MEMBERS_HPP_
#define _BOOST_SERIALIZATION_SERIALIZABLE_MEMBERS_HPP_

// Boost Serialization Tutorial
#include "non_invasive.hpp"

class Bus_Stop
{
public:
	// constructors
	Bus_Stop(){}
	Bus_Stop(const GPS_Position &latitude_, const GPS_Position &longitude_)
		: latitude(latitude_),
		  longitude(longitude_)
	{}
	
	// destructor
	virtual ~Bus_Stop(){}
	
	// operators
	bool operator==(const Bus_Stop &other) const
	{
		if (this == &other) return true;
		return (latitude == other.latitude && longitude == other.longitude);
	}

private:
	 friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & latitude;
        ar & longitude;
    }

    GPS_Position latitude;
    GPS_Position longitude;
};

#endif