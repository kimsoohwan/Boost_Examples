#ifndef _BOOST_SERIALIZATION_DRIVED_CLASS_HPP_
#define _BOOST_SERIALIZATION_DRIVED_CLASS_HPP_

// STL
#include <string>

// Boost
#include <boost/serialization/base_object.hpp>

// Boost Serialization Tutorial
#include "serializable_members.hpp"

class Bus_Stop_Corner : public Bus_Stop
{
public:
	// constructors
	Bus_Stop_Corner(){}
	Bus_Stop_Corner(const GPS_Position &latitude_, 
						 const GPS_Position &longitude_,
						 const std::string	&s1_,
						 const std::string	&s2_)
		: Bus_Stop(latitude_, longitude_), 
		  street1(s1_),
		  street2(s2_)
	{}

	// operators
	bool operator==(const Bus_Stop_Corner &other) const
	{
		if (this == &other) return true;
		return (static_cast<Bus_Stop>(*this) == static_cast<Bus_Stop>(other)	&&
				  street1 == other.street1		&&
				  street2 == other.street2);
	}
	
	bool operator!=(const Bus_Stop_Corner &other) const
	{
		return !(*this == other);
	}

	virtual std::string description() const
	{
		return street1 + " and " + street2;
	}

private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        // serialize base class information
        ar & boost::serialization::base_object<Bus_Stop>(*this);
        ar & street1;
        ar & street2;
    }

    std::string street1;
    std::string street2;
};

#endif