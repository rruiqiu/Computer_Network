
/*
 * 
 * Simulation_Run of A Single Server Queueing System
 * 
 * Copyright (C) 2014 Terence D. Todd Hamilton, Ontario, CANADA,
 * todd@mcmaster.ca
 * 
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 3 of the License, or (at your option)
 * any later version.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 * 
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

/*******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "output.h"
#include "simparameters.h"
#include "packet_arrival.h"
#include "cleanup_memory.h"
#include "trace.h"
#include "main.h"

/******************************************************************************/

/*
 * main.c declares and creates a new simulation_run with parameters defined in
 * simparameters.h. The code creates a fifo queue and server for the single
 * server queueuing system. It then loops through the list of random number
 * generator seeds defined in simparameters.h, doing a separate simulation_run
 * run for each. To start a run, it schedules the first packet arrival
 * event. When each run is finished, output is printed on the terminal.
 */

int
main(void)
{
  Simulation_Run_Ptr simulation_run;
  Simulation_Run_Data data;
  FILE *fptr;
  /*
   * Declare and initialize our random number generator seeds defined in
   * simparameters.h
   */
  fptr = fopen("output.txt", "w");

  unsigned RANDOM_SEEDS[] = {RANDOM_SEED_LIST, 0};
  unsigned random_seed;
  int j=0;

  /* 
   * Loop for each random number generator seed, doing a separate
   * simulation_run run for each.
   */

  while ((random_seed = RANDOM_SEEDS[j++]) != 0) {
    for(data.pb = 0;data.pb <1;data.pb+= 0.01){
      simulation_run = simulation_run_new(); /* Create a new simulation run. */

      /*
      * Set the simulation_run data pointer to our data object.
      */

      simulation_run_attach_data(simulation_run, (void *) & data);

      /* 
      * Initialize the simulation_run data variables, declared in main.h.
      */
      
      data.blip_counter = 0;
      data.arrival_count = 0;
      data.number_of_packets_processed = 0;
      data.accumulated_delay = 0.0;
      data.random_seed = random_seed;
      data.arrival_rate = 750;
      data.arrival_rate2 = 500;
      data.bit_rate = 2e6;
      data.bit_rate2 = 1e6;
      //initilazie the second
      data.buffer2 = fifoqueue_new();
      data.link2 = server_new();
      data.arrival_count2 = 0;
      data.number_of_packets_processed2 = 0;
      data.accumulated_delay2 = 0.0;


      data.buffer3 = fifoqueue_new();
      data.link3 = server_new();
      data.arrival_count3 = 0;
      data.number_of_packets_processed3 = 0;
      data.accumulated_delay3 = 0.0;
      // data.pb = 0.5;
      /* 
      * Create the packet buffer and transmission link, declared in main.h.
      */

      data.buffer = fifoqueue_new();
      data.link   = server_new();

      /* 
      * Set the random number generator seed for this run.
      */

      random_generator_initialize(random_seed);

      /* 
      * Schedule the initial packet arrival for the current clock time (= 0).
      */

      schedule_packet_arrival_event(simulation_run, 
            simulation_run_get_time(simulation_run));

      schedule_packet_arrival_event2(simulation_run,
          simulation_run_get_time(simulation_run));

      schedule_packet_arrival_event3(simulation_run,
          simulation_run_get_time(simulation_run));



      /* 
      * Execute events until we are finished. 
      */

      while (!(data.number_of_packets_processed2 >= RUNLENGTH) && !(data.number_of_packets_processed3 >= RUNLENGTH)) {
        simulation_run_execute_event(simulation_run);
      }

      /*
      * Output results and clean up after ourselves.
      */

      output_results(simulation_run,fptr);
      cleanup_memory(simulation_run);
    }
  }
  fclose(fptr);

  //getchar();   /* Pause before finishing. */
  return 0;
}












