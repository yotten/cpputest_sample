#include "CppUTest/TestHarness.h"

extern "C"
{
#include "LightControllerSpy.h"
}

TEST_GROUP(LightScheduler)
{
	void setup()
	{
		LightController_Create();
	}

	void teardown()
	{
		LightController_Destroy();
	}
};

TEST(LightScheduler, NoChangeToLightsDuringInitialization)
{
        LONGS_EQUAL(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastId());
        LONGS_EQUAL(LIGHT_STATE_UNKNOWN, LightControllerSpy_GetLastState());
}

#if 0
TEST(LightScheduler, ScheduleOnEverydayNotTimeYet)
{
	LightScheduler_ScheduleTurnOn(3, EVERYDAY, 1200);
	FakeTimeService_SetDay(MONDAY);
	FakeTimeService_SetMinute(1199);
	LightScheduler_Wakeup();

	LONGS_EQUAL(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastId());
	LONGS_EQUAL(LIGHT_STATE_UNKNOWN, LightControllerSpy_GetLastState());
}
#endif