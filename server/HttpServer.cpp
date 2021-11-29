#include "HttpServer.h"
#include "HttpServantImp.h"

using namespace std;

HttpServer g_app;

/////////////////////////////////////////////////////////////////
void
HttpServer::initialize()
{
    //initialize application here:
    //...

    addServant<HttpServantImp>(ServerConfig::Application + "." + ServerConfig::ServerName + ".HttpServant");
	addServantProtocol(ServerConfig::Application + "." + ServerConfig::ServerName + ".HttpServant", &TC_NetWorkBuffer::parseHttp);
}
/////////////////////////////////////////////////////////////////
void
HttpServer::destroyApp()
{
    //destroy application here:
    //...
}
/////////////////////////////////////////////////////////////////
int
main(int argc, char* argv[])
{
    try
    {
        g_app.main(argc, argv);
        g_app.waitForShutdown();
    }
    catch (std::exception& e)
    {
        cerr << "std::exception:" << e.what() << std::endl;
    }
    catch (...)
    {
        cerr << "unknown exception." << std::endl;
    }
    return -1;
}
/////////////////////////////////////////////////////////////////
