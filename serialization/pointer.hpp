#ifndef _BOOST_SERIALIZATION_POINTER_HPP_
#define _BOOST_SERIALIZATION_POINTER_HPP_

// Boost Serialization Tutorial
#include "serializable_members.hpp"

class Bus_Route_Pointer
{
public:
	Bus_Route_Pointer()
	{
		for(size_t i = 0; i < 3; ++i)
			pStops[i] = new Bus_Stop();
	}

	// operators
	bool operator==(const Bus_Route_Pointer &other) const
	{
		if (this == &other) return true;
		for(size_t i = 0; i < 3; ++i)
			if(pStops[i] != pStops[i]) return false;

		return true;
	}

	bool operator!=(const Bus_Route_Pointer &other) const
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
	void serialize(Archive & ar, const unsigned int version)
	{
		for(size_t i = 0; i < 3; ++i)
			ar & pStops[i];
	}

	Bus_Stop *pStops[3];
};

#endif