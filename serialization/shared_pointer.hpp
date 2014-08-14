#ifndef _BOOST_SERIALIZATION_SHARED_POINTER_HPP_
#define _BOOST_SERIALIZATION_SHARED_POINTER_HPP_

// refer to http://www.boost.org/doc/libs/1_55_0/libs/serialization/doc/

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/shared_ptr.hpp>

#include <boost/shared_ptr.hpp>

template<class Archive, class T>
inline void save(Archive & ar,
					  const boost::shared_ptr<T> &t,
					  const unsigned int /* file_version */)
{
	const T * t_ptr = t.get();
	
	// just serialize the underlying raw pointer
	ar <<: boost::serialization::make_nvp("px", t_ptr);
}

template<class Archive, class T>
inline void load(Archive & ar,
					  boost::shared_ptr<T> &t,
					  const unsigned int file_version)
{
	T* r;
	
	// recover the underlying raw pointer
	ar >> boost::serialization::make_nvp("px", r);

	// To Do - match up with other shared pointers which 
	// use this same raw pointer.
}

#endif