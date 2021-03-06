/*
 * DefaultAuthorizationNotificationAcknowledge.h
 *
 *  Created on: 10 ao�t 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTAUTHORIZATIONNOTIFICATIONACKNOWLEDGE_H_
#define DEFAULTAUTHORIZATIONNOTIFICATIONACKNOWLEDGE_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/AuthorizationNotificationAcknowledge.h"

namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_RESPONSE(CB2A, Authorization, Notification, Acknowledge)
	}
}

#endif
