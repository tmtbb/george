//  Copyright (c) 2015-2015 The george Authors. All rights reserved.
//  Created on: 2016年5月21日 Author: kerry

#ifndef GEORGE_VIP_PROTO_BUF_H__
#define GEORGE_VIP_PROTO_BUF_H__

#include "basic/basictypes.h"
#include "logic/base_values.h"
#include "net/proto_buf.h"
#include "vip_basic_info.h"
#include <list>
#include <string>

namespace vip_logic {

namespace net_request {
class VIPNews : public george_logic::PacketHead{
 public:
	VIPNews()
 	 :uid_(NULL)
 	 ,pos_(NULL)
 	 ,count_(NULL)
 	 ,token_(NULL){
	}

	~VIPNews() {
		if (uid_) {delete uid_; uid_ = NULL;}
		if (token_) {delete token_; token_ = NULL;}
		if (pos_) {delete pos_; pos_ = NULL;}
		if (count_) {delete count_; count_ = NULL;}
	}

	virtual void set_http_packet(base_logic::DictionaryValue* value);


	void set_uid(const int64 uid) { uid_ =
		new base_logic::FundamentalValue(uid);}

	void set_token(const std::string& token) { token_ =
		new base_logic::StringValue(token);}

	void set_pos(const int32 pos) { pos_ =
		new base_logic::FundamentalValue(pos);}

	void set_count(const int32 count) { count_ =
		new base_logic::FundamentalValue(count);}

	const int64 uid() const {
		int64 uid = 0;
		uid_->GetAsBigInteger(&uid);
		return uid;
	}

	const std::string token() const {
		std::string token;
		token_->GetAsString(&token);
		return token;
	}

	const int32 pos() const {
		int32 pos;
		pos_->GetAsInteger(&pos);
		return pos;
	}

	const int32 count() const {
		int32 count;
		count_->GetAsInteger(&count);
		return count;
	}

 public:
	base_logic::FundamentalValue*     uid_;
	base_logic::StringValue*          token_;
	base_logic::FundamentalValue*     pos_;
	base_logic::FundamentalValue*     count_;
};


typedef VIPNews HotVIP;

class VIPArticle: public george_logic::PacketHead{
 public:
	VIPArticle()
 	 :uid_(NULL)
 	 ,pos_(NULL)
 	 ,count_(NULL)
 	 ,vid_(NULL)
 	 ,flag_(NULL)
 	 ,token_(NULL){
	}

	~VIPArticle(){
		if (uid_) {delete uid_; uid_ = NULL;}
		if (vid_) {delete vid_; vid_ = NULL;}
		if (flag_) {delete flag_; flag_ = NULL;}
		if (token_) {delete token_; token_ = NULL;}
		if (pos_) {delete pos_; pos_ = NULL;}
		if (count_) {delete count_; count_ = NULL;}
	}


	virtual void set_http_packet(base_logic::DictionaryValue* value);


	void set_uid(const int64 uid) { uid_ =
		new base_logic::FundamentalValue(uid);}

	void set_token(const std::string& token) { token_ =
		new base_logic::StringValue(token);}

	void set_pos(const int32 pos) { pos_ =
		new base_logic::FundamentalValue(pos);}

	void set_count(const int32 count) { count_ =
		new base_logic::FundamentalValue(count);}

	void set_vid(const int64 vid) { vid_ =
		new base_logic::FundamentalValue(vid);}

	void set_flag(const int8 flag) { flag_ =
		new base_logic::FundamentalValue(flag);}

	const int64 uid() const {
		int64 uid = 0;
		uid_->GetAsBigInteger(&uid);
		return uid;
	}

	const int64 vid() const {
		int64 vid = 0;
		vid_->GetAsBigInteger(&vid);
		return vid;
	}

	const int8 flag() const {
		int8 flag = 0;
		flag_->GetAsCharInteger(&flag);
		return flag;
	}

