#ifndef _BOOST_CHRONO_TEST_HPP_
#define _BOOST_CHRONO_TEST_HPP_

#include <iostream>

#include <boost/chrono/include.hpp>
//#include <boost/chrono/chrono.hpp>
	//- #include <boost/chrono/duration.hpp>
	//- #include <boost/chrono/time_point.hpp>
	//- #include <boost/chrono/system_clocks.hpp>
	//- #include <boost/chrono/typeof/boost/chrono/chrono.hpp>
//#include <boost/chrono/chrono_io.hpp>
//#include <boost/chrono/process_cpu_clocks.hpp>
//#include <boost/chrono/thread_clocks.hpp>
//#include <boost/chrono/ceil.hpp>
//#include <boost/chrono/floor.hpp>
//#include <boost/chrono/round.hpp>

//#include <boost/chrono.hpp>
	//- #include <boost/chrono/chrono.hpp>

//#include <boost/chrono/stopwatch.hpp>

//#include "round_up.hpp"

TEST(Chrono, Duration)
{
	// minutes
	typedef boost::chrono::duration<long, boost::ratio<60> > minutes;
	minutes m1(3);							// m1 stores 3
	minutes m2(2);							// m2 stores 2
	minutes m3 = m1 + m2;				// m3 stores 5

	// microseconds
	typedef boost::chrono::duration<long long, boost::micro> microseconds;
	microseconds us1(3);					// us1 stores 3
	microseconds us2(2);					// us2 stores 2
	microseconds us3 = us1 + us2;		// us3 stores 5

	// unit conversion
	microseconds us4 = m3 + us3;		// us4 stores 300000005

	// tick count
	long long tc = us4.count();		// tc is 300000005

	// unit conversion - only conversions from coarser units to finer units are allowed.
	//minutes m4 = m3 + us3;			// compile error!
	minutes m4 = boost::chrono::duration_cast<minutes>(m3 + us3);  // m4.count() == 5
}

TEST(Chrono, RoundUp)
{
	// types
	typedef boost::chrono::milliseconds ms;
	typedef boost::chrono::nanoseconds ns;

	// nanoseconds
	ns start(13216548), end(684513654889);
	ns duration_ns = end - start;
	std::cout << "duration: " << duration_ns.count() << "ns\n";

	// unit conversion - from nanoseconds to milliseconds
	ms duration_ms = boost::chrono::duration_cast<ms>(end - start); // d now holds the number of milliseconds from start to end.
	std::cout << "unit conversion: " << duration_ms.count() << "ms\n";

	// floating point representation
	typedef boost::chrono::duration<double> sec;  // seconds, stored with a double
	sec duration_sec = end - start;
	std::cout << "floating point: " << duration_sec.count() << "s\n";

	// round up
	duration_ms = boost::chrono::ceil<ms>(end - start);
	std::cout << "round up: " << duration_ms.count() << "ms\n";

	// round down
	duration_ms = boost::chrono::floor<ms>(end - start);
	std::cout << "round down: " << duration_ms.count() << "ms\n";

	// round to nearest
	duration_ms = boost::chrono::round<ms>(end - start);
	std::cout << "round to nearest: " << duration_ms.count() << "ms\n";

	// milliseconds
	boost::chrono::milliseconds d_ms(2500);
	std::cout << "\n" << d_ms << "ms\n";
	std::cout << boost::chrono::floor<boost::chrono::seconds>(d_ms) << '\n';
	std::cout << boost::chrono::round<boost::chrono::seconds>(d_ms) << '\n';
	std::cout << boost::chrono::ceil <boost::chrono::seconds>(d_ms) << '\n';

	// ratio
	d_ms = boost::chrono::milliseconds(2516);
	typedef boost::chrono::duration<long, boost::ratio<1, 30> > frame_rate;
	std::cout << boost::chrono::floor<frame_rate>(d_ms) << '\n';
	std::cout << boost::chrono::round<frame_rate>(d_ms) << '\n';
	std::cout << boost::chrono::ceil <frame_rate>(d_ms) << '\n';

}

TEST(Chrono, SteadyClock)
{
	boost::chrono::steady_clock::time_point start = boost::chrono::steady_clock::now();

	for (long i = 0; i < 100000000; ++i) std::sqrt(123.456L); // burn some time
	
	boost::chrono::duration<double> sec = boost::chrono::steady_clock::now() - start;
	std::cout << "Steady Clock: " << sec.count() << " seconds\n";
}

TEST(Chrono, DelayLoop)
{
	// delay for at least 500 nanoseconds:
	auto go = boost::chrono::steady_clock::now() + boost::chrono::nanoseconds(500);
	size_t count(5);
	while(boost::chrono::steady_clock::now() < go)
	{
		if(count-- < 0) break;
		std::cout << boost::chrono::steady_clock::now() << "\n";
	}
}

TEST(Chrono, IO)
{
	// default
	std::cout << "milliseconds(1) = " <<  boost::chrono::milliseconds(1) << '\n';
	std::cout << "milliseconds(3) + microseconds(10) = " <<  boost::chrono::milliseconds(3) + boost::chrono::microseconds(10) << '\n';
	std::cout << "hours(3) + minutes(10) = " <<  boost::chrono::hours(3) + boost::chrono::minutes(10) << '\n';
	
	// clock tick
	typedef boost::chrono::duration<long long, boost::ratio<1, 2500000000> > ClockTick;
	std::cout << "ClockTick(3) + boost::chrono::nanoseconds(10) = " <<  ClockTick(3) + boost::chrono::nanoseconds(10) << '\n';

	// short name
	//std::cout << "\nSet cout to use short names:\n";
	//std::cout << boost::chrono::symbol_format;

	//std::cout << "milliseconds(3) + microseconds(10) = " <<  boost::chrono::milliseconds(3) + boost::chrono::microseconds(10) << '\n';
	//std::cout << "hours(3) + minutes(10) = " <<  boost::chrono::hours(3) + boost::chrono::minutes(10) << '\n';
	//std::cout << "ClockTick(3) + nanoseconds(10) = " <<  ClockTick(3) + boost::chrono::nanoseconds(10) << '\n';
}

TEST(Chrono, Clocks)
{
	// User CPU time since the process started (including user CPU time of child processes)
	boost::chrono::process_user_cpu_clock::time_point		start_user		= boost::chrono::process_user_cpu_clock::now();

	// System CPU time since the process started (including user CPU time of child processes)
	boost::chrono::process_system_cpu_clock::time_point	start_system	= boost::chrono::process_system_cpu_clock::now();

	// Wall-clock time, measured using the CPU clock of the process
	boost::chrono::process_real_cpu_clock::time_point		start_real		= boost::chrono::process_real_cpu_clock::now();

	for (long i = 0; i < 100000000; ++i) std::sqrt(123.456L); // burn some time
	
	boost::chrono::duration<double> sec_user		= boost::chrono::process_user_cpu_clock::now()		- start_user;
	boost::chrono::duration<double> sec_system	= boost::chrono::process_system_cpu_clock::now()	- start_system;
	boost::chrono::duration<double> sec_real		= boost::chrono::process_real_cpu_clock::now()		- start_real;
	std::cout << "User CPU time: "		<< sec_user.count()		<< " seconds\n";
	std::cout << "System CPU time: "		<< sec_system.count()	<< " seconds\n";
	std::cout << "Wall-clock time: "		<< sec_real.count()		<< " seconds\n"; // Warning: something is strange here!!!
}

#endif