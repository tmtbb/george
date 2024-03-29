//  Copyright (c) 2015-2015 The george Authors. All rights reserved.
//  Created on: 2016年5月18日 Author: kerry

#ifndef GEORGE_VIP_USER_MGR_H__
#define GEORGE_VIP_USER_MGR_H__

#include "vip_db.h"
#include "vip_basic_info.h"
#include "storage/data_engine.h"
#include "basic/basictypes.h"
#include "thread/base_thread_lock.h"
#include "vip_basic_info.h"
#include <map>

typedef std::map<int64,vip_logic::VIPUserInfo> VIPUSERINFO_MAP; //vid - vipuserinfo
typedef std::vector<vip_logic::VIPUserInfo>    VIPUSERINFO_VEC; //vid - vipuserinfo

namespace vip_logic {

class VIPUserCache {
public:
	VIPUSERINFO_MAP  vip_user_info_;
	VIPUSERINFO_VEC  vip_user_vec_;

};

class VIPUserManager {
 public:
	VIPUserManager();
	virtual ~VIPUserManager();
 private:
	void Init();
 public:
	void Init(vip_logic::VIPDB* vip_db);
 public:
	bool GetVIPUserInfo(const int64 vid,vip_logic::VIPUserInfo& vip);
	bool GetVIPUserInfo(const int64* uid,const int32 n,
			std::map<int64, vip_logic::VIPUserInfo> & map);

	bool GetHotVIPUser(std::list<vip_logic::VIPUserInfo>& list,const int32 pos,
				const int32 count);
 private:
	struct threadrw_t*                 lock_;
	VIPUserCache*                      vip_user_cache_;
	vip_logic::VIPDB*                  vip_db_;
};

class VIPUserEngine {
 private:
	static VIPUserManager*    vip_user_mgr_;
	static VIPUserEngine*     vip_user_engine_;
	VIPUserEngine() {}
	virtual ~VIPUserEngine() {}
 public:
	static VIPUserManager* GetVIPUserManager() {
		if (vip_user_mgr_ == NULL)
			vip_user_mgr_ = new VIPUserManager();
		return vip_user_mgr_;
	}

	static VIPUserEngine* GetVIPUserEngine() {
		if (vip_user_engine_ == NULL)
			vip_user_engine_ = new VIPUserEngine();
		return vip_user_engine_;
	}

	static void FreeVIPUserEngine() {
		delete vip_user_engine_;
	}

	static void FreeVIPUserManager() {
		delete vip_user_mgr_;
	}

};

}

#endif
