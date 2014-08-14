#ifndef _BOOST_SERIALIZATION_NON_INVASIVE_TEST_HPP_
#define _BOOST_SERIALIZATION_NON_INVASIVE_TEST_HPP_

// STL
#include <string>
#include <fstream>

// Google Test
#include "gtest/gtest.h"

// Boost Serialization Tutorial
#include "non_invasive.hpp"

/** @brief Serialization Test */
TEST(Serialization, Non_Invasive)
{
	// filename
	std::string strFileName("GPS_Position.text");

	// create class instance
	const GPS_Position g(35, 59, 24.567f);
	
	// save data to archive
	{
		// create and open a character archive for output
		std::ofstream ofs(strFileName);
		boost::archive::text_oarchive oa(ofs);

		// write class instance to archive
      oa << g;
		
		// archive and stream closed when destructors are called
	}
	
	// load data from archive
   GPS_Position newg;
	{
		// create and open a character archive for input
		std::ifstream ifs(strFileName);
		boost::archive::text_iarchive ia(ifs);
		
		// read class state from archive
		ia >> newg;
		// archive and stream closed when destructors are called
	}

	EXPECT_EQ(g, newg);
}


#endif