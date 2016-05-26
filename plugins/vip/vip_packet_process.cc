//  Copyright (c) 2015-2015 The KID Authors. All rights reserved.
//  Created on: 2016年5月23日 Author: kerry
#include "vip_packet_process.h"
#include "operator_code.h"
#include "vip_factory.h"
namespace vip_logic {

namespace http_packet {

PacketProcess::PacketProcess(){
}


void PacketProcess::PacketPocessGet(const int socket,base_logic::DictionaryValue* dict,
			george_logic::PacketHead* packet) {
	int16 operate_code = packet->operate_code();
	vip_logic::VIPFactory*  factory  =
			vip_logic::VIPFactory::GetInstance();

	switch (operate_code) {
	 case VIP_NEWS_REQ: {
		factory->OnVIPNewsEvent(socket, dict);
		break;
	 }
	 default:
		break;
	}
}

}


}