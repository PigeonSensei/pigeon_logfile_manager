#include "pigeon_logfile_manager/logfile_manager.h"
#include <ros/ros.h>
#include <termios.h>
#include <unistd.h>

int ReturnInputKey()
{
  struct termios org_term;

  char input_key = 0;

  tcgetattr(STDIN_FILENO, &org_term);

  struct termios new_term = org_term;

  new_term.c_lflag &= ~(ECHO | ICANON);

  new_term.c_cc[VMIN] = 0;
  new_term.c_cc[VTIME] = 0;

  tcsetattr(STDIN_FILENO, TCSANOW, &new_term);

  read(STDIN_FILENO, &input_key, 1);

  tcsetattr(STDIN_FILENO, TCSANOW, &org_term);

  return input_key;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "logfile_manager_demo_node");
  ros::NodeHandle n;

  Logfile_manager logfile_manager;

  char temp_path[255];
  getcwd(temp_path, 255);
  logfile_manager.OpenLogFile(temp_path, "DemoLogFile");

  ros::Rate loop_rate(10);

  std::string demo_log;

//  demo_log = logfile_manager.GetNowTime() + "," + "1" + "," + "2.222";
//  logfile_manager.WriteLogFile(demo_log);

  while(ros::ok)
  {
    demo_log = logfile_manager.GetNowTime() + "," + "1" + "," + "2.222";
    logfile_manager.WriteLogFile(demo_log);
    if(ReturnInputKey() == 97) std::cout << logfile_manager.LogFileManager(0) << std::endl;
    if(ReturnInputKey() == 119) std::cout << logfile_manager.LogFileManager(1) << std::endl;
    if(ReturnInputKey() == 101) std::cout << logfile_manager.LogFileManager(2) << std::endl;
    ros::spinOnce();
    loop_rate.sleep();
    if(ReturnInputKey() == 27) break;
  }

  logfile_manager.CloseLogFile();


  ROS_INFO("Hello world!");
  return 0;
}
