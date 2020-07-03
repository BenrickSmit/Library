#include "library.h"  

Library* Library::m_object = nullptr;
Library::LEVEL Library::m_message_level = LEVEL0;
Library::OUTPUT_TYPE Library::m_output_type = BOTH;
std::string Library::m_filename = "information.log";

// Constructors and Destructors
Library::Library(){
    // Clear the vector and the files previously created
    delete_file();

    // Set the constant filename
    m_filename = "information.log";

    // Set the basic level
    set_level(ALL);
}

Library::~Library(){
    // Do nothing for now
    //delete this->m_object;
    // Make sure all the threads are finished before continuing;
}

// The get instance function
Library* Library::get_instance(){
    if (m_object == nullptr){
        m_object = new Library();
    }//end of if
    return m_object;
}

// Public Functions
void Library::log_error(std::wstring input, bool display_message) {
    //Ensure the function doesn't log if it's not necessary to
    if(!display_message){
        return;
    }//end of if

    std::wstring basic = L"";
    std::wstring console = L"";

    basic = L" [ ERROR   ] " + input;
    console = get_coloured_text(WHITE, L" [") + get_coloured_text(RED, L" ERROR   ") + get_coloured_text(WHITE, L"] ") + input;

    // Output the text created
    if (m_output_type == FILE_ONLY){
        log_to_file(basic + L"\n", ERROR);
    }else if(m_output_type == CONSOLE_ONLY){
        log_to_console(console + L"\n", ERROR);
    }else{
        log_to_file(basic + L"\n", ERROR);
        log_to_console(console + L"\n", ERROR);
    }// end of if else
    
}

void Library::log_warning(std::wstring input, bool display_message) {
    //Ensure the function doesn't log if it's not necessary to
    if(!display_message){
        return;
    }//end of if

    std::wstring basic = L"";
    std::wstring console = L"";

    basic = L" [ WARNING ] " + input;
    console = get_coloured_text(WHITE, L" [") + get_coloured_text(YELLOW, L" WARNING ") + get_coloured_text(WHITE, L"] ") + input;

    // Output the text created
    if (m_output_type == FILE_ONLY){
        log_to_file(basic + L"\n", ERROR);
    }else if(m_output_type == CONSOLE_ONLY){
        log_to_console(console + L"\n", ERROR);
    }else{
        log_to_file(basic + L"\n", ERROR);
        log_to_console(console + L"\n", ERROR);
    }// end of if else
}

void Library::log_info(std::wstring input, bool display_message) {
    //Ensure the function doesn't log if it's not necessary to
    if(!display_message){
        return;
    }//end of if

    std::wstring basic = L"";
    std::wstring console = L"";

    basic = L" [ INFO    ] " + input;
    console = get_coloured_text(WHITE, L" [") + get_coloured_text(WHITE, L" INFO    ") + get_coloured_text(WHITE, L"] ") + input;

    // Output the text created
    if (m_output_type == FILE_ONLY){
        log_to_file(basic + L"\n", ERROR);
    }else if(m_output_type == CONSOLE_ONLY){
        log_to_console(console + L"\n", ERROR);
    }else{
        log_to_file(basic + L"\n", ERROR);
        log_to_console(console + L"\n", ERROR);
    }// end of if else
    
}

void Library::log_general(std::wstring input, bool display_message) {
    //Ensure the function doesn't log if it's not necessary to
    if(!display_message){
        return;
    }//end of if

    std::wstring basic = L"";
    std::wstring console = L"";

    basic = L" [ GENERAL ] " + input;
    console = get_coloured_text(WHITE, L" [") + get_coloured_text(WHITE, L" GENERAL ") + get_coloured_text(WHITE, L"] ") + input;

    // Output the text created
    if (m_output_type == FILE_ONLY){
        log_to_file(basic + L"\n", ERROR);
    }else if(m_output_type == CONSOLE_ONLY){
        log_to_console(console + L"\n", ERROR);
    }else{
        log_to_file(basic + L"\n", ERROR);
        log_to_console(console + L"\n", ERROR);
    }// end of if else
    
}