	const std::string token() const {
		std::string token;
		token_->GetAsString(&token);
		return token;
	}

	const int32 pos() const {
		int32 pos;
		pos_->GetAsInteger(&pos);
		return pos;
	}

	const int32 count() const {
		int32 count;
		count_->GetAsInteger(&count);
		return count;
	}

 public:
	base_logic::FundamentalValue*     uid_;
	base_logic::FundamentalValue*     vid_;
	base_logic::FundamentalValue*     flag_;
	base_logic::StringValue*          token_;
	base_logic::FundamentalValue*     pos_;
	base_logic::FundamentalValue*     count_;
};


class SubcribeVIP: public george_logic::PacketHead{
 public:
	SubcribeVIP()
 	 :pos_(NULL)
 	 ,count_(NULL)
 	 ,uid_(NULL)
 	 ,token_(NULL){
	}

	~SubcribeVIP(){
		if (uid_) {delete uid_; uid_ = NULL;}
		if (token_) {delete token_; token_ = NULL;}
		if (pos_) {delete pos_; pos_ = NULL;}
		if (count_) {delete count_; count_ = NULL;}
	}


	virtual void set_http_packet(base_logic::DictionaryValue* value);


	void set_uid(const std::string uid) { uid_ =
		new base_logic::StringValue(uid);}

	void set_token(const std::string& token) { token_ =
		new base_logic::StringValue(token);}

	void set_pos(const int32 pos) { pos_ =
		new base_logic::FundamentalValue(pos);}

	void set_count(const int32 count) { count_ =
		new base_logic::FundamentalValue(count);}


	const std::string uid() const {
		std::string uid = "0";
		uid_->GetAsString(&uid);
		return uid;
	}


	const std::string token() const {
		std::string token;
		token_->GetAsString(&token);
		return token;
	}

	const int32 pos() const {
		int32 pos = 0;
		pos_->GetAsInteger(&pos);
		return pos;
	}

	const int32 count() const {
		int32 count = 10;
		count_->GetAsInteger(&count);
		return count;
	}

 public:
	base_logic::StringValue*          uid_;
	base_logic::StringValue*          token_;
	base_logic::FundamentalValue*     pos_;
	base_logic::FundamentalValue*     count_;
};


class SetSubcribeVIP: public george_logic::PacketHead{
 public:
	SetSubcribeVIP()
 	 :uid_(NULL)
 	 ,token_(NULL)
 	 ,vid_(NULL){
	}

	~SetSubcribeVIP(){
		if (uid_) {delete uid_; uid_ = NULL;}
		if (token_) {delete token_; token_ = NULL;}
		if (vid_) {delete vid_; vid_ = NULL;}
	}


	virtual void set_http_packet(base_logic::DictionaryValue* value);


	void set_uid(const std::string& uid) { uid_ =
		new base_logic::StringValue(uid);}

	void set_token(const std::string& token) { token_ =
		new base_logic::StringValue(token);}

	void set_vid(const int64 vid) { vid_ =
		new base_logic::FundamentalValue(vid);}


	const std::string uid() const {
		std::string uid = "0";
		uid_->GetAsString(&uid);
		return uid;
	}


	const std::string token() const {
		std::string token;
		token_->GetAsString(&token);
		return token;
	}

	const int64 vid() const {
		int64 vid;
		vid_->GetAsBigInteger(&vid);
		return vid;
	}

 public:
	base_logic::StringValue*          uid_;
	base_logic::StringValue*          token_;
	base_logic::FundamentalValue*     vid_;
};

class VIPNewsDigest: public george_logic::PacketHead{
 public:
	VIPNewsDigest()
 	 :uid_(NULL)
 	 ,token_(NULL)
 	 ,article_id_(NULL) {}

	~VIPNewsDigest(){
		if(uid_ != NULL) {delete uid_; uid_ = NULL;}
		if(token_ != NULL) {delete token_; token_ = NULL;}
		if(article_id_ != NULL) {delete article_id_; article_id_ = NULL;}
	}

