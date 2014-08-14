#ifndef _BOOST_LOG_TEST_HPP_
#define _BOOST_LOG_TEST_HPP_

#if BOOST_VERSION > 105400 // Boost 1.54

#include <boost/log/trivial.hpp>

TEST(Log, Trivial)
{
	BOOST_LOG_TRIVIAL(trace)	<< "A trace severity message";
	BOOST_LOG_TRIVIAL(debug)	<< "A debug severity message";
	BOOST_LOG_TRIVIAL(info)		<< "An informational severity message";
	BOOST_LOG_TRIVIAL(warning)	<< "A warning severity message";
	BOOST_LOG_TRIVIAL(error)	<< "An error severity message";
	BOOST_LOG_TRIVIAL(fatal)	<< "A fatal severity message";
}

#endif

#endif