void Library::log_pass(std::wstring input, bool display_message) {
    //Ensure the function doesn't log if it's not necessary to
    if(!display_message){
        return;
    }//end of if

    std::wstring basic = L"";
    std::wstring console = L"";

    basic = L" [ PASS    ] " + input;
    console = get_coloured_text(WHITE, L" [") + get_coloured_text(GREEN, L" PASS    ") + get_coloured_text(WHITE, L"] ") + input;

    // Output the text created
    if (m_output_type == FILE_ONLY){
        log_to_file(basic + L"\n", ERROR);
    }else if(m_output_type == CONSOLE_ONLY){
        log_to_console(console + L"\n", ERROR);
    }else{
        log_to_file(basic + L"\n", ERROR);
        log_to_console(console + L"\n", ERROR);
    }// end of if else
    
}

void Library::log_fail(std::wstring input, bool display_message) {
    //Ensure the function doesn't log if it's not necessary to
    if(!display_message){
        return;
    }//end of if

    std::wstring basic = L"";
    std::wstring console = L"";

    basic = L" [ FAIL    ] " + input;
    console = get_coloured_text(WHITE, L" [") + get_coloured_text(RED, L" FAIL    ") + get_coloured_text(WHITE, L"] ") + input;

    // Output the text created
    if (m_output_type == FILE_ONLY){
        log_to_file(basic + L"\n", ERROR);
    }else if(m_output_type == CONSOLE_ONLY){
        log_to_console(console + L"\n", ERROR);
    }else{
        log_to_file(basic + L"\n", ERROR);
        log_to_console(console + L"\n", ERROR);
    }// end of if else
    
}

void Library::log_line(std::wstring input, int counter, bool display_message){
    //Ensure the function doesn't log if it's not necessary to
    if(!display_message){
        return;
    }//end of if

    // Create a line to log
    std::wstring to_log = L"";

    for (auto count = 0; count < counter; count++){
        to_log += input;
    }// end of for

    // Output the text created
    if (m_output_type == FILE_ONLY){
        log_to_file(to_log + L"\n", ERROR);
    }else if(m_output_type == CONSOLE_ONLY){
        log_to_console(to_log + L"\n", ERROR);
    }else{
        log_to_file(to_log + L"\n", ERROR);
        log_to_console(to_log + L"\n", ERROR);
    }// end of if else
}

void Library::log_start_process(bool display_message){
    //Ensure the function doesn't log if it's not necessary to
    if(!display_message){
        return;
    }//end of if

    // Output the text created
    if (m_output_type == FILE_ONLY){
        log_to_file(L"\n", ERROR);
    }else if(m_output_type == CONSOLE_ONLY){
        log_to_console(L"\n", ERROR);
    }else{
        log_to_file(L"\n", ERROR);
        log_to_console(L"\n", ERROR);
    }// end of if else
}

void Library::log_process(std::wstring process_name, int counter, bool display_message){
    // This function will use the carriage return to create a string and display it on the console, in the 
    // same way that the terminal would on *nix systems
    
    //Ensure the function doesn't log if it's not necessary to
    if(!display_message){
        return;
    }//end of if

    // Set the counter to a value between 0 and 100;
    if (counter > 100){
        counter = 100;
    }else {
        counter = counter;
    }

    // Convert the string to a 10 character name
    std::wstring name = process_name.substr(0, 17) + L"...";
    std::wstring progress_bar = get_progress(counter);

    // Create the final string
    std::string number = std::to_string(counter);
    number = number.substr(0, number.find('.'));
    std::wstring final_string = name + L"\t" + progress_bar + L" " + std::wstring(number.begin(), number.end()) + L"%";

    // These rules are slighlty special
    // Output to the console, if the message should be displayed, and  the message type is CONSOLE
    // Output only to file if the counter == 100
    if ((((m_output_type == FILE_ONLY) || (m_output_type == BOTH)))){
        if(counter == 100){
            log_to_file(final_string + L"\n", INFO);
        }// end of if
    }
    if(((m_output_type == CONSOLE_ONLY) || (m_output_type == BOTH))){
        log_to_console(L"\r"+ final_string, INFO);
    } // end of if
}

