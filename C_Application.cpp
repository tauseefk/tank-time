#include <string>
#include <list>
#include "graphics.h"
#include "time.h"
#include "Projectile.h"
#include "C_Application.h"

static const float k_PI = 3.1415926536f;

C_Application::C_Application(int screenWidth, int screenHeight)
	: m_ScreenWidth(screenWidth)
	, m_ScreenHeight(screenHeight)
	, m_CannonX(m_ScreenWidth/2)
	, m_CannonY(m_ScreenHeight* 5/6)
	, m_CannonAngle(k_PI)
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

	FillRect(m_CannonX - 30, m_CannonY - 1, 61, 42, GetRGB(0, 0, 0));

	// Key processing

	if(pressedKeys & s_KeyLeft)
	{
		m_CannonAngle = min((3 * k_PI) / 2, m_CannonAngle + 0.07);
	}

	if(pressedKeys & s_KeyRight)
	{
		m_CannonAngle = max(k_PI/2, m_CannonAngle - 0.07);
	}

	if(pressedKeys & s_KeySpace)
	{
		m_Projectiles.push_back(new Projectile(
			m_CannonX - 30 * sin(k_PI + m_CannonAngle),
			m_CannonY + 30 - 30 * cos(k_PI + m_CannonAngle),
			m_ScreenWidth, m_ScreenHeight, 5, m_CannonAngle
		));
	}

	std::list<Projectile*> tempProjectiles;
	for each (Projectile* p in m_Projectiles)
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

	// Draw cannon
	DrawLine(m_CannonX - 10 * cos(k_PI + m_CannonAngle),
		m_CannonY + 30 + 10 * sin(k_PI + m_CannonAngle),
		m_CannonX - 30 * sin(k_PI + m_CannonAngle),
		m_CannonY + 30 - 30 * cos(k_PI + m_CannonAngle),
		GetRGB(255, 255, 255));

	DrawLine(m_CannonX + 10 * cos(k_PI + m_CannonAngle),
		m_CannonY + 30 - 10 * sin(k_PI + m_CannonAngle),
		m_CannonX - 30 * sin(k_PI + m_CannonAngle),
		m_CannonY + 30 - 30 * cos(k_PI + m_CannonAngle),
		GetRGB(255, 255, 255));

	DrawLine(m_CannonX - 10 * cos(k_PI + m_CannonAngle),
		m_CannonY + 30 + 10 * sin(k_PI + m_CannonAngle),
		m_CannonX + 10 * cos(k_PI + m_CannonAngle),
		m_CannonY + 30 - 10 * sin(k_PI + m_CannonAngle),
		GetRGB(255, 255, 255));
}
