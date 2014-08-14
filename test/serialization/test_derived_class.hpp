#ifndef _BOOST_SERIALIZATION_DRIVED_CLASS_TEST_HPP_
#define _BOOST_SERIALIZATION_DRIVED_CLASS_TEST_HPP_

// STL
#include <string>
#include <fstream>

// Google Test
#include "gtest/gtest.h"

// Boost Serialization Tutorial
#include "../src/drived_class.hpp"

/** @brief Serialization Test */
TEST(Test_Drived_Class, Serialization)
{
	// filename
	std::string strFileName("Bus_Stop_Corner.text");

	// create class instance
	const Bus_Stop_Corner bsc1(GPS_Position(35, 59, 24.567f), 
										GPS_Position(12, 53, 24.657f),
										"bsc1", "bsc2");
	
	// save data to archive
	{
		// create and open a character archive for output
		std::ofstream ofs(strFileName);
		boost::archive::text_oarchive oa(ofs);

		// write class instance to archive
      oa << bsc1;
		
		// archive and stream closed when destructors are called
	}
	
	// load data from archive
   Bus_Stop_Corner bsc2;
	{
		// create and open a character archive for input
		std::ifstream ifs(strFileName);
		boost::archive::text_iarchive ia(ifs);
		
		// read class state from archive
		ia >> bsc2;
		// archive and stream closed when destructors are called
	}

	EXPECT_EQ(bsc1, bsc2);
}


#endif