	void set_uid(const std::string& uid) {
		uid_ = new base_logic::StringValue(uid);
	}

	void set_token(const std::string& token) {
		token_ = new base_logic::StringValue(token);
	}

	void set_article_id(const int64 article_id) {
		article_id_ =
				new base_logic::FundamentalValue(article_id);
	}

	virtual void set_http_packet(base_logic::DictionaryValue* value);

	const std::string uid() const {
		std::string uid = "0";
		uid_->GetAsString(&uid);
		return uid;
	}


	const std::string token() const {
		std::string token;
		token_->GetAsString(&token);
		return token;
	}

	const int64 article_id() const {
		int64 article_id;
		article_id_->GetAsBigInteger(&article_id);
		return article_id;
	}
 public:
	base_logic::StringValue*               uid_;
	base_logic::StringValue*               token_;
	base_logic::FundamentalValue*          article_id_;
};

}

namespace net_reply {
class VIPNews{
 public:
	VIPNews() {
		article_type_ =  NULL;
		vid_ = NULL;
		aid_ =  NULL;
		article_time_ = NULL;
		name_ = NULL;
		title_ = NULL;
		article_source_  =  NULL;
		protrait_ =  NULL;
		introduction_ = NULL;
		subcribe_count_ = NULL;
		flag_ = NULL;
		article_url_ = NULL;
		value_ = NULL;

	}
	void set_vid(const int64 vid) {vid_ = new base_logic::FundamentalValue(vid);}
	void set_aid(const int64 aid) {aid_ = new base_logic::FundamentalValue(aid);}
	void set_flag(const int8 type) {flag_ = new base_logic::FundamentalValue(type);}
	void set_name(const std::string& name) {name_ = new base_logic::StringValue(name);}
	void set_title(const std::string& title) {
		if(title.empty())
			title_ = new base_logic::StringValue("短讯");
		else
			title_ = new base_logic::StringValue(title);
	}

	void set_protrait(const std::string& protrait) {
		protrait_  = new base_logic::StringValue(protrait);
	}

	void set_introduction(const std::string& introduction) {
		introduction_  = new base_logic::StringValue(introduction);
	}

	void set_subcribe_count(const int64 subcribe_count) {
		subcribe_count_ = new base_logic::FundamentalValue(subcribe_count);
	}

	void set_article_source(const std::string& article_source) {article_source_
		= new base_logic::StringValue(article_source);}
	void set_article_time(const int64 article_time) {article_time_ =
			new base_logic::FundamentalValue(article_time);}

	void set_article_url(const std::string& article_url) { article_url_ =
			new base_logic::StringValue(article_url);
	}

	void set_code_name(std::list<StockInfo>& dict) {
		article_type_ = new base_logic::ListValue;
		while (dict.size() > 0) {
			StockInfo value = dict.front();
			dict.pop_front();
			article_type_->Append(value.get());
		}
	}


	~VIPNews() {
		if(value_) {delete value_; value_ = NULL;}
	}

	base_logic::DictionaryValue* get() {
		value_ = new base_logic::DictionaryValue();
		if(vid_ != NULL)
			value_->Set(L"vid",vid_);
		if(aid_ != NULL)
			value_->Set(L"aid",aid_);
		if(name_ != NULL)
			value_->Set(L"name",name_);
		if(title_ != NULL)
			value_->Set(L"title",title_);
		if(article_source_ != NULL)
			value_->Set(L"article_source",article_source_);
		if(article_type_ != NULL)
			value_->Set(L"article_type",article_type_);
		if(article_time_ != NULL)
			value_->Set(L"article_time",article_time_);
		if(article_url_ != NULL)
			value_->Set(L"url",article_url_);
		if(flag_ != NULL)
			value_->Set(L"flag", flag_);
		if(subcribe_count_ != NULL)
			value_->Set(L"subcribe_count",subcribe_count_);
		if(protrait_ != NULL)
			value_->Set(L"protrait",protrait_);
		if(introduction_ != NULL)
			value_->Set(L"introduction",introduction_);
		return value_;
	}

