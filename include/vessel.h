#ifndef HIL_SIMULATOR_H
#define HIL_SIMULATOR_H

#include <Eigen/Dense>

class Vessel
{
 public:
  Vessel();
  ~Vessel();

  void initialize(ros::NodeHandle nh);

  void setState(Eigen::Vector3d eta, Eigen::Vector3d nu);

  void getState(Eigen::Vector3d &eta, Eigen::Vector3d &nu);

 private:
  
  Eigen::Vector3d eta, nu, nu_r, nu_c_b, nu_c_n;
  Eigen::Vector3d tau_control, tau_wind, tau_current, tau_waves;

  Eigen::Matrix3d M, M_inv, C, D, R;

  double dt;

  // Mass and inertia
  double M;
  double I_z;

  // Center of gravity
  double x_g, y_g
  
  // Added mass parameters
  double X_udot, Y_vdot, Y_rdot, N_vdot, N_rdot;
  
  // Damping parameters
  double X_u, X_v, Y_v, Y_r, N_v, N_r;
  double X_uu, X_uuu, X_vv, X_vvv, Y_vv, Y_vvv, Y_rr, Y_rrr, Y_rv, Y_vr, N_rr, N_rrr, N_vv, N_vvv, N_rv, N_vr;

  // Other
  double K_thruster;

};

#endif