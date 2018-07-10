#include <iostream>
#include <ctime>
//#include <ratio>
//#include <chrono>
using namespace std;

//John Bedette, cs162
//Set an alarm time in hours mins seconds, display it, edit it.
int getTime(hour,min,sec,sysTime);

int main(){
  //time gettting https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
  //not sure if I want to include in final proj.
  //if I could figure out what was happening and use this info to make
  //my own work, sure, but right now, I'm not sure if I totally get it.
    std::time_t t = std::time(0);
    //std::tm* now = std::localtime(&t);
    //std::cout << (now->tm_year + 1900) << '-'
     //   << (now->tm_mon + 1) << '-'
        //<< now-tm_mday
      //  << "/n"
    cout << t;
  //init vars
  int timeTotal = 0;
  int hour = 0;
  int min = 0;
  int sec= 0;
  bool isOn = false;
  char letterOption = ' '; 
   // welcome
  cout << "Hello, welcome to the most excellent alarm calculator";
  cout << endl << endl;
  getTime(hour,min,sec,t); 
  //cout << "is this when you want your alarm to go off?" << endl << endl;
  
  return 0;
};

int getTime(int hour,int min,int sec,int sysTime){

  cout << "let's set a timer" << endl;
  cout << "please enter how many hours, stick to whole positive numbers."
      << endl <<endl;
  cin >> hour;
  cout << endl << hour << "hours" << endl << endl;
  cout << "How many minutes? and again, please stick to positive whole numbers. If you go over 59 i'll tack it onto the hours." 
      << endl << endl; cin >> min;
  if(min > 59){
    hour = ++hour;
    min = min - 60;
  };

  cout << endl << endl << hour << ':' << min << endl << endl;

  cout << "how many seconds? again, please positive whole numbers and values over 59 will be applied to the minutes section." << endl << endl;
  cin >> sec;
  
  if(sec > 59){
      sec = sec - 60;
      min = ++min;
      if(min > 59){
          min = min - 60;
          hour = ++hour;
      };
  };
  cout << endl << endl << hour << ':' 
      << min << ':' 
      << sec << endl << endl;
  return 0;
};
