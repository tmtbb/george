//  Copyright (c) 2015-2015 The geprge Authors. All rights reserved.
//  Created on: 2016年5月18日 Author: kerry

#include "vip_db.h"
#include "vip_basic_info.h"
#include <mysql.h>
namespace vip_logic {

VIPDB::VIPDB(config::FileConfig* config) {
	mysql_engine_ = base_logic::DataEngine::Create(MYSQL_TYPE);
	mysql_engine_->InitParam(config->mysql_db_list_);
}

VIPDB::~VIPDB() {
	if(mysql_engine_){
		delete mysql_engine_;
		mysql_engine_ = NULL;
	}
}

bool VIPDB::FectchVIPUserInfo() {
	bool r = false;
	std::string sql = "call proc_FectchVIPUser()";
    scoped_ptr<base_logic::DictionaryValue> dict(
                new base_logic::DictionaryValue());
    base_logic::ListValue* listvalue;
    dict->SetString(L"sql", sql);
    r = mysql_engine_->ReadData(0, (base_logic::Value*)(dict.get()),
    		CallFectchVIPUserInfo);
    if (!r)
    	return false;
    dict->GetList(L"resultvalue", &listvalue);
    while (listvalue->GetSize()) {
    	vip_logic::VIPUserInfo user;
    	base_logic::Value* result_value;
    	listvalue->Remove(0, &result_value);
        base_logic::DictionaryValue* dict_result_value =
                (base_logic::DictionaryValue*)(result_value);
        user.ValueSerialization(dict_result_value);
        //list->push_back(task);
        delete dict_result_value;
        dict_result_value = NULL;
    }
    return true;
}

void VIPDB::CallFectchVIPUserInfo(void* param,
            base_logic::Value* value) {
    base_logic::DictionaryValue* dict =
            (base_logic::DictionaryValue*)(value);
    base_logic::ListValue* list = new base_logic::ListValue();
    base_storage::DBStorageEngine* engine =
            (base_storage::DBStorageEngine*)(param);
    MYSQL_ROW rows;
    int32 num = engine->RecordCount();
    if (num > 0) {
        while (rows = (*(MYSQL_ROW*)(engine->FetchRows())->proc)) {
            base_logic::DictionaryValue* info_value =
                    new base_logic::DictionaryValue();
            if (rows[0] != NULL)
                info_value->SetBigInteger(L"id", atoll(rows[0]));
            if (rows[1] != NULL)
                info_value->SetBigInteger(L"followers_count", atoll(rows[1]));
            if (rows[2] != NULL)
                info_value->SetCharInteger(L"official_vip", atoll(rows[2]));
            if (rows[3] != NULL)
                info_value->SetString(L"name",rows[3]);
            if (rows[4] != NULL)
            	info_value->SetString(L"introduction",rows[4]);
            if (rows[5] != NULL)
                info_value->SetString(L"home_page",rows[5]);
            if (rows[6] != NULL)
                info_value->SetString(L"portrait",rows[6]);
            list->Append((base_logic::Value*)(info_value));
        }
    }
    dict->Set(L"resultvalue", (base_logic::Value*)(list));
}
}