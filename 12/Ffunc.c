#include "Sstruct.h"
#include <stdio.h>
Time calculateTotalTime(Time startTime, Time endTime) { Time totalTime; totalTime.hours = endTime.hours - startTime.hours; totalTime.minutes = endTime.minutes - startTime.minutes;

if (totalTime.minutes < 0) {
    totalTime.minutes += 60;
    totalTime.hours--;
}

return totalTime;
}