 private:
	base_logic::FundamentalValue*       vid_;
	base_logic::FundamentalValue*       aid_;
	base_logic::FundamentalValue*       subcribe_count_;
	base_logic::StringValue*            name_;
	base_logic::StringValue*            title_;
	base_logic::FundamentalValue*       flag_;
	base_logic::StringValue*            article_source_;
	base_logic::StringValue*            article_url_;
	base_logic::ListValue*              article_type_;
	base_logic::StringValue*            protrait_;
	base_logic::StringValue*            introduction_;
	base_logic::FundamentalValue*       article_time_;
	base_logic::DictionaryValue*        value_;
};

class VIPNewsList: public george_logic::PacketHead{
 public:
	VIPNewsList(){
		list_ = new base_logic::ListValue;
		jsonpcallback_ = NULL;
	}
	~VIPNewsList() {
		//if (list_) {delete list_; list_ = NULL;}
		if (body_value_) {delete body_value_; body_value_ = NULL;}
	}

	void set_vip_news(base_logic::Value* value) {
		list_->Append(value);
	}

	void set_jsonpcallback(const std::string& callback) {
		jsonpcallback_ = new base_logic::StringValue(callback);
	}

	base_logic::DictionaryValue* body() {
		body_value_ = new base_logic::DictionaryValue();
		body_value_->SetWithoutPathExpansion(L"list",list_);
		body_value_->SetInteger(L"count",list_->GetSize());
		if (jsonpcallback_ != NULL) {
			body_value_->Set(L"jsonpcallback",jsonpcallback_);
		}
		return body_value_;
	}

	void set_http_packet(base_logic::DictionaryValue* value) {}
 private:
	base_logic::ListValue*         list_;
	base_logic::StringValue*       jsonpcallback_;
};


class VIPUser {
 public:
	VIPUser() {
		vid_ = subscribe_count_ = vip_ = NULL;
		name_ = home_page_ = introduction_ = protrait_ =NULL;
		value_ = NULL;
	}

	~VIPUser() {
		if (value_) {delete value_; value_ = NULL;}
	}

	base_logic::DictionaryValue* get() {
		value_ = new base_logic::DictionaryValue();
		if(vid_ != NULL)
			value_->Set(L"vid",vid_);
		if(subscribe_count_ != NULL)
			value_->Set(L"subscribe_count",subscribe_count_);
		if(vip_ != NULL)
			value_->Set(L"vip",vip_);
		if(name_ != NULL)
			value_->Set(L"name",name_);
		if(home_page_ != NULL)
			value_->Set(L"home_page",home_page_);
		if(introduction_ != NULL)
			value_->Set(L"introduction",introduction_);
		if(protrait_ != NULL)
			value_->Set(L"protrait",protrait_);
		return value_;
	}


    void set_vid(const int64 vid) {
    	vid_ = new base_logic::FundamentalValue(vid);
    }

    void set_subscribe_count(const int64 subscribe_count) {
    	subscribe_count_ = new base_logic::FundamentalValue(subscribe_count);
    }

    void set_vip(const int8 vip) {
    	vip_ = new base_logic::FundamentalValue(vip);
    }

    void set_name(const std::string& name) {
    	name_ = new base_logic::StringValue(name);
    }

    void set_home_page(const std::string& home_page) {
    	home_page_ = new base_logic::StringValue(home_page);
    }

    void set_introduction(const std::string& introduction) {
    	introduction_ = new base_logic::StringValue(introduction);
    }

    void set_protrait(const std::string& protrait) {
    	protrait_ = new base_logic::StringValue(protrait);
    }

