/**
 * @file 01-HttpRequestHandler.h
 * @brief Default HTTP request handler: dequeue from request queue, dispatch, enqueue response.
 */

#ifndef RESPONSE_HANDLER_HTTP_REQUEST_HANDLER_H
#define RESPONSE_HANDLER_HTTP_REQUEST_HANDLER_H

#include <IHttpRequestQueue.h>
#include <IHttpRequestDispatcher.h>
#include <IHttpResponseQueue.h>
#include <IHttpResponse.h>
#include <ILogger.h>

#include "../01-interface/01-IHttpRequestHandler.h"

/* @Component */
class HttpRequestHandler final : public IHttpRequestHandler {

    /* @Autowired */
    Private ILoggerPtr logger;

    /* @Autowired */
    Private IHttpRequestQueuePtr requestQueue;

    /* @Autowired */
    Private IHttpRequestDispatcherPtr dispatcher;

    /* @Autowired */
    Private IHttpResponseQueuePtr responseQueue;

    Public HttpRequestHandler() = default;

    Public ~HttpRequestHandler() override = default;

    // ============================================================================
    // HTTP Request Handling Operations
    // ============================================================================

    Public Bool HandleRequest() override {
        if (requestQueue->IsEmpty()) {
            return false;
        }

        IHttpRequestPtr request = requestQueue->DequeueRequest();
        if (request == nullptr) {
            logger->Warning(Tag::Untagged, StdString("[HttpRequestHandler] HandleRequest: dequeue returned null"));
            return false;
        }

        logger->Info(Tag::Untagged, StdString("[HttpRequestHandler] Handling request id ") + request->GetRequestId() + " " + request->GetPath());
        responseQueue->EnqueueResponse(dispatcher->DispatchRequest(request));
        logger->Info(Tag::Untagged, StdString("[HttpRequestHandler] Request handled, response enqueued"));
        return true;
    }
};

#endif // RESPONSE_HANDLER_HTTP_REQUEST_HANDLER_H
