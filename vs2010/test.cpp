#include "../serialization/test_serialization.hpp"		// serialization
#include "../filesystem/test_filesystem.hpp"				// filesystem
#include "../tokenizer/test_tokenizer.hpp"				// tokenizer
#include "../lexical_cast/test_lexical_cast.hpp"		// lexical_cast
#include "../log/test_log.hpp"								// log
#include "../chrono/test_chrono.hpp"						// chrono
#include "../timer/test_timer.hpp"							// timer

int main(int argc, char** argv) 
{ 
	// Initialize test environment
	::testing::InitGoogleTest(&argc, argv);
		
	// Test
	int ret = RUN_ALL_TESTS(); 

	system("pause");
	return ret;
}