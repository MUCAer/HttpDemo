#ifndef _HttpServantImp_H_
#define _HttpServantImp_H_

#include "servant/Application.h"

/**
 *
 *
 */
class HttpServantImp : public Servant
{
public:
    /**
     *
     */
    virtual ~HttpServantImp() {}

    /**
     *
     */
    virtual void initialize();

    /**
     *
     */
    virtual void destroy();

    /**
     *
     */
	int doRequest(TarsCurrentPtr current, vector<char> &buffer);

private:
	int doRequest(const TC_HttpRequest &req, TC_HttpResponse &rsp);
};
/////////////////////////////////////////////////////
#endif
