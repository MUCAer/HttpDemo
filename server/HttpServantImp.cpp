#include "HttpServantImp.h"
#include "servant/Application.h"
#include "frame/cgi_manager.h"
#include "utils/common_define.h"
using namespace std;

//////////////////////////////////////////////////////
void HttpServantImp::initialize()
{
    //initialize servant here:
    //...
}

//////////////////////////////////////////////////////
void HttpServantImp::destroy()
{
    //destroy servant here:
    //...
    auto strategy_manager = StrategyManager::get_instance();
    auto ret = strategy_manager.init();

}

int HttpServantImp::doRequest(TarsCurrentPtr current, vector<char> &buffer)
{
    TC_HttpRequest req;
    TC_HttpResponse rsp;

	// parse request header
    vector<char> v = current->getRequestBuffer();
    string sBuf;
    sBuf.assign(v.data(), v.size());
    req.decode(sBuf);

    int ret = doRequest(req, rsp);

    rsp.encode(buffer);

    return ret;
}

int HttpServantImp::doRequest(const TC_HttpRequest &req, TC_HttpResponse &rsp)
{
	string msg = req.getOriginRequest();
    string msg_url = req.getRequestUrl();
    
    msg = StrategyManager::get_instance().do_response(msg);
    msg += "\"}";
    
    // rsp.setContentType("text/html");
    rsp.setContentType(::inf::common::TARS_PROTOCOL_HTTP_JSON);
    rsp.setResponse(msg.c_str(), msg.size());
    return 0;   
}
