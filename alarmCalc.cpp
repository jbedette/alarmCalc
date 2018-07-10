/*to do
 * 1: put in addition subtraction functionality
 * 2: get the time more accurate
 * 3: maybe do more with the time thing(get it to read out 8:30 etc.
 * 4. clean and comment*/



#include <iostream>
#include <ctime>
#include <math.h>
#include <cctype>
using namespace std;

//John Bedette, cs162
//Set an alarm time in hours mins seconds, display it, edit it.
void getTime(int[]);
void displayAlarm(int[], int);
void menuOptions();
void checkAlarm(bool);
int confirmAlarm(int[], bool);
bool turnOnAlarm();
int main(){
  //init vars
  time_t t = 0; 
  int time[4];
  int timeUntil = 0;
  bool isOn = false;
  char letterOption = ' ';
  int alarmArray[4];
   // welcome
  cout << "Hello, welcome to the most excellent alarm calculator";
  cout << endl << endl;
  getTime(time);
  t = std::time(0);
  isOn = turnOnAlarm();
  checkAlarm(isOn);
//while loop that redirects to menu/ relevant info
  while(letterOption != 'x'){
      //get updating alarm time
      time_t tUpdating = std::time(0);
      timeUntil = (time[0] * 60 * 60) + (time[1] *60)
              + time[2] + t - tUpdating;
      checkAlarm(isOn);
      alarmArray[0] = timeUntil /  3600;
      alarmArray[1] = (timeUntil % 3600)/ 60;
      alarmArray[2] = (timeUntil % 3600)%60;
      //display
      displayAlarm(alarmArray, timeUntil);
      cin >> letterOption;
      cin.ignore(100,'\n');
      if(letterOption == 'd'){
         displayAlarm(alarmArray, timeUntil); 
      }else if(letterOption == 's'){
          getTime(time);
         t = std::time(0);
      }else if(letterOption == 't'){
          cout << "switch alarm on or off?";
          isOn = turnOnAlarm();
      }else if(letterOption == 'x'){
          cout << "run program again to set a new alarm" << endl;
      }else{
          cout << "command not recognized, please enter 'd','s','t', or 'x'."
              << endl << endl;
      };
  };
  return 0;
};
// set the alarm time
// lil bit big
void getTime(int time[]){
  int hour = 0;
  int min = 0;
  int sec = 0;
  cout << "let's set a timer" << endl;
  cout << "please enter how many hours, stick to whole positive numbers."
      << endl <<endl;
  
  cin >> hour;
  cin.clear();
  cin.ignore(100,'\n');
  cout << endl << hour << "hours" << endl << endl;
  cout << "How many minutes? and again, please stick to positive whole numbers. If you go over 59 i'll tack it onto the hours." 
      << endl << endl; 

  cin >> min;
  cin.clear();
  cin.ignore(100,'\n');
  if(min > 59){
    hour = hour + (min/60);
    min = min - ((min/60) *60);
  };

  cout << endl << endl << hour << ':' << min << endl << endl;

  cout << "how many seconds? again, please positive whole numbers and values over 59 will be applied to the minutes section." << endl << endl;
  
  cin >> sec;
  cin.clear();
  cin.ignore(100,'\n');
  
  if(sec > 59){
    min = min + (sec/60);
    sec = sec - ((sec/60) * 60);
      if(min > 59){
          hour = hour + (min/60);
          min = min - ((min/6)*60);
      };
  };
  cout << endl << endl << hour << ':' 
      << min << ':' 
      << sec << endl << endl;
  if(hour < 0 || min < 0 || sec < 0 || min + sec + hour <= 0){
      cout << endl << endl << endl << 
          "==> >:( You either entered negative or no time, don't do that. >:(<=="<< endl
          << endl<< endl;
      getTime(time);
  }else{
      time[0] = hour;
      time[1] = min;
      time[2] = sec;
  }; 
  cout << "Would you like to enable this alarm off?" << endl << endl;
  cout << time[0] << ':' << time[1] << ':' << time[2] << endl << endl;
};

//this outputs the time until the alarm goes off.
void displayAlarm(int time[], int timeUntil){
  cout << "your alarm will go off in "
      << time[0] << "hours "
      << time[1] << "minutes and "
      << time[2] << " seconds" << endl << endl;
  menuOptions();
};

void menuOptions(){
  cout << "would you like to:"<< endl
      << "[d]isplay time until alarm goes off?" << endl
      << "[s]et a new alarm time?" << endl
      << "[t]urn alarm on or off" << endl
      << "e[x]it the alarm program" << endl;
};

void checkAlarm(bool isOn){
    
  if(isOn){
      cout << "okay your alarm is on" << endl << endl;
  }else{
      cout << "okay your alarm is off" << endl << endl;
  };
};

bool turnOnAlarm(){
  char letterOption = ' ';  
  cout << endl << endl << "[e]nable or [d]isable timer" << endl << endl;
  cin >> letterOption;
  cin.ignore(100,'\n');
  if(letterOption == 'e'){
    return true;
  }else if(letterOption == 'd'){
   return false;
  }else{
      cout << "please enter an [e] or a [d]";
    return turnOnAlarm();
  };
};

  //time gettting https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
  //used this ot figure out how to get system time and make an actual
  //countdown. 
