#include <string>
#include <list>
#include "graphics.h"
#include "time.h"
#include "C_Projectile.h"
#include "C_Clock.h"
#include "C_Application.h"

static const float k_PI = 3.1415926536f;

C_Application::C_Application(int screenWidth, int screenHeight)
	: m_ScreenWidth(screenWidth)
	, m_ScreenHeight(screenHeight)
	, m_CannonX(m_ScreenWidth/2)
	, m_CannonY(m_ScreenHeight* 5/6)
	, m_CannonAngle(k_PI)
	, m_CannonHeight(30)
	, m_CannonWidth(20)
	, m_RotationAngle(0.07) // radians
{
}


C_Application::~C_Application()
{

}

//void C_Application::GetRotatedPoints()

void C_Application::Tick(T_PressedKey pressedKeys)
{
	// Sample tick

	// Clear screen on cannon position
	FillRect(m_CannonX - m_CannonHeight, m_CannonY - 1, 2 * m_CannonHeight + 1, 2 * m_CannonWidth + 2, GetRGB(0, 0, 0));

	// Key processing
	if(pressedKeys & s_KeyLeft)
	{
		m_CannonAngle = min((3 * k_PI) / 2, m_CannonAngle + m_RotationAngle); // 2 * k_PI radians make a circle
	}

	if(pressedKeys & s_KeyRight)
	{
		m_CannonAngle = max(k_PI / 2, m_CannonAngle - m_RotationAngle); // k_PI / 2 radians make 90 degrees
	}

	if(pressedKeys & s_KeySpace)
	{
		m_Projectiles.push_back(new C_Projectile(
			m_CannonX - m_CannonHeight * sin(k_PI + m_CannonAngle),
			m_CannonY + m_CannonHeight - m_CannonHeight * cos(k_PI + m_CannonAngle),
			m_ScreenWidth, m_ScreenHeight, 5, m_CannonAngle
		));
	}

	std::list<C_Projectile*> tempProjectiles;
	for each (C_Projectile* p in m_Projectiles)
	{
		// Checking if projectile is on the screen space
		if (p->m_ProjectileX > 0 && p->m_ProjectileY > 0 && p->m_ProjectileX < m_ScreenWidth && p->m_ProjectileY < m_ScreenHeight) {
			p->Move();
			tempProjectiles.push_back(p);
		}
		else {
			delete(p);
		}
	}
	m_Projectiles = tempProjectiles;

	float clockSize = 100,
		clockVelocityX = 2,
		clockVelocityY = 2;

	if (m_Clocks.size() == 2) {
		m_Clocks.push_back(new C_Clock(m_ScreenWidth / 2, m_ScreenHeight / 2,
			clockSize, clockVelocityX, clockVelocityY));

		m_Clocks.push_back(new C_Clock((m_ScreenWidth / 2) - clockSize,
			m_ScreenHeight / 2, clockSize, clockVelocityX, clockVelocityY));
	}

	std::list<C_Clock*> tempClocks;
	tempClocks = m_Clocks;
	for each(C_Clock* c in m_Clocks) {
		for each(C_Clock* other in tempClocks) {
			if (c->GetClockCenter('x') != other->GetClockCenter('x') && c->GetClockCenter('y') != other->GetClockCenter('y')) {
				if (c->GetClockCenter('x') != other->GetClockCenter('x')) {

				}
			}
		}
		c->ClearPosition();
		c->DisplayClock();
		c->DisplayTime();
		c->Move(m_ScreenWidth, m_ScreenHeight);
	}



	// Draw cannon
	DrawCannon(m_CannonX, m_CannonY, m_CannonAngle, m_CannonHeight, m_CannonWidth);
}

void C_Application::DrawCannon(float cannonX, float cannonY, float cannonAngle, float cannonHeight, float cannonWidth) {

	DrawLine(cannonX - (cannonWidth / 2) * cos(k_PI + cannonAngle),
		cannonY + cannonHeight + (cannonWidth / 2) * sin(k_PI + cannonAngle),
		cannonX - cannonHeight * sin(k_PI + cannonAngle),
		cannonY + cannonHeight - cannonHeight * cos(k_PI + cannonAngle),
		GetRGB(255, 255, 255));

	DrawLine(cannonX + (cannonWidth / 2) * cos(k_PI + cannonAngle),
		cannonY + cannonHeight - (cannonWidth / 2) * sin(k_PI + cannonAngle),
		cannonX - cannonHeight * sin(k_PI + cannonAngle),
		cannonY + cannonHeight - cannonHeight * cos(k_PI + cannonAngle),
		GetRGB(255, 255, 255));

	DrawLine(cannonX - (cannonWidth / 2) * cos(k_PI + cannonAngle),
		cannonY + cannonHeight + (cannonWidth / 2) * sin(k_PI + cannonAngle),
		cannonX + (cannonWidth / 2) * cos(k_PI + cannonAngle),
		cannonY + cannonHeight - (cannonWidth / 2) * sin(k_PI + cannonAngle),
		GetRGB(255, 255, 255));
}
