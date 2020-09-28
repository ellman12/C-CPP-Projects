#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G  (double)9.80
#define PI  (double)3.14159

class   TrajectoryComputations {

private:
    double x_0;  //  inital x postion in meters
    double x;    //  target x position in meters
    double y_0;  //  initial y position in meters
    double y;    //  target y position in meters
    double v;    //  firing velocity in meters/second
    double theta;  //  firing angle in degrees



public:

    //  Default constructor
    TrajectoryComputations(void);

    //  Overloaded constructor
    TrajectoryComputations(double init_x, double targ_x, double launch_v, double init_y, double targ_y, double launch_angle);
    
    virtual ~TrajectoryComputations();

    //  Access (get/set) functions for private member variables
    void set_x0(double x);

    void set_y0(double y);

    void set_v(double launch_v);

    void set_x(double x_targ);

    void set_y(double y_targ);

    void set_theta(double theta_0);

    double get_x0(void);

    double get_y0(void);

    double get_v(void);

    double get_x(void);

    double get_y(void);


    double get_theta(void);


    double compute_tof_x(double x0, double x, double v, double theta_deg);


    double compute_tof_y(double y0, double y, double v, double theta_deg);


    double compute_tof_y_max(double y0, double y, double v, double theta_deg);


    double solve4Theta();


    double solve4Theta_max(void);
};
   