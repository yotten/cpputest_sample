#ifndef FAKETIMESERVICE_H
#define FAKETIMESERVICE_H

#include "TimeService.h"

enum {
	TIME_UNKNOWN = -1
};

void TimeService_GetTime(Time *time);
void FakeTimeService_SetMinute(int miniute);
void FakeTimeService_SetDay(int);
#endif /* FAKETIMESERVICE_H */

