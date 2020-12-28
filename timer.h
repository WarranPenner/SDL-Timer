#include <SDL.h>

class Timer {
public:
	void start();
	void stop();
	void pause();
	void unpause();
	void restart();
	void reset();
	int getTicks();
	bool isStarted();
	bool isPaused();
private:
	Uint32 startTicks_ = 0u;
	Uint32 pausedTicks_ = 0u;
	bool started_ = false;
	bool paused_ = false;
};