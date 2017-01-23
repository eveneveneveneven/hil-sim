#include "ros/ros.h"
#include "vessel.h"

#include <Eigen/Dense>

Vessel::Vessel()
{
	eta = Eigen::Vector3d::Zero();
	nu  = Eigen::Vector3d::Zero();
	nu_r  = Eigen::Vector3d::Zero();
	nu_c_b  = Eigen::Vector3d::Zero();
	nu_c_n  = Eigen::Vector3d::Zero();
	tau_wind = Eigen::Vector3d::Zero();
	tau_waves = Eigen::Vector3d::Zero();
	tau_current = Eigen::Vector3d::Zero();
	tau_control = Eigen::Vector3d::Zero();
}

Vessel::~Vessel() {}

bool Vessel::initialize(ros::NodeHandle nh) {
	bool parameterFail = false;

	if (!nh.getParam("m", M))
		parameterFail=true;
	if (!nh.getParam("I_z", I_z))
		parameterFail=true;
	if (!nh.getParam("x_g", x_g))
		parameterFail=true;
	if (!nh.getParam("y_g", y_g))
		parameterFail=true;

	// Added mass
	if (!nh.getParam("X_u_dot", X_u_dot))
		parameterFail=true;
	if (!nh.getParam("Y_v_dot", Y_v_dot))
		parameterFail=true;
	if (!nh.getParam("Y_r_dot", Y_r_dot))
		parameterFail=true;
	if (!nh.getParam("N_v_dot", N_v_dot))
		parameterFail=true;
	if (!nh.getParam("N_r_dot", N_r_dot))
		parameterFail=true;

	// Linear damping
	if (!nh.getParam("X_u", X_u))
		parameterFail=true;
	if (!nh.getParam("X_v", X_v))
		parameterFail=true;
	if (!nh.getParam("Y_v", Y_v))
		parameterFail=true;
	if (!nh.getParam("Y_r", Y_r))
		parameterFail=true;
	if (!nh.getParam("N_v", N_v))
		parameterFail=true;
	if (!nh.getParam("N_r", N_r))
		parameterFail=true;

	// Nonlinear damping
	if (!nh.getParam("X_uu", X_uu))
		parameterFail=true;
	if (!nh.getParam("X_uuu", X_uuu))
		parameterFail=true;
	if (!nh.getParam("X_vv", X_vv))
		parameterFail=true;
	if (!nh.getParam("X_vvv", X_vvv))
		parameterFail=true;
	if (!nh.getParam("Y_vv", Y_vv))
		parameterFail=true;
	if (!nh.getParam("Y_vvv", Y_vvv))
		parameterFail=true;
	if (!nh.getParam("Y_rr", Y_rr))
		parameterFail=true;
	if (!nh.getParam("Y_rrr", Y_rrr))
		parameterFail=true;
	if (!nh.getParam("Y_rv", Y_rv))
		parameterFail=true;
	if (!nh.getParam("Y_vr", Y_vr))
		parameterFail=true;
	if (!nh.getParam("N_rr", N_rr))
		parameterFail=true;
	if (!nh.getParam("N_rrr", N_rrr))
		parameterFail=true;
	if (!nh.getParam("N_vv", N_vv))
		parameterFail=true;
	if (!nh.getParam("N_vvv", N_vvv))
		parameterFail=true;
	if (!nh.getParam("N_rv", N_rv))
		parameterFail=true;
	if (!nh.getParam("N_vr", N_vr))
		parameterFail=true;

	// Others
	if (!nh.getParam("K_thruster", K_thruster))
		parameterFail=true;
	if (!nh.getParam("dt", dt))
		parameterFail=true;

	return parameterFail;
}