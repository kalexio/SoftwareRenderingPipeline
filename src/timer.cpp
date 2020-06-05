#include "timer.hpp"
#include <iostream>

Timer::Timer()
 : mAccumulatedTime(std::chrono::nanoseconds::zero()),
   frames(0)
{

}

Timer::~Timer()
{

}

void Timer::startRecording()
{
    mCurrentTime = mTimer.now();
}

void Timer::stopRecording()
{
    frames++;
    mPreviousTime = mCurrentTime;
    mCurrentTime = mTimer.now();
    mAccumulatedTime += mCurrentTime - mPreviousTime;
}

void Timer::getFPS()
{
    std::chrono::milliseconds oneSecond(1000);
    if (mAccumulatedTime >= oneSecond) {
        std::cout << "fps: " << frames << '\n';
        frames = 0;
        mAccumulatedTime = std::chrono::nanoseconds::zero();
    }
}

