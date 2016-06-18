//  Copyright (c) 2015-2015 The mem_manager.h Authors. All rights reserved.
//  Created on: 2016年1月9日 Author: paco

#ifndef _HOME_TIANYIHENG_TEST_JINDOWIN_RUNNER_JINDOWIN_PLUGINS_NEWS_MEM_MANAGER_H_
#define _HOME_TIANYIHENG_TEST_JINDOWIN_RUNNER_JINDOWIN_PLUGINS_NEWS_MEM_MANAGER_H_

#include <pthread.h>
#include <string>
#include <map>

#include "../news/news_base.h"

class MemManager {
 private:
  MemManager();
  ~MemManager();

 public:
  static MemManager* GetInstance();

  void InitHyMap();
  void InitGnMap();
  void InitStockNameMap();
  std::string GetHyByCode(std::string code);
  std::string GetGnByCode(std::string code);
  std::string GetStockNameByCode(std::string code);
  std::string GetUserSubscribe(int user_id, int get_type);

 private:
  StringMap hy_stock_map_;
  StringMap gn_stock_map_;
  StringMap news_map_;
  StringMap hy_news_map_;
  StringMap stock_name_map_;

 private:
  static pthread_mutex_t lock_;
  static MemManager* instance_;
};

#endif  // _HOME_TIANYIHENG_TEST_JINDOWIN_RUNNER_JINDOWIN_PLUGINS_NEWS_MEM_MANAGER_H_
