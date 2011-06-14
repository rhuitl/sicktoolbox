/*!
 * \file main.cc
 * \brief Plots single and multi-pulse range values returned from
 *        the Sick LMS 5xx.
 *
 * Note: This example should work for all Sick LMS 5xx models.
 *
 * Code by Jason C. Derenick and Christopher R. Mansley.
 * Contact jasonder(at)seas(dot)upenn(dot)edu
 *
 * The Sick LIDAR Matlab/C++ Toolbox
 * Copyright (c) 2008, Jason C. Derenick and Thomas H. Miller
 * All rights reserved.
 *
 * This software is released under a BSD Open-Source License.
 * See http://sicktoolbox.sourceforge.net
 */

/* Implementation dependencies */
#include <string>
#include <vector>
#include <signal.h>
#include <iostream>
#include <math.h>
#include <sicklms5xx/SickLMS5xx.hh>
#include "gnuplot_i.hpp"

using namespace std;
using namespace SickToolbox;

bool running = true;
void sigintHandler(int signal);

int main(int argc, char * argv[]) {
  
  /* Signal handler */
  signal(SIGINT,sigintHandler);
  
  /* Define the plot */
  Gnuplot data_plot("points");
  data_plot.set_xrange(-20000, 20000);
  data_plot.set_yrange(-1000, 15000);

  string plot_label("Range");
  
  /* A vector to hold the values we are going to plot */
  vector<double> data_vector;
  vector<double> x1, x2, x3, x4, x5;
  vector<double> y1, y2, y3, y4, y5;
  
  /* Instantiate the SickLMS2xx class with the device path string. */
  SickLMS5xx sick_lms_5xx;
  
  /* Define some buffers to hold the returned measurements */
  unsigned int range_vals1[SickLMS5xx::SICK_LMS_5xx_MAX_NUM_MEASUREMENTS] = {0};
  unsigned int range_vals2[SickLMS5xx::SICK_LMS_5xx_MAX_NUM_MEASUREMENTS] = {0};
  unsigned int range_vals3[SickLMS5xx::SICK_LMS_5xx_MAX_NUM_MEASUREMENTS] = {0};
  unsigned int range_vals4[SickLMS5xx::SICK_LMS_5xx_MAX_NUM_MEASUREMENTS] = {0};
  unsigned int range_vals5[SickLMS5xx::SICK_LMS_5xx_MAX_NUM_MEASUREMENTS] = {0};
  unsigned int num_measurements = 0;

  /*
   * Initialize the Sick LMS 5xx
   */
  try {
    sick_lms_5xx.Initialize();
/*    sick_lms_5xx.SetSickScanFreqAndRes(SickLMS5xx::SICK_LMS_5xx_SCAN_FREQ_25,
                                       SickLMS5xx::SICK_LMS_5xx_SCAN_RES_17);*/
    sick_lms_5xx.SetSickScanFreqAndRes(SickLMS5xx::SICK_LMS_5xx_SCAN_FREQ_25,
                                       SickLMS5xx::SICK_LMS_5xx_SCAN_RES_25);
    sick_lms_5xx.SetSickEchoFilter(SickLMS5xx::SICK_LMS_5xx_ECHO_FILTER_ALL_ECHOES);
  }

  catch(...) {
    cerr << "Initialize failed! Are you using the correct device path?" << endl;
    return -1;
  }
  
  try {

    /*
     * Acquire measurements from Sick LMS 5xx and plot
     * them using gnuplot_i++
     */
    cout << "\tGrabbing measurements..." << endl << endl;
    for (unsigned int i = 0; /*i < 1000 &&*/ running; i++) {
      /* Reset plot and vector */
      data_plot.reset_plot();
      data_vector.clear();
      x1.clear(); x2.clear(); x3.clear(); x4.clear(); x5.clear();
      y1.clear(); y2.clear(); y3.clear(); y4.clear(); y5.clear();
      
      /* Acquire the most recent scan from the Sick */
      sick_lms_5xx.GetSickMeasurements(range_vals1, range_vals2, range_vals3, range_vals4, range_vals5,
                                       NULL, NULL, NULL, NULL, NULL, num_measurements);
      //cout << "got " << num_measurements << " measurements" << endl;
      
      /* Populate the data vector */
      for(unsigned int j = 0; j < num_measurements; j++) {
        data_vector.push_back((double)range_vals1[j]);

        double alpha_deg = sick_lms_5xx.GetSickStartAngle()
                         + j*sick_lms_5xx.SickScanResToDouble(sick_lms_5xx.GetSickScanRes());

        if(range_vals1[j]) {
          x1.push_back((double)range_vals1[j] * cos(alpha_deg / 180. * M_PI));
          y1.push_back((double)range_vals1[j] * sin(alpha_deg / 180. * M_PI));
        }
        if(range_vals2[j]) {
          x2.push_back((double)range_vals2[j] * cos(alpha_deg / 180. * M_PI));
          y2.push_back((double)range_vals2[j] * sin(alpha_deg / 180. * M_PI));
        }
        if(range_vals3[j]) {
          x3.push_back((double)range_vals3[j] * cos(alpha_deg / 180. * M_PI));
          y3.push_back((double)range_vals3[j] * sin(alpha_deg / 180. * M_PI));
        }
        if(range_vals4[j]) {
          x4.push_back((double)range_vals4[j] * cos(alpha_deg / 180. * M_PI));
          y4.push_back((double)range_vals4[j] * sin(alpha_deg / 180. * M_PI));
        }
        if(range_vals5[j]) {
          x5.push_back((double)range_vals5[j] * cos(alpha_deg / 180. * M_PI));
          y5.push_back((double)range_vals5[j] * sin(alpha_deg / 180. * M_PI));
        }
      }
      //printf("\n");
      
      /* Plot the values */
//      data_plot.plot_x(data_vector,plot_label.c_str());
      /*data_plot.plot_xy(x1,y1,plot_label.c_str());
      data_plot.plot_xy(x2,y2,plot_label.c_str());
      data_plot.plot_xy(x3,y3,plot_label.c_str());
      data_plot.plot_xy(x4,y4,plot_label.c_str());
      data_plot.plot_xy(x5,y5,plot_label.c_str());*/
      //data_plot.plot_xy2(x1,y1,x2,y2,plot_label.c_str());
      data_plot.plot_xy5(x1,y1, x2,y2, x3,y3, x4,y4, x5,y5, plot_label.c_str());

      
      /* Sleep a bit (gnuplot likes this) */
      //usleep(10000);
      
      
    }

  }

  /* Handle anything else */
  catch(...) {
    cerr << "An error occurred!"  << endl;
  }

  /*
   * Uninitialize the device
   */
  try {
    sick_lms_5xx.Uninitialize();
  }
  
  catch(...) {
    cerr << "Uninitialize failed!" << endl;
    return -1;
  }
  
  /* Success! */
  return 0;

}

void sigintHandler(int signal){  running = false;  }
