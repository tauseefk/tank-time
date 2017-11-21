#include <string>
#include <iostream>
#include "graphics.h"
#include "C_Clock.h"
#include "time.h"

static const float k_PI = 3.1415926536f;

C_Clock::C_Clock(int m_ClockX, int m_ClockY, int m_ClockDefSize, int m_ClockVelocityX, int m_ClockVelocityY)
	: m_ClockDefSize(m_ClockDefSize)
	, m_ClockX(m_ClockX)
	, m_ClockY(m_ClockY)
	, m_ClockVelocityX(m_ClockVelocityX)
	, m_ClockVelocityY(m_ClockVelocityY)
{
}

C_Clock::~C_Clock()
{
}


void C_Clock::Move(int m_ScreenWidth, int m_ScreenHeight) {

	// Preventing clock from going out of the screen area
	if (m_ClockX < 0 || m_ClockX > m_ScreenWidth - m_ClockDefSize) {
		m_ClockVelocityX = 0 - m_ClockVelocityX;
	}
	if (m_ClockY < 0 || m_ClockY > m_ScreenHeight - m_ClockDefSize) {
		m_ClockVelocityY = 0 - m_ClockVelocityY;
	}

	// Moving the clock

	m_ClockX += m_ClockVelocityX;
	m_ClockY += m_ClockVelocityY;
}

void C_Clock::DisplayClock() {
	DrawLine(m_ClockX, m_ClockY, m_ClockX + m_ClockDefSize, m_ClockY, GetRGB(255, 0, 0));
	DrawLine(m_ClockX, m_ClockY, m_ClockX, m_ClockY + m_ClockDefSize, GetRGB(255, 0, 0));
	DrawLine(m_ClockX, m_ClockY + m_ClockDefSize, m_ClockX + m_ClockDefSize, m_ClockY + m_ClockDefSize, GetRGB(255, 0, 0));
	DrawLine(m_ClockX + m_ClockDefSize, m_ClockY, m_ClockX + m_ClockDefSize, m_ClockY + m_ClockDefSize, GetRGB(255, 0, 0));
}

void C_Clock::TimeToAngle(const char* unit, int value, float &angle) {
	if (unit == "h") {
		angle = (value % 12) * 30 * k_PI / 180;
		std::cout << angle;
	}
	else {
		angle = value * 6 * k_PI / 180;
	}
}

void C_Clock::DisplayTime() {

	int hr = 0,
		min = 0,
		sec = 0;
	float angleSubHr = 0,
		angleSubMin = 0,
		angleSubSec = 0;

	GetTime(hr, min, sec);
	
	int clockCenterX = m_ClockX + m_ClockDefSize / 2,
		clockCenterY = m_ClockY + m_ClockDefSize / 2;
	
	TimeToAngle("h", hr, angleSubHr);
	TimeToAngle("m", min, angleSubMin);
	TimeToAngle("s", sec, angleSubSec);

	// Draw clock hands
	DrawLine(clockCenterX, clockCenterY, clockCenterX + 30 * sin(angleSubHr), clockCenterY - 30 * cos(angleSubHr), GetRGB(255, 0, 0));
	DrawLine(clockCenterX, clockCenterY, clockCenterX + 48 * sin(angleSubMin), clockCenterY - 48 * cos(angleSubMin), GetRGB(255, 255, 0));
	DrawLine(clockCenterX, clockCenterY, clockCenterX + 40 * sin(angleSubSec), clockCenterY - 40 * cos(angleSubSec), GetRGB(255, 0, 255));
}

void C_Clock::ClearPosition() {
	// Clear screen on clock positions

	FillRect(m_ClockX - 2, m_ClockY - 2, m_ClockDefSize + 5, m_ClockDefSize + 5, GetRGB(0, 0, 0));
}

void C_Clock::ChangeDirection(char axis) {
	if (axis == 'x') {
		m_ClockVelocityX = 0 - m_ClockVelocityX;
	}
	else if (axis == 'y') {
		m_ClockVelocityY = 0 - m_ClockVelocityY;
	}
}

float C_Clock::GetClockCenter(char axis) {
	if (axis == 'x') {
		return this->m_ClockX + m_ClockDefSize / 2;
	}
	else if (axis == 'y') {
		return this->m_ClockY + m_ClockDefSize / 2;
	}
}

float C_Clock::GetClockSize() {
	return this->m_ClockDefSize;
}