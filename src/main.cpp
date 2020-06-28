#include <iostream>
#include "include/Library/library.h"

int main(){
	Library* logger = logger->get_instance();
	logger->set_level(Library::LEVEL0);
	logger->set_output_type(Library::BOTH);

	logger->log_error(L"ERROR MESSAGE");
	logger->log_warning(L"WARNING MESSAGE");
	logger->log_info(L"INFORMATIVE MESSAGE");
	logger->log_general(L"GENERAL INFORMATION");
	logger->log_fail(L"TEST FAILED");
	logger->log_pass(L"TEST PASSED");
	

	return 0;
}