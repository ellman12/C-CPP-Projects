/////////////////////////////////////////////////////////////////////
//  File:  trajectory.java
/////////////////////////////////////////////////////////////////////
//
//  Purpose:  Tests class TrajectoryComputations.
//
//  Environment:  Microsoft VS - java
//
//  Programmer: Me
//
//  Initial Development: 01/05/2020
//
//  Revisions:  8/06/2020  Converted a Java program to C/C++
//  Emphasis is on C but we throw in a C++ class to make things
//  confusing and interesting.  I prefer C.
//
//  
//
//
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

//  Disables the MS BS regarding use of ANSI C functions that are
//  very portable across compilers.
#pragma warning(disable : 4996)

#include "TrajectoryCompute.h"

    
   
   
    int main(void)  {

        double v;
        double launch_theta;
        double launch_theta_max;

        TrajectoryComputations *traj_comp;

        FILE* f;

        //  Default constructor.  Note that use will need to be made of the
        //  access functions to set the problem parameters.
        //  Note that traj_comp is a pointer to a TrajectoryComputations object.
        //  Good practice to test that object creation is successful and file
        //  open operation is successful.
        traj_comp=new TrajectoryComputations();
        if (traj_comp == NULL) {
            printf("\nMemory allocation failure, failure to create object");
            return(- 1);
        }

        f = fopen("TrajectoryData.txt", "wt");
        if (f == NULL) {
            printf("Output file failed to open");
            return(-3);
        }


        //  Setup shooting parameters.  These are private member variables
        //  of the class.  All distances in meters.
        traj_comp->set_x0(0.0);
        traj_comp->set_y0(0.5);
        traj_comp->set_x(6.0);
        traj_comp->set_y(3.0);
    

        //  Sweep through various starting velocities computing launch angles.
        //  If a valid solution write data to file, if not do not print output.
        for(v=3.0;v<25.0;v+=0.5)  {

            traj_comp->set_v(v);

            launch_theta=traj_comp->solve4Theta();

            launch_theta_max=traj_comp->solve4Theta_max();

            if ((launch_theta > 0.0) && (launch_theta_max > 0.0)) {
                printf("\nv = %.4lf  launch_thetha = %.4lf  launch_theta_max = %.4lf", v, launch_theta, launch_theta_max);
            }

            if ((launch_theta > 0.0) && (launch_theta_max > 0.0)) {
                fprintf(f, "\nv = %.4lf  launch_thetha = %.4lf  launch_theta_max = %.4lf", v, launch_theta, launch_theta_max);
            }
        }

        //  Don't forget to close the file and to free memory.
        fclose(f);
        delete(traj_comp);
        return(0);
    }

