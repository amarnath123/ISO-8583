/*
 * KeyManagementData.cpp
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/KeyManagementData.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(KeyManagementData)
			string KeyManagementData::toString() const {
			string s(str());
			return s;
		}
	}
}
