#ifndef _BOOST_SERIALIZATION_POINTER_TEST_HPP_
#define _BOOST_SERIALIZATION_POINTER_TEST_HPP_

// STL
#include <string>
#include <fstream>

// Google Test
#include "gtest/gtest.h"

// Boost Serialization Tutorial
#include "../src/pointer.hpp"

/** @brief Serialization Test */
TEST(Test_Pointer, Serialization)
{
	// filename
	std::string strFileName("Bus_Route.text");

	// create class instance
	Bus_Route_Pointer br1;
	br1[0] = Bus_Stop(GPS_Position(35, 59, 24.567f), GPS_Position(12, 53, 24.657f));
	br1[1] = Bus_Stop(GPS_Position(13, 42, 42.165f), GPS_Position(42, 84, 95.624f));
	br1[2] = Bus_Stop(GPS_Position(63, 79, 96.135f), GPS_Position(35, 25, 65.134f));
	
	// save data to archive
	{
		// create and open a character archive for output
		std::ofstream ofs(strFileName);
		boost::archive::text_oarchive oa(ofs);

		// write class instance to archive
      oa << br1;
		
		// archive and stream closed when destructors are called
	}
	
	// load data from archive
	Bus_Route_Pointer br2;
	{
		// create and open a character archive for input
		std::ifstream ifs(strFileName);
		boost::archive::text_iarchive ia(ifs);
		
		// read class state from archive
		ia >> br2;
		// archive and stream closed when destructors are called
	}

	EXPECT_EQ(br1, br2);
}


#endif