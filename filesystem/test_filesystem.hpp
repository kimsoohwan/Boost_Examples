#ifndef _BOOST_FILESYSTEM_TEST_HPP_
#define _BOOST_FILESYSTEM_TEST_HPP_

#include "filesystem.hpp"

TEST(Filesystem, FindFile)
{
	// find file in subdirectories
	std::string	str_path_found;
	EXPECT_TRUE(find_file_in_subdirectories("..\\filesystem\\",			// in this directory,
														 "test_filesystem.hpp",			// search for this name,
														 str_path_found));				// placing path here if found
	std::cout << "file found at " << str_path_found << std::endl;
}

TEST(Filesystem, SearchFiles)
{
	// search files with an extension
	std::vector<std::string> str_file_name_list;
	search_files("..\\filesystem\\", ".hpp", str_file_name_list);
	std::cout << str_file_name_list.size() << " files." << std::endl;
	for(size_t i = 0; i < str_file_name_list.size(); i++)
	{
		std::cout << str_file_name_list[i] << std::endl;
	}
}

#endif