/*
 * PrimaryAccountNumberExtended.cpp
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/PrimaryAccountNumberExtended.h"

namespace ISO_8583 {
	namespace DTE {
#if STD_CB2A == 150 || STD_ISO_8583 == 1987 
		SERIALIZE(PrimaryAccountNumberExtended)
			string PrimaryAccountNumberExtended::toString() const {
			string s(str());
			return s;
		}
#endif
	}
}
