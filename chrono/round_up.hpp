#ifndef _BOOST_CHRONO_ROUND_UP_HPP_
#define _BOOST_CHRONO_ROUND_UP_HPP_

#include <boost/chrono.hpp>

template <class ToDuration, class Rep, class Period>
ToDuration round_up(boost::chrono::duration<Rep, Period> d)
{
	// first round down
	ToDuration result = boost::chrono::duration_cast<ToDuration>(d);
	if (result < d)  // comparisons are *always* exact
		++result;     // increment by one tick period
	return result;
}

#endif