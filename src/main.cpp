#include <iostream>
#include "include/Library/library.h"
#include <chrono>

#define DEBUG true

int main(){
	Library* logger = logger->get_instance();
	logger->set_level(Library::LEVEL0);
	logger->set_output_type(Library::BOTH);

	logger->log_error("ERROR MESSAGE (string)", DEBUG);
	logger->log_warning("WARNING MESSAGE (string)", DEBUG);
	logger->log_info("INFORMATIVE MESSAGE (string)", DEBUG);
	logger->log_general("GENERAL INFORMATION (string)", DEBUG);
	logger->log_fail("TEST FAILED (string)", DEBUG);
	logger->log_pass("TEST PASSED (string)", DEBUG);
	
	logger->log_line(L"=", 40, DEBUG);
	
	logger->log_start_process();
	for (int i = 0; i <= 100; i++){
		logger->log_process("Arbitary Process", i, DEBUG);
		auto time = std::chrono::microseconds(40000);
		std::this_thread::sleep_for(time);
	}
	logger->log_end_process();

	logger->log_line(L"=", 40, DEBUG);

	return 0;
}