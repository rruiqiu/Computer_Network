
/*
 * 
 * Simulation of A Single Server Queueing System
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

/******************************************************************************/

#ifndef _SIMPARAMETERS_H_
#define _SIMPARAMETERS_H_

/******************************************************************************/

#define PACKET_ARRIVAL_RATE 1 /* packets per second */
#define PACKET_LENGTH 1e3 /* bits */
#define LINK_BIT_RATE 2e6 /* bits per second */
#define RUNLENGTH 10e6 /* packets */

/* Comma separated list of random seeds to run. */
#define RANDOM_SEED_LIST 333333, 444444, 555555,666666,777777, 888888, 1000000, 2000000,3000000 ,400318681

#define PACKET_XMT_TIME ((double) PACKET_LENGTH/LINK_BIT_RATE)
#define BLIPRATE (RUNLENGTH/1000)

//switch1
#define PACKET_ARRIVAL_RATE_1 750 /* packets per second */
#define PACKET_LENGTH_1 1e3 /* bits */
#define LINK_BIT_RATE_1 2e6 /* bits per second */
#define RUNLENGTH_1 10e6 /* packets */

/* Comma separated list of random seeds to run. */
#define RANDOM_SEED_LIST 333333, 444444, 555555,666666,777777, 888888, 1000000, 2000000,3000000 ,400318681

#define PACKET_XMT_TIME_1 ((double) PACKET_LENGTH_1/LINK_BIT_RATE_1)
#define BLIPRATE_1 (RUNLENGTH/1000)

//switch2
#define PACKET_ARRIVAL_RATE_2 750 /* packets per second */
#define PACKET_LENGTH_2 1e3 /* bits */
#define LINK_BIT_RATE_2 2e6 /* bits per second */
#define RUNLENGTH_2 10e6 /* packets */

/* Comma separated list of random seeds to run. */
#define RANDOM_SEED_LIST 333333, 444444, 555555,666666,777777, 888888, 1000000, 2000000,3000000 ,400318681

#define PACKET_XMT_TIME_2 ((double) PACKET_LENGTH_1/LINK_BIT_RATE_1)
#define BLIPRATE_2 (RUNLENGTH/1000)

//switch3
#define PACKET_ARRIVAL_RATE_3 750 /* packets per second */
#define PACKET_LENGTH_3 1e3 /* bits */
#define LINK_BIT_RATE_3 2e6 /* bits per second */
#define RUNLENGTH_3 10e6 /* packets */

/* Comma separated list of random seeds to run. */
#define RANDOM_SEED_LIST 333333, 444444, 555555,666666,777777, 888888, 1000000, 2000000,3000000 ,400318681

#define PACKET_XMT_TIME_3 ((double) PACKET_LENGTH_1/LINK_BIT_RATE_1)
#define BLIPRATE_3 (RUNLENGTH/1000)

/******************************************************************************/

#endif /* simparameters.h */



