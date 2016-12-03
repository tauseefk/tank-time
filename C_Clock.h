#ifndef TEST_C_Clock_H
#define TEST_C_Clock_H

#include <string>
#include "Projectile.h"

class C_Clock
{
public:
	C_Clock(int m_ClockX, int m_ClockY, int m_ClockDefSize, int m_ClockVelocityX, int m_ClockVelocityY);
	~C_Clock();

	void Move(int m_ScreenWidth,int m_ScreenHeight);

	void DisplayClock();

	void TimeToAngle(std::string unit, int value, float &angle);

	void DisplayTime();

	void ClearPosition();

private:

	int			m_ClockDefSize;

	int			m_ClockX;
	int			m_ClockY;
	int			m_ClockVelocityX;
	int			m_ClockVelocityY;

};

#endif 