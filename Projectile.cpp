#include <math.h>
#include "graphics.h"
#include "Projectile.h"

static const float k_PI = 3.1415926536f;

Projectile::Projectile(float m_ProjectileX, float m_ProjectileY, int screenWidth, int screenHeight, float m_ProjectileSpeed, float m_ProjectileAngle)
	: m_ProjectileX(m_ProjectileX)
	, m_ProjectileY(m_ProjectileY)
	, m_ProjectileSpeed(m_ProjectileSpeed)
	, m_ProjectileAngle(m_ProjectileAngle)
	, m_ScreenWidth(screenWidth)
	, m_ScreenHeight(screenHeight)
{
}

Projectile::~Projectile()
{
}

void Projectile::Move() {
	FillRect(m_ProjectileX - 1, m_ProjectileY - 1, 5, 5, GetRGB(0, 0, 0));
	m_ProjectileX += m_ProjectileSpeed * sin(m_ProjectileAngle);
	m_ProjectileY += m_ProjectileSpeed * cos(m_ProjectileAngle);
	DrawLine(m_ProjectileX, m_ProjectileY, m_ProjectileX + 2 * sin(m_ProjectileAngle), m_ProjectileY + 2 * cos(m_ProjectileAngle), GetRGB(255, 255, 255));
}