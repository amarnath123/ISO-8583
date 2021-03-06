/*
 * SocketChannel.cpp
 *
 *  Created on: 4 ao�t 2015
 *      Author: FrancisANDRE
 */
#include <sstream>
#include <memory>
#include <cassert>
using namespace std;

#include "Poco/Timespan.h"
#include "Poco/ByteOrder.h"
using Poco::Timespan;
using Poco::ByteOrder;


#include "ISO-8583/MSG/SocketChannel.h"

namespace ISO_8583 {
	namespace COM {
		SocketChannel::SocketChannel(Logger* logger, const string& host, short port) :
			host(host),
			port(port),
			logger(logger),
			sa(host, port){
		}
		SocketChannel::SocketChannel(Logger* logger, StreamSocket& socket) :
			socket(socket), logger(logger) {
		}
		SocketChannel::~SocketChannel() {
		}
		void SocketChannel::connect(int timeout) {
			socket = StreamSocket(sa);
		}
		int SocketChannel::send(Buffer& cos) {
			cos.flip();
			int sended;
			nat4 length = cos.limit();
			nat4 netendian = hton(length);
			sended = socket.sendBytes(&netendian, sizeof(netendian));
			assert(sended == sizeof(netendian));
			if (logger && logger->trace()) {
				string message = string_to_hex(cos.str(length));
				logger->trace(message);
			}
			sended = socket.sendBytes(cos.data(), length);
			return sended;
		}
		int SocketChannel::recv(Buffer& cis) {
			int remain;
			int recv = socket.receiveBytes(&remain, sizeof(remain));
			if (recv <= 0) {
				return recv;
			}
			remain = ntoh(remain);
			unique_ptr<char> buffer(new char[remain]);
			int length = 0;
			while (remain > 0) {
				recv = socket.receiveBytes(buffer.get() + length, remain);
				if (recv <= 0) {
					return recv;
				}
				length += recv;
				remain -= recv;
			}
			cis.take(buffer.get(), length);
			if (logger && logger->trace()) {
				string hexa = string(buffer.get(), length);
				string message = string_to_hex(hexa);
				logger->trace(message);
			}
			buffer.release();
			return length;
		}
		void SocketChannel::disconnect(int timeout) {

		}
		void SocketChannel::setRecvTimeout(int second) {
			Timespan timeout(second, 0);
			socket.setReceiveTimeout(timeout);
		}
		void SocketChannel::setSendTimeout(int second) {
			Timespan timeout(second, 0);
			socket.setSendTimeout(timeout);
		}
	}
}
