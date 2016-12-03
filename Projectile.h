#ifndef C_PROJECTILE_H
#define C_PROJECTILE_H

#include "graphics.h"

class Projectile
{
public:
	Projectile(float m_ProjectileX, float m_ProjectileY, int screenWidth, int screenHeight, float m_ProjectileSpeed, float m_ProjectileAngle);
	~Projectile();

	void Move();

	int			m_ScreenWidth,
				m_ScreenHeight;
	
	float		m_ProjectileSpeed,
				m_ProjectileX,
				m_ProjectileY, 
				m_ProjectileAngle;
};
#endif