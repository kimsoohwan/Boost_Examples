#ifndef _BOOST_SERIALIZATION_SHARED_POINTER_TEST_HPP_
#define _BOOST_SERIALIZATION_SHARED_POINTER_TEST_HPP_

// STL
#include <string>
#include <fstream>

// Google Test
#include "gtest/gtest.h"

// Boost Serialization Tutorial
#include "../src/invasive.hpp"
#include "../src/shared_pointer.hpp"

/** @brief Serialization Test */
TEST(Test_Shared_Pointer, Serialization)
{
	// filename
	std::string strFileName("GPS_Position.text");

	// create class instance
	const boost::shared_ptr<GPS_Position_Invasive> pG(new GPS_Position_Invasive(35, 59, 24.567f));
	
	// save data to archive
	{
		// create and open a character archive for output
		std::ofstream ofs(strFileName);
		boost::archive::text_oarchive oa(ofs);

		// write class instance to archive
      oa << pG;
		
		// archive and stream closed when destructors are called
	}
	
	// load data from archive
   boost::shared_ptr<GPS_Position_Invasive> pNewG;
	{
		// create and open a character archive for input
		std::ifstream ifs(strFileName);
		boost::archive::text_iarchive ia(ifs);
		
		// read class state from archive
		ia >> pNewG;
		// archive and stream closed when destructors are called
	}

	EXPECT_EQ(*pG, *pNewG);
}


#endif