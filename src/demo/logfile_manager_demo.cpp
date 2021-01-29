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

  ROS_INFO("logfile_manager_demo_node Open");

  ros::Rate loop_rate(10);

  char temp_path[255];
  getcwd(temp_path, 255);

  Logfile_manager logfile_manager(temp_path,"DemoLogFile");

  logfile_manager.OpenLogFile();

  std::string demo_log;
  int Count = 0;

  while(ros::ok())
  {
    int return_key = 0;
    demo_log = logfile_manager.GetNowTime() + "," + std::to_string(Count) + "," + std::to_string(Count+3);
    logfile_manager.WriteLogFile(demo_log);
    return_key = ReturnInputKey();
    Count++;
    if(return_key == 113) std::cout << logfile_manager.LogFileManager(0) << std::endl; // q
    if(return_key == 119) std::cout << logfile_manager.LogFileManager(1) << std::endl; // w
    if(return_key == 101) std::cout << logfile_manager.LogFileManager(2) << std::endl; // e
    if(return_key == 27) break; // Esc
    loop_rate.sleep();
    ros::spinOnce();
  }

  logfile_manager.CloseLogFile();

  ROS_INFO("logfile_manager_demo_node Close");

  return 0;
}
