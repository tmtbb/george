//  Copyright (c) 2016-2016 The jindowin Authors. All rights reserved.
//  Created on: 2016/3/28 Author: jiaoyongqing

#include <signal.h>
#include "search/search_init.h"
#include "search/search_logic.h"
#include "core/common.h"
#include "core/plugins.h"
#include "logic/logic_comm.h"
#include "pub/net/comm_struct.h"

static void *OnSearchStart() {
  signal(SIGPIPE, SIG_IGN);
  PluginInfo* search = (PluginInfo*)calloc(1, sizeof(PluginInfo));

  search->id = "search";

  search->name = "search";

  search->version = "1.0.0";

  search->provider = "paco";

  return search;
}

static handler_t OnSearchShutdown(struct server* srv, void* pd) {
  return HANDLER_GO_ON;
}

static handler_t OnSearchConnect(struct server *srv, \
                                            int fd, \
                                        void *data, \
                                           int len) {
  search::SearchLogic::GetInstance()->OnSearchConnect(srv, fd);

  return HANDLER_GO_ON;
}

static handler_t OnSearchMessage(struct server *srv, \
                                            int fd, \
                                        void *data, \
                                           int len) {
  bool r = search::SearchLogic::GetInstance()->OnSearchMessage(srv, \
                                                                      fd, \
                                                                    data, \
                                                                     len);
  //if (r == true)
    //return HANDLER_FINISHED;
  //else
    return HANDLER_GO_ON;
}

static handler_t OnSearchClose(struct server *srv, \
                                          int fd) {
  search::SearchLogic::GetInstance()->OnSearchClose(srv, fd);

    return HANDLER_GO_ON;
}

static handler_t OnUnknow(struct server *srv, int fd, void *data, int len) {
    return HANDLER_GO_ON;
}

static handler_t OnBroadcastConnect(struct server* srv, \
                                                int fd, \
                                            void *data, \
                                               int len) {
  search::SearchLogic::GetInstance()->OnBroadcastConnect(srv, \
                                                                   fd, \
                                                                 data, \
                                                                  len);
    return HANDLER_GO_ON;
}

static handler_t OnBroadcastClose(struct server* srv, int fd) {
  search::SearchLogic::GetInstance()->OnBroadcastClose(srv, fd);

    return HANDLER_GO_ON;
}

static handler_t OnBroadcastMessage(struct server* srv, \
                                                int fd, \
                                            void *data, \
                                               int len) {
  search::SearchLogic::GetInstance()->OnBroadcastMessage(srv, \
                                                                   fd, \
                                                                 data, \
                                                                  len);
    return HANDLER_GO_ON;
}

static handler_t OnIniTimer(struct server* srv) {
  search::SearchLogic::GetInstance()->OnIniTimer(srv);

    return HANDLER_GO_ON;
}

static handler_t OnTimeOut(struct server* srv, char* id, int opcode, int time) {
  search::SearchLogic::GetInstance()->OnTimeout(srv, id, opcode, time);

    return HANDLER_GO_ON;
}

int search_plugin_init(struct plugin *pl) {
    pl->init = OnSearchStart;

    pl->clean_up = OnSearchShutdown;

    pl->connection = OnSearchConnect;

    pl->connection_close = OnSearchClose;

    pl->connection_close_srv = OnBroadcastClose;

    pl->connection_srv = OnBroadcastConnect;

    pl->handler_init_time = OnIniTimer;

    pl->handler_read = OnSearchMessage;

    pl->handler_read_srv = OnBroadcastMessage;

    pl->handler_read_other = OnUnknow;

    pl->time_msg = OnTimeOut;

    pl->data = NULL;
    return 0;
}

