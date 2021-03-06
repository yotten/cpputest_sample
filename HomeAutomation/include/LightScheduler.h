#ifndef LIGHTSCHEDULER_H
#define LIGHTSCHEDULER_H

#include "TimeService.h"

typedef enum {
	NONE = -1,
	EVERYDAY = 10,
	WEEKDAY,
	WEEKEND,
	SUNDAY = 1,
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY 
} Day;

void LightScheduler_Create(void);
void LightScheduler_Destroy(void);
void LightScheduler_Wakeup(void);
void LightScheduler_ScheduleTurnOn(int id, Day day, int minute);
void LightScheduler_ScheduleTurnOff(int id, Day day, int minute);

#endif /* LIGHTSCHEDULER_H */
