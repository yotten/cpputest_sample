#include "LightScheduler.h"
#include "TimeService.h"
#include "LightController.h"

enum {
	UNUSED = -1
};

enum {
	TURN_OFF,
	TURN_ON
};

typedef struct {
	int id;
	Day day;
	int minuteOfDay;
	int event;
} ScheduledLightEvent;

static ScheduledLightEvent scheduledEvent;

static void scheduleEvent(int id, Day day, int minuteOfDay, int event)
{
	scheduledEvent.id = id;
	scheduledEvent.day = day;
	scheduledEvent.minuteOfDay = minuteOfDay;
	scheduledEvent.event = event;
}

static void operateLight(ScheduledLightEvent *lightEvent)
{
	if (lightEvent->event == TURN_ON) {
		LightController_On(scheduledEvent.id);
	} else {
		LightController_Off(scheduledEvent.id);
	}
}
#include <stdio.h>
static void proccessEventDueNow(Time *time, ScheduledLightEvent *lightEvent)
{
	int reactionDay = lightEvent->day;
	int today = time->dayOfWeek;

	if (lightEvent->id == UNUSED) {
		return;
	}

	if (reactionDay == WEEKEND && (today != SATURDAY && today != SUNDAY)) {
		return;
	}

	if (reactionDay != WEEKEND && reactionDay != EVERYDAY && reactionDay != today) {
		return;
	}

	if (time->minuteOfDay != lightEvent->minuteOfDay) {
		return;
	}

	operateLight(lightEvent);
}

void LightScheduler_Create(void)
{
	/* LightController_Create(); */
	scheduledEvent.id = UNUSED;
}

void LightScheduler_Destroy(void)
{
}

void LightScheduler_Wakeup(void)
{
	Time time;


	TimeService_GetTime(&time);

	proccessEventDueNow(&time, &scheduledEvent);
}

void LightScheduler_ScheduleTurnOn(int id, Day day, int minute)
{
	scheduleEvent(id, day, minute, TURN_ON);
}

void LightScheduler_ScheduleTurnOff(int id, Day day, int minute)
{
	scheduleEvent(id, day, minute, TURN_OFF);
}

