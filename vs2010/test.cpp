#include "../serialization/test_serialization.hpp" // serialization
#include "../filesystem/test_filesystem.hpp"// filesystem
#include "../lexical_cast/test_lexical_cast.hpp"// lexical_cast
#include "../cpu_timer/test_cpu_timer.hpp"// cpu_timer

int main(int argc, char** argv) 
{ 
	// Initialize test environment
	::testing::InitGoogleTest(&argc, argv);
		
	// Test
	int ret = RUN_ALL_TESTS(); 

	system("pause");
	return ret;
}