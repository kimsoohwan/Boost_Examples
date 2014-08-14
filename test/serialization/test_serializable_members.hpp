#ifndef _BOOST_SERIALIZATION_SERIALIZABLE_MEMBERS_TEST_HPP_
#define _BOOST_SERIALIZATION_SERIALIZABLE_MEMBERS_TEST_HPP_

// STL
#include <string>
#include <fstream>

// Google Test
#include "gtest/gtest.h"

// Boost Serialization Tutorial
#include "../src/serializable_members.hpp"

/** @brief Serialization Test */
TEST(Test_Serializable_Members, Serialization)
{
	// filename
	std::string strFileName("Bus_Stop.text");

	// create class instance
	const Bus_Stop bs1(GPS_Position(35, 59, 24.567f), GPS_Position(12, 53, 24.657f));
	
	// save data to archive
	{
		// create and open a character archive for output
		std::ofstream ofs(strFileName);
		boost::archive::text_oarchive oa(ofs);

		// write class instance to archive
      oa << bs1;
		
		// archive and stream closed when destructors are called
	}
	
	// load data from archive
   Bus_Stop bs2;
	{
		// create and open a character archive for input
		std::ifstream ifs(strFileName);
		boost::archive::text_iarchive ia(ifs);
		
		// read class state from archive
		ia >> bs2;
		// archive and stream closed when destructors are called
	}

	EXPECT_EQ(bs1, bs2);
}


#endif