#ifndef _BOOST_TIMER_TEST_HPP_
#define _BOOST_TIMER_TEST_HPP_

#include <boost/timer/timer.hpp>
#include <cmath>

TEST(Timer, AutoCpuTimer)
{
	{
		boost::timer::auto_cpu_timer t;

		for (long i = 0; i < 100000000; ++i)
			std::sqrt(123.456L); // burn some time
	}
}

//struct cpu_times
//    {
//      nanosecond_type wall;
//      nanosecond_type user;
//      nanosecond_type system;
//
//      void clear();
//    };

TEST(Timer, CpuTimer)
{
	// this is wallclock AND cpu time
	boost::timer::cpu_timer timer;
	
	for (int count = 0; count < 10; count++)
	{
		timer.resume();
		for (long i = 0; i < 10000000; ++i) std::sqrt(123.456L); // burn some time
		timer.stop();
	}
	
	boost::timer::cpu_times elapsed = timer.elapsed();
	
	// default: nano-seconds
	std::cout << "User CPU time: "		<< elapsed.user	/ 1e9		<< " seconds\n";
	std::cout << "System CPU time: "		<< elapsed.system / 1e9		<< " seconds\n";
	std::cout << "Wall-clock time: "		<< elapsed.wall	/ 1e9		<< " seconds\n";
}
#endif