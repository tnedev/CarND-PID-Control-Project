#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {
}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  prev_cte = 0.0; // Used to store the previous error value
  int_cte = 0.0; // Used to accumulate integral error
  i_error_max = 0.2; // Used to set the maximum error integral term could reach
	
}

void PID::UpdateError(double cte) {

  p_error = cte*Kp;
  d_error = Kd*(cte-prev_cte);
  prev_cte = cte;
  if(i_error < i_error_max){
    int_cte += cte;
    i_error = int_cte*Ki;
  }

}

double PID::TotalError() {

	return -p_error-d_error-i_error; 
}

