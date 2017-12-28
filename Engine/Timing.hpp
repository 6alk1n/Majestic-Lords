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
		UINT64 End();
		double GetTime();
	protected:
		UINT64 m_startTicks;
		UINT64 m_endTicks;
		double m_diff;
		UINT64 m_freq;
	};
}