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
	int minuteOfDay;
	int event;
} ScheduledLightEvent;

static ScheduledLightEvent scheduledEvent;

static void operateLight(ScheduledLightEvent *lightEvent)
{
	if (lightEvent->event == TURN_ON) {
		LightController_On(scheduledEvent.id);
	} else {
		LightController_Off(scheduledEvent.id);
	}
}

static void proccessEventDueNow(Time *time, ScheduledLightEvent *lightEvent)
{
	if (lightEvent->id == UNUSED) {
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
	if (scheduledEvent.id == UNUSED) {
		return;
	}
}

void LightScheduler_ScheduleTurnOn(int id, Day day, int minute)
{
	scheduledEvent.id = id;
	scheduledEvent.minuteOfDay = minute;
	scheduledEvent.event = TURN_ON;
}

void LightScheduler_ScheduleTurnOff(int id, Day day, int minute)
{
	scheduledEvent.id = id;
	scheduledEvent.minuteOfDay = minute;
	scheduledEvent.event = TURN_OFF;
}

