#include "timer.h"

void Timer::start() {
	started_ = true;
	paused_ = false;
	startTicks_ = SDL_GetTicks();
}

void Timer::stop() {
	started_ = false;
	paused_ = false;
}

void Timer::pause() {
	if (started_ == true && paused_ == false) {
		paused_ = true;
		pausedTicks_ = SDL_GetTicks() - startTicks_;
	}
}

void Timer::unpause() {
	if (paused_) {
		paused_ = false;
		startTicks_ = SDL_GetTicks() - pausedTicks_;
		pausedTicks_ = 0u;
	}
}

void Timer::restart() {
	started_ = true;
	paused_ = false;
	pausedTicks_ = 0u;
	startTicks_ = SDL_GetTicks();
}

void Timer::reset() {
	startTicks_ = 0u;
	pausedTicks_ = 0u;
	started_ = false;
	paused_ = false;
}

int Timer::getTicks() {
	if (!started_) {
		return 0u;
	} else if (paused_) {
		return pausedTicks_;
	} else {
		return SDL_GetTicks() - startTicks_;
	}
}

bool Timer::isStarted() {
	return started_;
}

bool Timer::isPaused() {
	return paused_;
}