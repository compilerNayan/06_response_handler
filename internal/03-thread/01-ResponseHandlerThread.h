/**
 * @file 01-ResponseHandlerThread.h
 * @brief IRunnable that runs HandleRequest on IHttpRequestHandler (typically in a loop).
 */

#ifndef RESPONSE_HANDLER_RESPONSE_HANDLER_THREAD_H
#define RESPONSE_HANDLER_RESPONSE_HANDLER_THREAD_H

#include <IRunnable.h>
#include <Thread.h>
#include "../01-interface/01-IHttpRequestHandler.h"

class ResponseHandlerThread final : public IRunnable {

    /* @Autowired */
    Private IHttpRequestHandlerPtr httpRequestHandler;

    Public Void Run() override {
        Thread::Sleep(6000);
        while (true) {
            httpRequestHandler->HandleRequest();
            Thread::Sleep(100);  // yield so IDLE task runs; avoids task watchdog trigger
        }
    }
};

#endif // RESPONSE_HANDLER_RESPONSE_HANDLER_THREAD_H
