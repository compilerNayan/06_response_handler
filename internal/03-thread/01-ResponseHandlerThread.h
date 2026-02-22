/**
 * @file 01-ResponseHandlerThread.h
 * @brief IRunnable that runs HandleRequest on IHttpRequestHandler (typically in a loop).
 */

#ifndef RESPONSE_HANDLER_RESPONSE_HANDLER_THREAD_H
#define RESPONSE_HANDLER_RESPONSE_HANDLER_THREAD_H

#include <IRunnable.h>
#include "../01-interface/01-IHttpRequestHandler.h"

class ResponseHandlerThread final : public IRunnable {

    /* @Autowired */
    Private IHttpRequestHandlerPtr httpRequestHandler;

    Public Void Run() override {
        while (true) {  
            httpRequestHandler->HandleRequest()
        }
    }
};

#endif // RESPONSE_HANDLER_RESPONSE_HANDLER_THREAD_H
