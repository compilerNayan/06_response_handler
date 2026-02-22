/**
 * @file 01-IHttpRequestHandler.h
 * @brief Interface for handling HTTP requests (dequeue, dispatch, enqueue response).
 */

#ifndef RESPONSE_HANDLER_IHTTP_REQUEST_HANDLER_H
#define RESPONSE_HANDLER_IHTTP_REQUEST_HANDLER_H

#include <StandardDefines.h>
#include <IHttpRequest.h>

DefineStandardPointers(IHttpRequestHandler)
class IHttpRequestHandler {

    Public Virtual ~IHttpRequestHandler() = default;

    // ============================================================================
    // HTTP REQUEST HANDLING OPERATIONS
    // ============================================================================

    /**
     * Handles a request from the queue if available: dequeue, dispatch, enqueue response.
     * @return true if a request was handled, false if queue was empty or handling failed
     */
    Public Virtual Bool HandleRequest() = 0;
};

#endif // RESPONSE_HANDLER_IHTTP_REQUEST_HANDLER_H
