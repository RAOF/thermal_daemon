/*
 * thd_cdev_pstates.h: thermal cooling class interface
 *
 * Copyright (C) 2012 Intel Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version
 * 2 or later as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 *
 * Author Name <Srinivas.Pandruvada@linux.intel.com>
 *
 */

#ifndef THD_CDEV_PSTATES_H_
#define THD_CDEV_PSTATES_H_

#include <string>
#include <vector>
#include "thd_cdev.h"
#include "thd_msr.h"


class cthd_cdev_pstates: public cthd_cdev
{
private:

	int cpu_start_index;
	int cpu_end_index;
	std::vector < int > cpufreqs;
	int pstate_active_freq_index;
	int turbo_state;
	cthd_msr msr;
	std::string last_governor;
	int cpu_index;

public:
	cthd_cdev_pstates(unsigned int _index, int _cpu_index): cthd_cdev(_index, 
	"/sys/devices/system/cpu/"), cpu_index(_cpu_index){}

	int init();
	void set_curr_state(int state, int arg);
	int get_max_state();
	int update();
};

#endif /* THD_CDEV_PSTATES_H_ */
