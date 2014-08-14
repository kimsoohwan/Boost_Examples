#ifndef _BOOST_SERIALIZATION_STL_HPP_
#define _BOOST_SERIALIZATION_STL_HPP_

// STL
#include <vector>

// Boost
#include <boost/serialization/vector.hpp>

// Boost Serialization Tutorial
#include "serializable_members.hpp"

class Bus_Route_STL
{
public:
	Bus_Route_STL()
		: pStops(3)
	{
		for(size_t i = 0; i < 3; ++i)
			pStops[i] = new Bus_Stop();
	}

	// operators
	bool operator==(const Bus_Route_STL &other) const
	{
		if (this == &other) return true;
		for(size_t i = 0; i < 3; ++i)
			if(pStops[i] != pStops[i]) return false;

		return true;
	}

	bool operator!=(const Bus_Route_STL &other) const
	{
		return !(*this == other);
	}

	const Bus_Stop& operator[](std::size_t idx) const
	{
		assert(idx < 3);
		return *(pStops[idx]);
	}

	Bus_Stop& operator[](std::size_t idx)
	{
		assert(idx < 3);
		return *(pStops[idx]);
	}

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive &ar, const unsigned int version)
	{
		ar & pStops;
	}

	std::vector<Bus_Stop *> pStops;
};

#endif