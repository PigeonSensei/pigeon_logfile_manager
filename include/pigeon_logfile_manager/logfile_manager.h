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
    Logfile_manager(std::string log_file_path, std::string log_file_name)
      : log_file_path_(log_file_path),
        log_file_name_(log_file_name)
       {
          // open run
       }
       ~Logfile_manager()
       {
          // close run
          CloseLogFile();
       }

    std::string LogFileManager(int trigger);

    std::string OpenLogFile();

    bool CloseLogFile();

    std::string GetNowTime();

    bool WriteLogFile(std::string text);

private:

    std::string log_file_path_;
    std::string log_file_name_;
    std::string log_file_path_with_name_;
    std::ofstream log_file_;

};

#endif // LOGFILE_MANAGER_H