 private:
	base_logic::FundamentalValue*      vid_;
	base_logic::FundamentalValue*      subscribe_count_;
	base_logic::FundamentalValue*      vip_;
	base_logic::StringValue*           name_;
	base_logic::StringValue*           home_page_;
	base_logic::StringValue*           introduction_;
	base_logic::StringValue*           protrait_;
	base_logic::DictionaryValue*       value_;
};

typedef VIPNewsList VIPUserList;

class VIPArticleList : public george_logic::PacketHead {
public:
	VIPArticleList(){
		article_list_ = new base_logic::ListValue;
		live_list_ = new base_logic::ListValue;
		vip_info_ = NULL;
	}

	~VIPArticleList() {
		//if (article_list_) {delete article_list_; article_list_ = NULL;}
		//if (live_list_) {delete live_list_; live_list_ = NULL;}
		if (body_value_) {delete body_value_; body_value_ = NULL;}
	}

	void set_vip_article(base_logic::Value* value) {
		article_list_->Append(value);
	}

	void set_vip_live(base_logic::Value* value) {
		live_list_->Append(value);
	}

	void set_vip_info(base_logic::DictionaryValue* value) {
		vip_info_ = value;
	}

	base_logic::DictionaryValue* body() {
		body_value_ = new base_logic::DictionaryValue();
		base_logic::DictionaryValue* dict  = new base_logic::DictionaryValue();
		if(article_list_ != NULL ) dict->Set(L"article", article_list_);
		if(live_list_ != NULL) dict->Set(L"live", live_list_);
		body_value_->SetWithoutPathExpansion(L"info",dict);
		body_value_->SetWithoutPathExpansion(L"vip",vip_info_);
		body_value_->SetWithoutPathExpansion(L"is_subcibe",0);
		return body_value_;
	}

	void set_http_packet(base_logic::DictionaryValue* value) {}
private:
	base_logic::ListValue*         article_list_;
	base_logic::ListValue*         live_list_;
	base_logic::DictionaryValue*   vip_info_;
	base_logic::FundamentalValue*  is_subcibe_;
};


class VIPNewsDigest : public george_logic::PacketHead {
public:
	VIPNewsDigest()
	:digest_(NULL)
	,summary_(NULL)
	,url_(NULL)
	,title_(NULL)
	,source_(NULL)
	,article_time_(NULL){}

	~VIPNewsDigest(){
		if (body_value_) {delete body_value_; body_value_ = NULL;}
	}

	void set_digest(const std::string& digest) {
		digest_ = new base_logic::StringValue(digest);
	}

	void set_summary(const std::string& summary) {
		summary_ = new base_logic::StringValue(summary);
	}

	void set_url(const std::string& url) {
		url_ = new base_logic::StringValue(url);
	}

	void set_title(const std::string& title){
		title_ = new base_logic::StringValue(title);
	}

	void set_source(const std::string& source) {
		source_ = new base_logic::StringValue(source);
	}

	void set_article_time(const int64 article_time){
		article_time_ = new base_logic::FundamentalValue(article_time);
	}

	base_logic::DictionaryValue* body() {
		body_value_ = new base_logic::DictionaryValue();
		if(digest_ != NULL )
			body_value_->SetWithoutPathExpansion(L"digest",digest_);
		if(summary_ != NULL)
			body_value_->SetWithoutPathExpansion(L"summary",summary_);
		if(url_ != NULL)
			body_value_->SetWithoutPathExpansion(L"url",url_);
		if(title_ != NULL)
			body_value_->SetWithoutPathExpansion(L"title",title_);
		if(article_time_ != NULL)
			body_value_->SetWithoutPathExpansion(L"article_time",article_time_);
		if(source_ != NULL)
			body_value_->SetWithoutPathExpansion(L"source",source_);
		return body_value_;
	}
private:
	base_logic::StringValue*    title_;
	base_logic::StringValue*    digest_;
	base_logic::StringValue*    summary_;
	base_logic::StringValue*    url_;
	base_logic::StringValue*    source_;
	base_logic::FundamentalValue*  article_time_;
};



}
}
#endif
