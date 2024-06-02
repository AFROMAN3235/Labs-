#include <stdio.h>
#include "SSstruct.h"
int main() { const int daysInWeek = 7; Time totalTime = {0, 0};

Time startTime = {8, 0}; // начало работы прибора
Time endTime = {16, 30}; // конец работы прибора

for (int day = 1; day <= daysInWeek; day++) {
    printf("День %d:\n", day);
    Time dayTotalTime = calculateTotalTime(startTime, endTime);
    
    printf("Общее время работы: %d ч. %d мин.\n\n", dayTotalTime.hours, dayTotalTime.minutes);
    
    totalTime.hours += dayTotalTime.hours;
    totalTime.minutes += dayTotalTime.minutes;
    
    if (totalTime.minutes >= 60) {
        totalTime.minutes -= 60;
        totalTime.hours++;
    }
}

printf("Общее время работы прибора за неделю: %d ч. %d мин.\n", totalTime.hours, totalTime.minutes);

return 0;
}