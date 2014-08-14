#ifndef _BOOST_CPU_TIMER_TEST_HPP_
#define _BOOST_CPU_TIMER_TEST_HPP_

#include <boost/timer/timer.hpp>
#include <cmath>

TEST(CpuTimer, AutoCpuTimer)
{
	{
		boost::timer::auto_cpu_timer t;

		for (long i = 0; i < 100000000; ++i)
			std::sqrt(123.456L); // burn some time
	}
}

#endif