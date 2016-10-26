#include "stdafx.h"
#include "Const.h"

const SpeedRange speedRange = {
	{ Gear::REVERSE, Speed(0, 20) },
	{ Gear::NEUTRAL_GEAR, Speed(MIN_SPEED, MAX_SPEED) },
	{ Gear::FIRST_GEAR, Speed(0, 30) },
	{ Gear::SECOND_GEAR, Speed(20, 50) },
	{ Gear::THIRD_GEAR, Speed(30, 60) },
	{ Gear::FOURTH_GEAR, Speed(40, 90) },
	{ Gear::FIFTH_GEAR, Speed(50, 150) }
};
