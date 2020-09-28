/////////////////////////////////////////////////////////////////////
//  File:  trajectory.java
/////////////////////////////////////////////////////////////////////
//
//  Purpose:  Tests class trajectoryCompute.
//
//  Environment:  Microsoft VS - java
//
//  Programmer:
//
//  Initial Development: 01/05/2020
//
//  Revisions:
//
//  01/10/20:  Added loop in velocity
//
//
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

#pragma warning(disable : 4996)

#include "TrajectoryCompute.h"



    double x_0;  //  inital x postion in meters
    double x;    //  target x position in meters
    double y_0;  //  initial y position in meters
    double y;    //  target y position in meters
    double v;    //  firing velocity in meters/second
    double theta;  //  firing angle in degrees


    double tof_x;
    double tof_y;



   
   
    int main(void)  {

        double launch_theta;
        double launch_theta_max;

        TrajectoryComputations *traj_comp;

        FILE* f;

        v=10.0;  //  10 meters per second
        x_0=0.0;
        y_0=0.5;
        x=10.0;
        y=3.0;
        theta=24;

        //  Constructor using targeting specifics
        traj_comp=new TrajectoryComputations(x_0,x,v,y_0,y,0.0);

        tof_x=traj_comp->compute_tof_x(x_0,x,v,theta);

        printf("\nX time of flight = %.4lf",tof_x);

        tof_y=traj_comp->compute_tof_y(y_0,y,v,theta);

        printf("\nY time of flight = %.4lf",tof_y);

        f = fopen("TrajectoryData.txt", "wt");
        if (f == NULL) {
            printf("Output file failed to open");
            return-1;
        }


        //  Sweep through various starting velocities computing launch angles.
        //  If a valid solution write data to file, if not do not print output.
        for(v=3.0;v<25.0;v+=0.5)  {

            //printf("\nv = %.4lf m/sec",v);

            traj_comp->set_v(v);

            launch_theta=traj_comp->solve4Theta();

            //printf("\nlaunch theta = %.4lf degrees",launch_theta);

            launch_theta_max=traj_comp->solve4Theta_max();

            //printf("\nlaunch theta = %.4lf degrees",launch_theta_max);

            if ((launch_theta > 0.0) && (launch_theta_max > 0.0)) {
                printf("\nv = %.4lf  launch_thetha = %.4lf  launch_theta_max = %.4lf", v, launch_theta, launch_theta_max);
            }

            if ((launch_theta > 0.0) && (launch_theta_max > 0.0)) {
                fprintf(f, "\nv = %.4lf  launch_thetha = %.4lf  launch_theta_max = %.4lf", v, launch_theta, launch_theta_max);
            }
        }
        fclose(f);
        delete(traj_comp);
    }

