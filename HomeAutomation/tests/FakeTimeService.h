
enum {
	TIME_UNKNOWN = -1
};

typedef struct {
	int minuteOfDay;
	int dayOfWeek; 	
} Time;

void TimeService_GetTime(Time *time);
