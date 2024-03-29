//  Copyright (c) 2015-2015 The GEORGE Authors. All rights reserved.
//  Created on: 2016年5月25日 Author: kerry

#include "vip_proto_buf.h"
#include "basic/basic_util.h"

namespace vip_logic {

namespace net_request {

void VIPNews::set_http_packet(base_logic::DictionaryValue* value) {
	bool r = false;
	int64 uid = 0;
	int64 pos = 0;
	int64 count = 10;
	std::string token;
	//base_logic::Value* tvalue;

	r = value->GetBigInteger(L"uid",&uid);
	if(r)
		set_uid(uid);

	r = value->GetString(L"token",&token);
	if (r)
		set_token(token);

	//r = value->Get(L"count",&tvalue);
	r = value->GetBigInteger(L"count", &count);
	set_count(count);

	r = value->GetBigInteger(L"pos",&pos);
	set_pos(pos*count);

}

void VIPArticle::set_http_packet(base_logic::DictionaryValue* value) {
	bool r = false;
	int64 uid = 0;
	int64 pos = 0;
	int64 count = 10;
	int64 vid = 0;
	int64 flag = 0;
	std::string token;
	//base_logic::Value* tvalue;

	r = value->GetBigInteger(L"uid",&uid);
	if(r)
		set_uid(uid);

	r = value->GetString(L"token",&token);
	if (r)
		set_token(token);


	r = value->GetBigInteger(L"vid", &vid);
	set_vid(vid);
	r = value->GetBigInteger(L"flag", &flag);
	set_flag(flag);
	//r = value->Get(L"count",&tvalue);
	r = value->GetBigInteger(L"count", &count);
	set_count(count);

	r = value->GetBigInteger(L"pos",&pos);
	set_pos(pos*count);

}

void SubcribeVIP::set_http_packet(base_logic::DictionaryValue* value) {
	bool r = false;
	int64 uid = 0;
	std::string str_uid;
	int64 pos = 0;
	int64 count = 10;
	std::string token;
	base_logic::Value* tvalue;


	r = value->GetBigInteger(L"uid",&uid);
	if(!r)
		r = value->GetString(L"uid",&str_uid);
	else
		str_uid = base::BasicUtil::StringUtil::Int64ToString(uid);
	set_uid(str_uid);

	r = value->GetString(L"token",&token);
	if (r)
		set_token(token);

	r = value->GetBigInteger(L"count", &count);
	set_count(count);

	r = value->GetBigInteger(L"pos",&pos);
	set_pos(pos*count);

}

void SetSubcribeVIP::set_http_packet(base_logic::DictionaryValue* value) {
	bool r = false;
	int64 uid = 0;
	int64 vid = 0;
	std::string token;
	std::string str_uid;


	r = value->GetBigInteger(L"uid",&uid);
	if(!r)
		r = value->GetString(L"uid",&str_uid);
	else
		str_uid = base::BasicUtil::StringUtil::Int64ToString(uid);
	set_uid(str_uid);

	r = value->GetString(L"token",&token);
	if (r)
		set_token(token);

	r = value->GetBigInteger(L"vid", &vid);
	set_vid(vid);
}

void VIPNewsDigest::set_http_packet(base_logic::DictionaryValue* value) {
	bool r = false;
	int64 uid = 0;
	int64 article_id = 0;
	std::string token;
	std::string str_uid;


	r = value->GetBigInteger(L"uid",&uid);
	if(!r)
		r = value->GetString(L"uid",&str_uid);
	else
		str_uid = base::BasicUtil::StringUtil::Int64ToString(uid);
	set_uid(str_uid);

	r = value->GetString(L"token",&token);
	if (r)
		set_token(token);

	r = value->GetBigInteger(L"aid", &article_id);
	set_article_id(article_id);
}

}
}
