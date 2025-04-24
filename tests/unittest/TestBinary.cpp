#ifndef MODULE_NAME
#define MODULE_NAME TestBinary
#endif /* MODULE_NAME */

#include <core/core.h>
#include <websocket/websocket.h>

MODULE_NAME_DECLARATION("MyTestBinary")

using namespace WPEFramework;
using namespace std;


int main ()
{
     {
   Core::SystemInfo::SetEnvironment(_T("THUNDER_ACCESS"), (_T("127.0.0.1:9998")));


    std::shared_ptr<WPEFramework::JSONRPC::LinkType<WPEFramework::Core::JSON::IElement>> jsonPlugin;
    jsonPlugin = make_shared<WPEFramework::JSONRPC::LinkType<WPEFramework::Core::JSON::IElement> >("org.rdk.NetworkManager.1", "");
    JsonObject parameters, response;

    //Test 1:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetIPSettings"), parameters, response);
    //Test 2:
    parameters["interface"] = "test";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetIPSettings"), parameters, response);
    //Test 3:
    parameters["interface"] = "eth0";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetIPSettings"), parameters, response);
    //Test 4:
    parameters["interface"] = "wlan0";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetIPSettings"), parameters, response);
    
    //Test 5:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetLogLevel), parameters, response);

}
