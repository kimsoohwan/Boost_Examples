#ifndef _BOOST_TOKENIZER_TEST_HPP_
#define _BOOST_TOKENIZER_TEST_HPP_

// STL
#include<string>

// BOOST
#include<boost/tokenizer.hpp>

TEST(Tokenizer, CharSeparator)
{
	std::string s("directory_name/sub_directory_name\\file_name.txt");
	boost::char_separator<char> sep("/\\");
	boost::tokenizer<boost::char_separator<char> > tok(s, sep);
	for(boost::tokenizer<boost::char_separator<char> >::iterator beg = tok.begin(); beg != tok.end(); ++beg)
	{
		std::cout << *beg << std::endl;
	}
}

#endif