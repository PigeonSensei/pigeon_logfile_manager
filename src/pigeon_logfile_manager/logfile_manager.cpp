#include "pigeon_logfile_manager/logfile_manager.h"

std::string Logfile_manager::LogFileManager(int trigger)
{
  std::stringstream command;
  command.str("");
  std::system(command.str().c_str());

  CloseLogFile();

  if(trigger == 0) // reset
  {
    command << "rm " << log_file_path_with_name_ << std::endl;
    std::system(command.str().c_str());
    OpenLogFile();
    trigger = -1;
    return "reset LogFile";
  }

  else if (trigger == 1) // save
  {
    OpenLogFile();
    trigger = -1;
    return "save LogFile";
  }

  else if (trigger == 2) // remove all
  {
    command << "rm " << log_file_path_ << "/" << log_file_name_ << "*" << std::endl;
    std::system(command.str().c_str());
    OpenLogFile();
    trigger = -1;
    return "remove all LogFile";

  }

  return "Non Comand";

}

std::string Logfile_manager::OpenLogFile()
{
  if(log_file_path_.back() == '/') log_file_path_.pop_back();
  if(log_file_name_.front() == '/') log_file_name_.erase(0,1);
  if(log_file_name_.back() == '/') log_file_name_.pop_back();

  std::string log_file_name = log_file_name_ + "-"+ GetNowTime() +".csv";
  log_file_path_with_name_ = log_file_path_ + "/" + log_file_name;
  log_file_.open(log_file_path_with_name_);
  return log_file_path_with_name_;
}

bool Logfile_manager::CloseLogFile()
{
  log_file_.close();
  return true;
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
  log_file_ << text << std::endl;
  return true;
}


