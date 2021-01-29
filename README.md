# pigeon_logfile_manager

Provides API to write log files

### Classes
   #### Logfile_manager(std::string log_file_path, std::string log_file_name)
   
   When declaring a class, you must provide the log_file_path and log_file_name.
   
   ex ) 
   
   - log_file_path : /home/pigeon/log_files
   
   - log_file_name : PigeonLogFile
   
   ### API Lists
   - #### std::string OpenLogFile();
   
     Open log file
     
     return : log_file_path/log_file_name-date.csv
     
   - #### bool CloseLogFile()
     
     Close log file
     
     return : true
   
   - #### bool WriteLogFile(std::string text)
     
     Write the contents provided in the text argument to the log file
     
     return : true
     
   - #### std::string LogFileManager(int trigger)
     
     Manage log files according to the value passed to the trigger argument
     
     - ##### 0 : reset
     
       Delete the current log file and create a new one
       
       return : "reset LogFile"
       
     - ##### 1 : save
     
       Save the log file being created and create a new one
       
       return : "save LogFile"
       
      - ##### 2 : remove all
     
        Delete all log files under the provided path and create a new one
       
        return : "remove all LogFile"
     
   - #### std::string GetNowTime()
     
     Get the current time on your computer
     
     return : Your computer's current time
     
     
   
   
   
