/////////////////////////////////////////////////////////////////////
//  File: trajectoryCompute.cpp
/////////////////////////////////////////////////////////////////////
//
//  Purpose:  This file contains functions that compute the angle
//            required to hit a target located at (x,y) from
//            location (x0,y0)  given the launch velocity.
//            
//            Note the following:
//
//            1.  The effect of air resistance is ignored.
//            2.  No compensation for the effect of spin.
//            3.  Classic trajectory physics.
//            4.  Units are MKS (metric)
//
//            The premise is that the projectile must have the
//            same time of light for the x travel and y travel.
//            When they are equal, the projectile hits the 
//            target.
//
//            Note that there are two possible solutions for
//            the y time-of-flight.  The function for the
//            y-dependence on time is a parabola.  One
//            solution hit the y target prior to reaching
//            the azimuth, the other will hit the target
//            after reaching the azimuth.
//
//            For a variety of parameter values there will
//            not be a solution.
//
//  Environment:  Microsoft C/C++
//
//  Programmer:
//
//  Initial Development: 08/06/2020
//
//  Revisions:
//
//
//
//
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

#include "TrajectoryCompute.h"


   //  Default constructor
   TrajectoryComputations::TrajectoryComputations(void)
   {
       x_0=0.0;
       y_0=0.0;
       x=0.0;
       y=0.0;
       v=0.0;
       theta=0.0;
   }

      //  Overloaded constructor
   TrajectoryComputations::TrajectoryComputations(double init_x,double targ_x,double launch_v,double init_y,double targ_y,double launch_angle)
    {
        x_0=init_x;
        y_0=init_y;
        x=targ_x;
        y=targ_y;
        v=launch_v;
        theta=launch_angle;
    }

   TrajectoryComputations::~TrajectoryComputations()
   {

   }

    //  Access (get/set) functions for private member variables
   void TrajectoryComputations::set_x0(double x)
    {
         x_0=x;

    }

    void TrajectoryComputations::set_y0(double y)
    {
         y_0=y;

    }

    void TrajectoryComputations::set_v(double launch_v)
    {
         v=launch_v;

    }

    void TrajectoryComputations::set_x(double x_targ)
    {
         x=x_targ;

    }

    void TrajectoryComputations::set_y(double y_targ)
    {
         y=y_targ;

    }

    void TrajectoryComputations::set_theta(double theta_0)
    {
         theta=theta_0;

    }


    double TrajectoryComputations::get_x0()
    {
         return(x_0);

    }
    double TrajectoryComputations::get_y0()
    {
         return(y_0);

    }
    double TrajectoryComputations::get_v()
    {
         return(v);

    }

    double TrajectoryComputations::get_x()
    {
         return(x);

    }
    double TrajectoryComputations::get_y()
    {
         return(x);

    }

    double TrajectoryComputations::get_theta()
    {
        return(theta);
    }

    /////////////////////////////////////////////////////////////////
    //  Function:     double compute_tof_x( ... )
    /////////////////////////////////////////////////////////////////
    //
    //  Purpose:  Given the velocity and distances, this function
    //            computes the time of flight along the horizontal.
    //
    //  Arguments:initial coordinates, target coordinates, launch
    //            velocity, and launch angle.  All as double.
    //
    //  Returns:  The time of flight in seconds as double
    //
    //  Remarks:  Units are MKS, angles are expressed in degrees.
    //
    /////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////
    double TrajectoryComputations::compute_tof_x(double x0,double x,double v,double theta_deg)
    {
        double tof;
        double v0_x;
        double theta_r;

        //  Convert to radians
        theta_r=theta_deg*PI/180.0;

        //  Compute horizontal velocity component
        v0_x=v*cos(theta_r);

        //  Compute time of flight
        tof=(x-x0)/v0_x;

        return(tof);

    }

    /////////////////////////////////////////////////////////////////
    //  Function:     double compute_tof_y( ... )
    /////////////////////////////////////////////////////////////////
    //
    //  Purpose:  Given the velocity and distances, this function
    //            computes the time of flight along the vertical.
    //            This function computes the shortest time, the
    //            arrival prior to the azimuth.
    //
    //  Arguments:initial coordinates, target coordinates, launch
    //            velocity, and launch angle.  All as double.
    //
    //  Returns:  The time of flight in seconds as double
    //
    //  Remarks:  Units are MKS, angles are expressed in degrees.
    //
    /////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////
    double TrajectoryComputations::compute_tof_y(double y0,double y,double v,double theta_deg)
    {
        double tof;
        double v0_y;
        double theta_r;
        double temp_arg;

        //  Convert to radians
        theta_r=theta_deg*PI/180.0;

        //  Compute vertical component
        v0_y=v*sin(theta_r);

        //  Compute the argument of the square root
        temp_arg=(v0_y*v0_y) - 4*(G/2.0)*(y-y0);

   
        //  Test for real values
        if(temp_arg<0.0)  {
            return(-999.99);
        }

        //  Compute time of flight for y
        tof=(v0_y - sqrt(temp_arg))/G;

        return(tof);

    }

    /////////////////////////////////////////////////////////////////
    //  Function:     double compute_tof_y_max( ... )
    /////////////////////////////////////////////////////////////////
    //
    //  Purpose:  Given the velocity and distances, this function
    //            computes the time of flight along the vertical.
    //            This function computes the longer time, the
    //            arrival after the azimuth.
    //
    //  Arguments:initial coordinates, target coordinates, launch
    //            velocity, and launch angle.  All as double.
    //
    //  Returns:  The time of flight in seconds as double
    //
    //  Remarks:  Units are MKS, angles are expressed in degrees.
    //
    /////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////
    double TrajectoryComputations::compute_tof_y_max(double y0,double y,double v,double theta_deg)
    {
        double tof;
        double v0_y;
        double theta_r;
        double temp_arg;

        //  Convert to radians
        theta_r=theta_deg*PI/180.0;

        //  Compute vertical component
        v0_y=v*sin(theta_r);

       //  Compute the argument of the square root
       temp_arg=(v0_y*v0_y) - 4*(G/2.0)*(y-y0);

       //  Test for real values
       if(temp_arg<0.0)  {
           return(-999.99);
       }

       //  Compute time of flight for y
       tof=(v0_y + sqrt(temp_arg))/G;

       return(tof);

    }

    /////////////////////////////////////////////////////////////////
    //  Function:  solve4Theta()
    /////////////////////////////////////////////////////////////////
    //
    //  Purpose:  Computes the launch angle in degrees where the x and
    //            y time-of-flight values are equal.  It firsts 
    //            determines the minimum launch angle represented by
    //            a direct line of sight.  From this point the
    //            routine searchs for the minimum difference between
    //            the x and y tofs.  If the routine fails to minimize
    //            the difference to less than one second it is 
    //            assumed that a solution does not exist.
    //
    //  Arguments:void
    //
    //  Returns:  The launch angle in degress expressed as double.
    //
    //  Remarks:  This function computes the shortest route, i.e.,
    //            y target hit before azimuth.
    //
    /////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////
    double TrajectoryComputations::solve4Theta()
    {
        double min_theta;
        double theta;
        double best_theta=0.0;
        double delta;
        double min_delta=2000.00;
        double launch_theta;
        double tof_x;
        double tof_y;
        bool debug=false;


        //  minimum theta is direct line of sight
        //  this function will return the value in radians
        min_theta=atan2((y-y_0),(x-x_0));

        //  convert to degrees
        min_theta=(180.0/PI)*min_theta;

        //  Search for minimum delta of tof x & y
        for(theta=min_theta;theta<90.0;theta+=.01)  {
            //  These functions require that theta is in degrees.
            tof_y=compute_tof_y(y_0,y,v,theta);  
            tof_x=compute_tof_x(x_0,x,v,theta);  

            delta=(tof_y-tof_x);
            if (delta < 0.0)delta *= -1.0;
            if(delta<min_delta)  {
                min_delta=delta;
                best_theta=theta;
                if(debug==true)
                {
                    printf("\nmin_delta = %.4lf best_theta = %.4lf" ,min_delta,best_theta);
                }
            }

        }

        //  Limit tof difference to 1 second
        if(min_delta>1.0)  {
            printf("\nNo solution exists with the given parameters.");
            return(0.0);
        }
        launch_theta=best_theta;
        return(launch_theta);
    }

    /////////////////////////////////////////////////////////////////
    //  Function:  solve4Theta_max()
    /////////////////////////////////////////////////////////////////
    //
    //  Purpose:  Computes the launch angle in degrees where the x and
    //            y time-of-flight values are equal.  It firsts 
    //            determines the minimum launch angle represented by
    //            a direct line of sight.  From this point the
    //            routine searchs for the minimum difference between
    //            the x and y tofs.  If the routine fails to minimize
    //            the difference to less than one second it is 
    //            assumed that a solution does not exist.
    //
    //  Arguments:void
    //
    //  Returns:  The launch angle in degress expressed as double.
    //
    //  Remarks:  This function computes the longest route, i.e.,
    //            y target hit after azimuth.
    //
    /////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////
    double TrajectoryComputations::solve4Theta_max()
    {
        double min_theta;
        double theta;
        double best_theta=0.0;
        double delta;
        double min_delta=2000.00;
        double launch_theta;
        double tof_x;
        double tof_y;
        bool debug=false;


        //  minimum theta is direct line of sight
        //  this function will return the value in radians
        min_theta=atan2((y-y_0),(x-x_0));

        //  convert to degrees
        min_theta=(180.0/PI)*min_theta;

        //  Search for minimum delta of tof x & y
        for(theta=min_theta;theta<90.0;theta+=.01)  {
            //  These functions require that theta is in degrees.
            tof_y=compute_tof_y_max(y_0,y,v,theta);  
            tof_x=compute_tof_x(x_0,x,v,theta);  

            delta=(tof_y-tof_x);
            if (delta < 0.0)delta *= -1.0;
            if(delta<min_delta)  {
                min_delta=delta;
                best_theta=theta;
                if(debug==true)
                {
                    printf("\nmin_delta = %.4lf   best_theta = %.4lf",min_delta,best_theta);
                }
            }

        }

        //  Limit tof difference to 1 second
        if(min_delta>1.0)  {
            printf("\nNo solution exists with the given parameters.");
            return(0.0);
        }
        launch_theta=best_theta;
        return(launch_theta);
    }


