// Copyright (c) 2016 The george Authors. All rights reserved.
// news.cc
// Created on: 2016年5月19日.
// Author: Paco.

#include "news/news.h"

namespace news {

News::News() {
  data_ = new Data();
}

News::~News() {
  if (data_ != NULL) {
    data_->Release();
  }
}

News::News(const News& news) : data_(news.data_){
  if (data_ != NULL) {
    data_->AddRef();
  }
}

News& News::operator = (const News& news) {
  if(news.data_ != NULL){
    news.data_->AddRef();
  }
  if (data_ != NULL) {
    data_->Release();
  }
  data_ = news.data_;
  return (*this);
}


void News::Serialization(DicValue* value) {
  value->GetBigInteger(L"id", &data_->id_);
  value->GetBigInteger(L"type", &data_->type_);
  value->GetString(L"title", &data_->title_);
  std::string::size_type pos = data_->title_.find_first_of("\"");
  while (pos != std::string::npos) {
    data_->title_.replace(pos, 1, "'");
    pos = data_->title_.find_first_of("\"");
  }
  value->GetString(L"url", &data_->url_);
  value->GetBigInteger(L"time", &data_->time_);
  value->GetString(L"industry", &data_->rf_industry_);
  value->GetString(L"section", &data_->rf_section_);
  value->GetString(L"stock", &data_->rf_stock_);
  value->GetString(L"summary", &data_->summary_);
  std::string::size_type pos_sum = data_->summary_.find_first_of("\"");
  while (pos_sum != std::string::npos) {
    data_->summary_.replace(pos_sum, 1, "'");
    pos_sum = data_->summary_.find_first_of("\"");
  }
  int64 n = 0;
  value->GetBigInteger(L"sentiment", &n);
  data_->sentiment_ = n;
  value->GetBigInteger(L"updated_time", &data_->updated_time_);
  value->GetString(L"from", &data_->from_);

}

SimpleNews::SimpleNews() {
  data_ = new Data();
}

SimpleNews::~SimpleNews() {
  if (data_ != NULL) {
    data_->Release();
  }
}

SimpleNews::SimpleNews(const SimpleNews& news) : data_(news.data_){
  if (data_ != NULL) {
    data_->AddRef();
  }
}

SimpleNews& SimpleNews::operator = (const SimpleNews& news) {
  if(news.data_ != NULL){
    news.data_->AddRef();
  }
  if (data_ != NULL) {
    data_->Release();
  }
  data_ = news.data_;
  return (*this);
}


void SimpleNews::Serialization(DicValue* value) {
  value->GetBigInteger(L"id", &data_->id_);
  value->GetBigInteger(L"time", &data_->time_);
  value->GetString(L"stock", &data_->rf_stock_);
  int64 n = 0;
  value->GetBigInteger(L"sentiment", &n);
  data_->sentiment_ = n;
}

}  // namespace news
