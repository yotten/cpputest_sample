#ifndef TIMESERVICE_H
#define TIMESERVICE_H

typedef struct Time
{
    int minuteOfDay;
    int dayOfWeek;
} Time;

void TimeService_Create(void);
void TimeService_Destroy(void);

#endif /* TIMESERVICE_H */
