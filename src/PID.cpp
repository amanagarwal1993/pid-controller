#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_in, double Ki_in, double Kd_in) {
  p_error = 0;
  i_error = 0;
  d_error = 0;
  
  Kp = Kp_in;
  Ki = Ki_in;
  Kd = Kd_in;

  prev_cte = 0;
  sum_cte = 0;
  return;
  
};

void PID::UpdateError(double cte) {
  prev_cte = cte;
  sum_cte += cte;
  
  return;
};