void Library::log_end_process(bool display_message){
    log_start_process(display_message);
}



void Library::log_error(std::string input, bool display_message) {
    std::wstring w_input = std::wstring(input.begin(), input.end());
    log_error(w_input, display_message);
}


void Library::log_warning(std::string input, bool display_message) {
    std::wstring w_input = std::wstring(input.begin(), input.end());
    log_warning(w_input, display_message);
}


void Library::log_info(std::string input, bool display_message) {
    std::wstring w_input = std::wstring(input.begin(), input.end());
    log_info(w_input, display_message);
}


void Library::log_general(std::string input, bool display_message) {
    std::wstring w_input = std::wstring(input.begin(), input.end());
    log_general(w_input, display_message);
}


void Library::log_pass(std::string input, bool display_message) {
    std::wstring w_input = std::wstring(input.begin(), input.end());
    log_pass(w_input, display_message);
}


void Library::log_fail(std::string input, bool display_message) {
    std::wstring w_input = std::wstring(input.begin(), input.end());
    log_fail(w_input, display_message);
}


void Library::log_process(std::string process_name, int percentage, bool display_message) {
    std::wstring w_input = std::wstring(process_name.begin(), process_name.end());
    log_process(w_input, percentage, display_message);    
}




void Library::set_level(Library::LEVEL value) {
    // This function will set the level of messages to display
    m_message_level = value;
}

void Library::set_output_type(OUTPUT_TYPE type) {
    m_output_type = type;
}


// Private Functions
void Library::log_to_file(std::wstring input, MESSAGE_TYPE value) {
    std::thread write = std::thread([this, input, value]{
        // This function will log to a file by using the vector
        if ((m_message_level == ALL) || (m_message_level == LEVEL0)){
            write_log_file(input);
        }else if(m_message_level == GENERAL_ONLY ){
            if(value == GENERAL){
                // write_log_file(input);
                write_log_file(input);
            }
        }else if(m_message_level == INFO_ONLY){
            if(value == INFO){
                // write_log_file(input);
                write_log_file(input);
            }
        }else if(m_message_level == WARNING_ONLY){
            if(value == WARNING){
                // write_log_file(input);
                write_log_file(input);
            }
        }else if(m_message_level == ERROR_ONLY){
            if(value == ERROR){
                // write_log_file(input);
                write_log_file(input);
            }
        }else if(m_message_level == LEVEL1){
            if ((value == ERROR) || (value == WARNING) || (value == INFO)) {
                // write_log_file(input);
                write_log_file(input);
            }
        }else if(m_message_level == LEVEL2){
            if ((value == ERROR) || (value == WARNING)) {
                // write_log_file(input);
                write_log_file(input);
            }
        }else if(m_message_level == LEVEL3){
            if ((value == ERROR)) {
                // write_log_file(input);
                write_log_file(input);
            }
        }//end of if else
    });
    write.join();
}

