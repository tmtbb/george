//  Copyright (c) 2015-2015 The geo Authors. All rights reserved.
//  Created on: 2016年5月23日 Author: kerry

#ifndef VIP_OPERATOR_CODE_H__
#define VIP_OPERATOR_CODE_H__

#include "net/comm_head.h"


namespace vip_logic {

#define VIP_NEWS_REQ   george_logic::VIP_TYPE * 1000 + 1
#define VIP_NEWS_RLY   george_logic::VIP_TYPE * 1000 + 2

#define HOT_USER_REQ   george_logic::VIP_TYPE * 1000 + 3
#define HOT_USER_RLY   george_logic::VIP_TYPE * 1000 + 4

#define VIP_ARTICLE_REQ   george_logic::VIP_TYPE * 1000 + 5
#define VIP_ARTICLE_RLY   george_logic::VIP_TYPE * 1000 + 6

#define VIP_SUBCRIBE_REQ   george_logic::VIP_TYPE * 1000 + 7
#define VIP_SUBCRIBE_RLY   george_logic::VIP_TYPE * 1000 + 8

#define VIP_SETSUB_REQ   george_logic::VIP_TYPE * 1000 + 9
#define VIP_SETSUB_RLY   george_logic::VIP_TYPE * 1000 + 10

#define VIP_NEWDIGEST_REQ   george_logic::VIP_TYPE * 1000 + 11
#define VIP_NEWDIGEST_RLY   george_logic::VIP_TYPE * 1000 + 12

}
#endif
