#ifndef _BOOST_LEXICAL_CAST_TEST_HPP_
#define _BOOST_LEXICAL_CAST_TEST_HPP_

// STL
#include<string>
#include <iostream>
#include <sstream>

// BOOST
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>

TEST(LexicalCast, Format)
{
	// lexical cast
	const float num = 123.456f;
	const std::string strNum = boost::lexical_cast<std::string>(num);
	const float num2 = boost::lexical_cast<float>(strNum);
	std::cout << "num original: " << num << std::endl;
	std::cout << "string: " << strNum << std::endl; // not clean
	std::cout << "num: " << num2 << std::endl;

	// format
	const float x = 123.456789f;
	const float y = 456.789123f;
	const float z = 789.123456f;
	std::stringstream ss;
	ss << boost::format("%d_%d_%d") % x % y % z;
	std::cout << ss.str() << std::endl;
}

#endif