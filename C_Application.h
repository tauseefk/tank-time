#ifndef TEST_C_APPLICATION_H
#define TEST_C_APPLICATION_H

#include <list>
#include "C_Projectile.h"
#include "C_Clock.h"

class C_Application
{
public:
	
	typedef unsigned int T_PressedKey;

	C_Application(int screenWidth, int screenHeight);
	~C_Application();

	/// Tick is called on fix framerate (50fps)
	void Tick(T_PressedKey pressedKeys);

	void DrawCannon(float cannonX, float cannonY, float cannonAngle, float cannonHeight, float cannonWidth);

	static const T_PressedKey s_KeyLeft  = 0x01;
	static const T_PressedKey s_KeyUp    = 0x02;
	static const T_PressedKey s_KeyRight = 0x04;
	static const T_PressedKey s_KeyDown  = 0x08;
	static const T_PressedKey s_KeySpace = 0x10;

private:

	const int	m_ScreenWidth;
	const int	m_ScreenHeight;
	
	// Members for sample tick
	int			m_CannonX;
	int			m_CannonY;
	float		m_CannonAngle;
	float		m_RotationAngle;
	float		m_CannonHeight;
	float		m_CannonWidth;
	
	std::list<C_Projectile*> m_Projectiles;
	std::list<C_Clock*> m_Clocks;

};

#endif // #ifndef TEST_C_APPLICATION_H
