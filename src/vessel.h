#ifndef HIL_SIMULATOR_H
#define HIL_SIMULATOR_H

#include <Eigen/Dense>

using namespace std;


class Vessel
{
  
 public:
  friend Eigen::Vector3d getEta(Vessel vessel);
  Vessel();
  ~Vessel();

  bool initialize(ros::NodeHandle nh);

  void setState(Eigen::Vector3d eta, Eigen::Vector3d nu);

  void getState(Eigen::Vector3d &eta, Eigen::Vector3d &nu);

 private:
  
  Eigen::Vector3d eta, nu, nu_r, nu_c_b, nu_c_n;
  Eigen::Vector3d tau_control, tau_wind, tau_current, tau_waves;

  Eigen::Matrix3d M_tot, M_tot_inv, C, D, R;

  double dt;

  // Mass and inertia
  double M;
  double I_z;

  // Center of gravity
  double x_g, y_g;
  
  // Added mass parameters
  double X_u_dot, Y_v_dot, Y_r_dot, N_v_dot, N_r_dot;
  
  // Damping parameters
  double X_u, X_v, Y_v, Y_r, N_v, N_r;
  double X_uu, X_uuu, X_vv, X_vvv, Y_vv, Y_vvv, Y_rr, Y_rrr, Y_rv, Y_vr, N_rr, N_rrr, N_vv, N_vvv, N_rv, N_vr;

  // Other
  double K_thruster;

};
Eigen::Vector3d getEta(Vessel vessel){
  return vessel.eta;
}

#endif