void Library::log_to_console(std::wstring input, MESSAGE_TYPE value) {
    // This funciton will log to the standard console
    
    //_setmode(_fileno(stdout), _O_U16TEXT);
    // ALL - displays all messages -> DEFAULT
    // GENERAL_ONLY - displays only GENERAL PROMPTS
    // INFO_ONLY - displays only INFO Prompts
    // WARNING_ONLY - displays only WARNING prompts
    // ERROR_ONLY - display only ERROR prompts
    // LEVEL0 == ALL.
    // LEVEL1 - displays info, warning, and  error messages
    // LEVEL2 - displays warning and error messages
    // LEVEL3 - displays only Error messages
    std::thread write = std::thread([this, input, value] {
        if ((m_message_level == ALL) || (m_message_level == LEVEL0)){
            std::wcout << input;
        }else if(m_message_level == GENERAL_ONLY ){
            if(value == GENERAL){
                // std::wcout << input << std::endl;
                std::wcout << input;
            }
        }else if(m_message_level == INFO_ONLY){
            if(value == INFO){
                // std::wcout << input << std::endl;            
                std::wcout << input;
            }
        }else if(m_message_level == WARNING_ONLY){
            if(value == WARNING){
                // std::wcout << input << std::endl;        
                std::wcout << input;
            }
        }else if(m_message_level == ERROR_ONLY){
            if(value == ERROR){
                // std::wcout << input << std::endl;            
                std::wcout << input;
            }
        }else if(m_message_level == LEVEL1){
            if ((value == ERROR) || (value == WARNING) || (value == INFO)) {
                // std::wcout << input << std::endl;
                std::wcout << input;
            }
        }else if(m_message_level == LEVEL2){
            if ((value == ERROR) || (value == WARNING)) {
                // std::wcout << input << std::endl;
                std::wcout << input;
            }
        }else if(m_message_level == LEVEL3){
            if ((value == ERROR)) {
                // std::wcout << input << std::endl;
                std::wcout << input;
            }
        }//end of if else
    });
    write.join();
}

void Library::log_to_file(std::string input, MESSAGE_TYPE value) {
    std::wstring new_input = std::wstring(input.begin(), input.end());
    log_to_file(new_input, value);
}

void Library::log_to_console(std::string input, MESSAGE_TYPE value) {
    std::wstring new_input = std::wstring(input.begin(), input.end());
    log_to_console(new_input, value);
}

void Library::delete_file() {
    // This function will clear the log file
    namespace fs = std::filesystem;
    if(fs::exists(m_filename.c_str())){
        // Delete the file if it exists
        if (remove(m_filename.c_str()) != 0){
        perror("Logging file could not be removed.");
        }// end of if
    }// end of if
}

std::wstring Library::get_coloured_text(COLOUR value, std::wstring input_string){
    // This function will return a string surrounded by the coloured ANSI escape characters
    std::wstring to_return;
    if (value == RED){
        // Only change the colour, not bold (0;), and not underlined (0m)
        to_return = L"\033[31m";
        to_return = to_return + input_string;
        to_return = to_return + L"\033[0m";
    }else if(value == GREEN){
        to_return = L"\033[32m";
        to_return = to_return + input_string;
        to_return = to_return + L"\033[0m";
    }else if(value == YELLOW){
        to_return = L"\033[93m";
        to_return = to_return + input_string;
        to_return = to_return + L"\033[0m";
    }else if(value == WHITE){
        to_return = L"\033[97m";
        to_return = to_return + input_string;
        to_return = to_return + L"\033[0m";
    }    

    return to_return;
}

void Library::write_log_file(std::wstring input) {
    std::wofstream output_file;
    output_file.open(m_filename.c_str(), std::ios::out | std::ios::app);
    if(!output_file.is_open()){
        std::string output_message = "Error opening file: \"" + m_filename + "\"";
        perror(output_message.c_str()); 
    }
    output_file << input;
    output_file.close();
}



std::wstring Library::get_progress(int count) {
    // This function takes in a value, and converts it to one out of 100. Then creates a progress bar to append
    // which it then returns
    std::wstring to_return = L"";
    std::wstring whitespace = L"____________________"; // 20 Whitespaces

    // Find convert the counter
    if (count < 100){
        count = count;
    }else if(count < 0){
        count = 0;
    }else {
        count = 100;
    }// end of if

    // Get the number of characters to add
    std::wstring character = L"=";

    // Quick and Dirty method
    int number_of_chars = (count == 0 ? 0:std::ceil(count/5.0));

    for (int i = 0; i < number_of_chars; i++) {
        to_return += character;
    }// end of for

    // Remove the parts from the empty string that aren't necessary
    std::wstring composite = to_return + whitespace.substr(0, (20 - to_return.length()));

    // Reset the to_return string for the ending string
    to_return = composite;

    return (L"[" + to_return + L"] ");
}
