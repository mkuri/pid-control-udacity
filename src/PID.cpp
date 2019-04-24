#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {
  this->count = 0;
  this->loss = 0;
}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  this->Kp = Kp_;
  this->Ki = Ki_;
  this->Kd = Kd_;

}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  this->d_error = cte - this->p_error;
  this->p_error = cte;
  this->i_error += cte;


}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  double total_error;
  total_error = -this->Kp * this->p_error
    - this->Ki * this->i_error - this->Kd * this->d_error;
  return total_error; // TODO: Add your total error calc here!
}

void PID::UpdateLoss(double cte) {
  count++;
  loss += std::abs(cte);
}

void PID::Print() {
  if (this->count % 100 == 0) {
    std::cout << "count: " << this->count << std::endl;
    std::cout << "loss: " << this->loss << std::endl;
  }
}
