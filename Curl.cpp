/****************************************************
 *** Copyright (c) 2014 Aaron aaron1126@gmail.com ***
 ***                                              ***
 *** See the file LICENSE for copying permission. ***
****************************************************/


#include "Curl.h"

#include <cstdlib>

using namespace std;

Curl::Curl()
{
   CURL *handle = curl_easy_init();
   atexit(curl_global_cleanup);
   if (!handle) {
      throw runtime_error("Curl init failed!");
   }
   handle_.reset(handle);
}

Curl::~Curl()
{
}

void Curl::perform()
{
   CURLcode ret = curl_easy_perform(handle_.get());
   if (ret != CURLE_OK) {
      throw runtime_error(curl_easy_strerror(ret));
   }
}
