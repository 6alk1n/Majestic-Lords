#pragma once
#include "Core.hpp"
#include <chrono>
#include <cstdint>

namespace Majestic {
	class Timer
	{
	public:
		Timer();
		~Timer();
		void Start();
		Uint64 End();
		double GetTime();
	protected:
		Uint64 m_startTicks;
		Uint64 m_endTicks;
		double m_diff;
		Uint64 m_freq;
	};
}