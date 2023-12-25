/*
 *This file includes all others for simple library integration.  Better
 *form would be just to include what you need.  Essentials are:
 *CANPacket.h, port.h, CANCommon.h
 *You will also need any utility files required by your board, i.e.
 *CANMotorUnit.h or CANLocalization.
 */

#pragma once

//Essentials
#include "CANPacket.h"
#include "CANCommon.h"
#include "Port.h"

//Board specifics
#include "CANGPIO.h"
#include "CANLocalization.h"
#include "CANMotorUnit.h"
#include "CANPower.h"
#include "CANSerialNumbers.h"