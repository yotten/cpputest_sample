#include "CppUTest/TestHarness.h"

extern "C"
{
#include "FakeTimeService.h"
}

TEST_GROUP(FakeTimeService)
{
	void setup()
	{
//		LightController_Create();
	}

	void teardown()
	{
//		LightController_Destroy();
	}
};

TEST(FakeTimeService, Create)
{
	Time time;
	TimeService_GetTime(&time);
	LONGS_EQUAL(TIME_UNKNOWN, time.minuteOfDay);	
	LONGS_EQUAL(TIME_UNKNOWN, time.dayOfWeek);
}
