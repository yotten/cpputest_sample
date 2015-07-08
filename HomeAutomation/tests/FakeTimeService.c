#include "FakeTimeService.h"

static Time fakeTime;

void TimeService_Create(void)
{
	fakeTime.minuteOfDay = TIME_UNKNOWN;
	fakeTime.dayOfWeek = TIME_UNKNOWN;	
}

void TimeService_Destroy(void)
{
}
 
void TimeService_GetTime(Time *time)
{
	time->minuteOfDay = fakeTime.minuteOfDay;
	time->dayOfWeek = fakeTime.dayOfWeek;
}

void FakeTimeService_SetMinute(int miniute)
{
	fakeTime.minuteOfDay = miniute;
}

void FakeTimeService_SetDay(int day)
{
	fakeTime.dayOfWeek = day;
}

