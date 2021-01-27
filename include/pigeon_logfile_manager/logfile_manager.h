#ifndef LOGFILE_MANAGER_H
#define LOGFILE_MANAGER_H

#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <sstream>


class Logfile_manager
{
public:
    Logfile_manager()
       {
          // open run
       }
       ~Logfile_manager()
       {
          // close run
       }

    std::string LogFileManager(int trigger);

    std::string SetLogFile(std::string log_file_path, std::string log_file_name);

    std::string OpenLogFile(std::string log_file_path, std::string log_file_name);

    bool CloseLogFile();

    std::string GetNowTime();

    bool WriteLogFile(std::string text);

    bool Update();

private:

    std::string log_file_path_;
    std::string log_file_name_;
    std::string log_file_;
    std::ofstream log_text_;

};

#endif // LOGFILE_MANAGER_H
