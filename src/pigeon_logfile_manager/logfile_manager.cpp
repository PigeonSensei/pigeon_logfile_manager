#include "pigeon_logfile_manager/logfile_manager.h"

std::string Logfile_manager::LogFileManager(int trigger)
{
  std::stringstream command;
  command.str("");
  std::system(command.str().c_str());

  CloseLogFile();

  if(trigger == 0) // reset
  {
    command << "rm " << log_file_ << std::endl;
    std::system(command.str().c_str());
    OpenLogFile(log_file_path_,log_file_name_);
    trigger = -1;
    return "reset LogFile";
  }

  else if (trigger == 1) // save
  {
    OpenLogFile(log_file_path_,log_file_name_);
    trigger = -1;
    return "save LogFile";
  }

  else if (trigger == 2) // remove all
  {
    command << "rm " << log_file_path_ << "/" << log_file_name_ << "*" << std::endl;
    std::system(command.str().c_str());
    OpenLogFile(log_file_path_,log_file_name_);
    trigger = -1;
    return "remove LogFile";

  }

  return "Non Comand";


//  return true;

}

std::string Logfile_manager::OpenLogFile(std::string log_file_path, std::string log_file_name)
{
  log_file_name_ = log_file_name;
  log_file_name = log_file_name + "-"+ GetNowTime() +".csv";
  log_file_path_ = log_file_path;
  log_file_ = log_file_path + "/" + log_file_name;
  log_text_.open(log_file_);
  return log_file_;
}

std::string Logfile_manager::GetNowTime()
{
  time_t rawtime;
  struct tm *tm;
  time(&rawtime);
  tm = localtime(&rawtime);
  std::string year = std::to_string(tm->tm_year+1900);
  std::string mon = std::to_string(tm->tm_mon+1);
  std::string day =  std::to_string(tm->tm_mday);
  std::string hour = std::to_string(tm->tm_hour);
  std::string min = std::to_string(tm->tm_min);
  std::string sec = std::to_string(tm->tm_sec);

  std::string now_time;

  if(tm->tm_mon+1 <10) now_time = year + "0" + mon + day + hour + min + sec;
  else now_time = year + mon + day + hour + min + sec;

  return now_time;
}

bool Logfile_manager::WriteLogFile(std::string text)
{
  log_text_ << text << std::endl;
  return true;
}

bool Logfile_manager::CloseLogFile()
{
  log_text_.close();
  return true;
}

