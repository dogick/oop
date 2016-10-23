#pragma once
#include "stdafx.h"
#include "Const.h"

enum class Gear
{
	REVERSE = -1,
	NEUTRAL_GEAR = 0,
	FIRST_GEAR = 1,
	SECOND_GEAR = 2,
	THIRD_GEAR = 3,
	FOURTH_GEAR = 4,
	FIFTH_GEAR = 5,
};

enum class Direction
{
	STAND = 0,
	FORWARD = 1,
	BACKWARD = -1,
};

typedef std::pair<int, int> Speed;
typedef std::map<Gear, Speed> SpeedRange;
static const SpeedRange speedRange = {
	{ Gear::REVERSE, Speed(0, 20) },
	{ Gear::NEUTRAL_GEAR, Speed(MIN_SPEED, MAX_SPEED) },
	{ Gear::FIRST_GEAR, Speed(0, 30) },
	{ Gear::SECOND_GEAR, Speed(20, 50) },
	{ Gear::THIRD_GEAR, Speed(30, 60) },
	{ Gear::FOURTH_GEAR, Speed(40, 90) },
	{ Gear::FIFTH_GEAR, Speed(50, 150) },
};

class CCar
{
public:
	int GetGear() const;
	int GetSpeed() const;
	bool IsTurnOnEngine() const;

	bool TurnOnEngine();
	bool TurnOffEngine();

	bool SetGear(int gear);
	bool SetSpeed(int speed);
private:
	bool IsNeutralGear() const;
	bool IsSpeedInRange(Gear const& gear, int speed) const;
	bool CheckGear(int gear) const;
	bool m_isOn = false;
	Gear m_selectGear = Gear::NEUTRAL_GEAR;
	int m_speed = 0;
};
