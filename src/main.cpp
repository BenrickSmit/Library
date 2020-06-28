#include <iostream>
#include "include/Library/library.h"

#define DEBUG false

int main(){
	Library* logger = logger->get_instance();
	logger->set_level(Library::LEVEL0);
	logger->set_output_type(Library::BOTH);

	logger->log_error(L"ERROR MESSAGE", DEBUG);
	logger->log_warning(L"WARNING MESSAGE", DEBUG);
	logger->log_info(L"INFORMATIVE MESSAGE", DEBUG);
	logger->log_general(L"GENERAL INFORMATION", DEBUG);
	logger->log_fail(L"TEST FAILED", DEBUG);
	logger->log_pass(L"TEST PASSED", DEBUG);

	return 0;
}