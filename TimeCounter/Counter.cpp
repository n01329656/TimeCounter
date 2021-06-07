#pragma once
#include <iostream>
#include<Windows.h>
#include<profileapi.h>
namespace timer {
    class TimeCounter {
        using milliseconds = float;
        using procTicks = int64_t;
        procTicks start;
        procTicks end;
        milliseconds result;
        bool flag;
    public:
        TimeCounter() :start(0), end(0), result(0), flag(0) { }

        inline void SetCounter() {
            if (end != 0 || start != 0) { std::cerr << "Incorrect usage"; return; }
            flag = QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&start));
        }

        inline milliseconds getTime()const {
            return this->result;
        }

        void StopCounter() {
            if (start == 0) { std::cerr << "Incorrect usage"; return; }
            if (flag) { // checks if we got the correct value for the start number of clock ticks
                if (QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&end))) {
                    int64_t ticks = end - start; // clock ticks have passed since the SetCounter() call 
                    int64_t temp = 0;
                    if (QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&temp))) { // gets the current value of performance counter 
                        this->result = ((float)ticks / temp) * 1000; // calculating time; multiply by 1000 to represent in milliseconds                 
                    }
                    else {
                        std::cerr << "Failed to get the value of QueryPerformanceFrequency()\n";
                    }
                }
                else {
                    std::cerr << "Failed to get the value of QueryPerformanceCounter()\n";
                }
            }
            else {
                std::cerr << "Failed to get the value of QueryPerformanceCounter()\n";
            }
            start = 0;
            end = 0;
        }
    };
};