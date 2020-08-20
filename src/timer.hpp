#pragma once

#include <chrono>

class Timer {
private:
    std::chrono::high_resolution_clock::time_point mCurrentTime;
    std::chrono::high_resolution_clock::time_point mPreviousTime;
    std::chrono::duration<double, std::milli> mAccumulatedTime;
    std::chrono::high_resolution_clock mTimer;
    unsigned int mFrames;

public:
    Timer();
    ~Timer();

    void startRecording();
    void stopRecording();
    void getFPS();
};

