//License and Author information

#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <thread>
#include <iostream>
#include <stdio.h>
#include <locale>
#include <codecvt>
#include <filesystem>

class Library {
	public:
		//Enums for ue
		// ALL Displays all the information, equavalent to LEVEL0
		// X_ONLY, only shows only those informations
		// LEVEL0, equal to ALL
		// LEVEL1, shows INFO, WARNING, and ERROR messages
		// LEVEL2, shows WARNING and ERROR messages
		// LEVEL3, shows ERROR messages
		enum LEVEL{ALL=0, GENERAL_ONLY, INFO_ONLY, WARNING_ONLY, ERROR_ONLY, LEVEL0, LEVEL1, LEVEL2, LEVEL3};
		enum OUTPUT_TYPE{CONSOLE_ONLY, FILE_ONLY, BOTH};

		// Deconstructor
		~Library();

		// Instance object
		Library* get_instance();

		// Logging functions
		void log_error(std::wstring input);
		void log_warning(std::wstring input);
		void log_info(std::wstring input);
		void log_general(std::wstring input);
		void log_pass(std::wstring input);
		void log_fail(std::wstring input);
		
		// Set logging level
		void set_level(LEVEL value);
		void set_output_type(OUTPUT_TYPE type);

	private:
		//PRIVATE ENUM Used for colour selection
		enum COLOUR{WHITE, GREEN, YELLOW, RED};
		enum MESSAGE_TYPE{GENERAL, INFO, WARNING, ERROR};

		// Delete for singleton use
		Library();
		Library(const Library&) = delete;
		Library(Library&&) = delete;
		Library& operator=(const Library&) = delete;

		// Private Functions
		void log_to_file(std::wstring input, MESSAGE_TYPE type = GENERAL);
		void log_to_console(std::wstring input, MESSAGE_TYPE type = GENERAL);

		// A thread use checking the information to write to the file
		void clear_vector();
		void delete_file();

		// Encapsulate the text in a colour
		std::wstring get_coloured_text(COLOUR value, std::wstring input_string);

		// Functions to write the logger
		void write_log_file(std::wstring input);

		// Private Members
		static Library* m_object;
		std::thread m_write_thread;
		static LEVEL m_message_level;
		static std::string m_filename;
		static OUTPUT_TYPE m_output_type;

};