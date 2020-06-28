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
}

// The get instance function
Library* Library::get_instance(){
    if (m_object == nullptr){
        m_object = new Library();
    }//end of if
    return m_object;
}

// Public Functions
void Library::log_error(std::wstring input) {
    std::wstring basic = L"";
    std::wstring console = L"";

    basic = L" [ ERROR   ] " + input;
    console = get_coloured_text(WHITE, L" [") + get_coloured_text(RED, L" ERROR   ") + get_coloured_text(WHITE, L"] ") + input;

    // Output the text created
    if (m_output_type == FILE_ONLY){
        log_to_file(basic, ERROR);
    }else if(m_output_type == CONSOLE_ONLY){
        log_to_console(console, ERROR);
    }else{
        log_to_file(basic, ERROR);
        log_to_console(console, ERROR);
    }// end of if else
    
}

void Library::log_warning(std::wstring input) {
    std::wstring basic = L"";
    std::wstring console = L"";

    basic = L" [ WARNING ] " + input;
    console = get_coloured_text(WHITE, L" [") + get_coloured_text(YELLOW, L" WARNING ") + get_coloured_text(WHITE, L"] ") + input;

    // Output the text created
    if (m_output_type == FILE_ONLY){
        log_to_file(basic, WARNING);
    }else if(m_output_type == CONSOLE_ONLY){
        log_to_console(console, WARNING);
    }else{
        log_to_file(basic, WARNING);
        log_to_console(console, WARNING);
    }// end of if else
    
}

void Library::log_info(std::wstring input) {
    std::wstring basic = L"";
    std::wstring console = L"";

    basic = L" [ INFO    ] " + input;
    console = get_coloured_text(WHITE, L" [") + get_coloured_text(WHITE, L" INFO    ") + get_coloured_text(WHITE, L"] ") + input;

    // Output the text created
    if (m_output_type == FILE_ONLY){
        log_to_file(basic, INFO);
    }else if(m_output_type == CONSOLE_ONLY){
        log_to_console(console, INFO);
    }else{
        log_to_file(basic, INFO);
        log_to_console(console, INFO);
    }// end of if else
    
}

void Library::log_general(std::wstring input) {
    std::wstring basic = L"";
    std::wstring console = L"";

    basic = L" [ GENERAL ] " + input;
    console = get_coloured_text(WHITE, L" [") + get_coloured_text(WHITE, L" GENERAL ") + get_coloured_text(WHITE, L"] ") + input;

    // Output the text created
    if (m_output_type == FILE_ONLY){
        log_to_file(basic, GENERAL);
    }else if(m_output_type == CONSOLE_ONLY){
        log_to_console(console, GENERAL);
    }else{
        log_to_file(basic, GENERAL);
        log_to_console(console, GENERAL);
    }// end of if else
    
}

void Library::log_pass(std::wstring input) {
    std::wstring basic = L"";
    std::wstring console = L"";

    basic = L" [ PASS    ] " + input;
    console = get_coloured_text(WHITE, L" [") + get_coloured_text(GREEN, L" PASS    ") + get_coloured_text(WHITE, L"] ") + input;

    // Output the text created
    if (m_output_type == FILE_ONLY){
        log_to_file(basic, INFO);
    }else if(m_output_type == CONSOLE_ONLY){
        log_to_console(console, INFO);
    }else{
        log_to_file(basic, INFO);
        log_to_console(console, INFO);
    }// end of if else
    
}

void Library::log_fail(std::wstring input) {
    std::wstring basic = L"";
    std::wstring console = L"";

    basic = L" [ FAIL    ] " + input;
    console = get_coloured_text(WHITE, L" [") + get_coloured_text(RED, L" FAIL    ") + get_coloured_text(WHITE, L"] ") + input;

    // Output the text created
    if (m_output_type == FILE_ONLY){
        log_to_file(basic, INFO);
    }else if(m_output_type == CONSOLE_ONLY){
        log_to_console(console, INFO);
    }else{
        log_to_file(basic, INFO);
        log_to_console(console, INFO);
    }// end of if else
    
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

    if ((m_message_level == ALL) || (m_message_level == LEVEL0)){
        std::wcout << input << std::endl;
    }else if(m_message_level == GENERAL_ONLY ){
        if(value == GENERAL){
            // std::wcout << input << std::endl;
            std::wcout << input << std::endl;
        }
    }else if(m_message_level == INFO_ONLY){
        if(value == INFO){
            // std::wcout << input << std::endl;            
            std::wcout << input << std::endl;
        }
    }else if(m_message_level == WARNING_ONLY){
        if(value == WARNING){
            // std::wcout << input << std::endl;        
            std::wcout << input << std::endl;
        }
    }else if(m_message_level == ERROR_ONLY){
        if(value == ERROR){
            // std::wcout << input << std::endl;            
            std::wcout << input << std::endl;
        }
    }else if(m_message_level == LEVEL1){
        if ((value == ERROR) || (value == WARNING) || (value == INFO)) {
            // std::wcout << input << std::endl;
            std::wcout << input << std::endl;
        }
    }else if(m_message_level == LEVEL2){
        if ((value == ERROR) || (value == WARNING)) {
            // std::wcout << input << std::endl;
            std::wcout << input << std::endl;
        }
    }else if(m_message_level == LEVEL3){
        if ((value == ERROR)) {
            // std::wcout << input << std::endl;
            std::wcout << input << std::endl;
        }
    }//end of if else
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
    output_file << input << std::endl;
    output_file.close();
}


