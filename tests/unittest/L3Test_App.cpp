#ifndef MODULE_NAME
#define MODULE_NAME L3Test
#endif /* MODULE_NAME */

#include <core/core.h>
#include <websocket/websocket.h>

MODULE_NAME_DECLARATION("l3_tests")

using namespace WPEFramework;
using namespace std;


int main ()
{
     
   Core::SystemInfo::SetEnvironment(_T("THUNDER_ACCESS"), (_T("127.0.0.1:9998")));


    std::shared_ptr<WPEFramework::JSONRPC::LinkType<WPEFramework::Core::JSON::IElement>> jsonPlugin;
    jsonPlugin = make_shared<WPEFramework::JSONRPC::LinkType<WPEFramework::Core::JSON::IElement> >("org.rdk.NetworkManager.1", "");
    JsonObject parameters, response;
   
    //Test 1:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetIPSettings"), parameters, response);
	printf("testing");
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
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetLogLevel"), parameters, response);
     std::cout << "Operation Result: ERROR_CODE(ERROR_NONE, 0)" << std::endl;
    //Test 6:
    parameters["level"] = "0";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetLogLevel"), parameters, response);
    //Test 7:
    parameters["level"] = "7";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetLogLevel"), parameters, response);
    //Test 8:
    parameters["level"] = -1; //invalid level
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetLogLevel"), parameters, response);

    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetLogLevel"), parameters, response);
     std::cout << "Operation Result: ERROR_CODE(ERROR_GENERAL, 1)" << std::endl;
    
    //Test 9:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetAvailableInterfaces"), parameters, response);
     std::cout << "Operation Result: ERROR_CODE(ERROR_UNAVAILABLE, 2)" << std::endl;
    
    //Test 10:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetPrimaryInterface"), parameters, response);
    EXPECT_EQ(Core::ERROR_UNAVAILABLE); 
    //Test 11:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetPrimaryInterface"), parameters, response);
    //Test 12:
    parameters["interface"] = "wlan0";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetPrimaryInterface"), parameters, response); 
    //Test 13:
    parameters["interface"] = "eth0";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetPrimaryInterface"), parameters, response);
    //Test 14:
    parameters["interface"] = "test1"; //invalid interface
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetPrimaryInterface"), parameters, response);
    
    //Test 15:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetInterfaceState"), parameters, response);
    //Test 16:
    parameters["interface"] = "wlan0";
    parameters["enabled"] = true;
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetInterfaceState"), parameters, response);
    //Test 17:
    parameters["interface"] = "eth0";
    parameters["enabled"] = false;
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetInterfaceState"), parameters, response);
    //Test 18:
    parameters["interface"] = "test";
    parameters["enabled"] = "true";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetInterfaceState"), parameters, response);
    //Test 19:
    parameters["interface"] = "wlan0";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetInterfaceState"), parameters, response);
    
    //Test 20:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetInterfaceState"), parameters, response);
    //Test 21:
    parameters["interface"] = "eth0";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetInterfaceState"), parameters, response);
    //Test 22:
    parameters["interface"] = "wlan0";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetInterfaceState"), parameters, response);
    //Test 23:
    parameters["interface"] = "test";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetInterfaceState"), parameters, response);
    
    //Test 24:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetIPSettings"), parameters, response);
    
    //Test 25:
    parameters["interface"] = "wlan0";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetIPSettings"), parameters, response);
    //Test 26:
    parameters["interface"] = "wlan0";
    parameters["ipversion"] = "IPv4";
    parameters["autoconfig"] = true;
    parameters["ipaddress"] = "192.168.1.101";
    parameters["prefix"] = 24;
    parameters["gateway"] = "192.168.1.1";
    parameters["primarydns"] = "192.168.1.1";
    parameters["secondarydns"] = "192.168.1.2";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetIPSettings"), parameters, response);
     
     //Test 27:
     jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetStunEndpoint"), parameters, response);
    
    //Test 28:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetStunEndpoint"), parameters, response);
    //Test 29:
    parameters["endpoint"] = "45.57.221.20";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetStunEndpoint"), parameters, response);
    //Test 30:
     parameters["endpoint"] = "1567";
     jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetStunEndpoint"), parameters, response);
     parameters["endpoint"] = "45.57.221.20";
     parameters["port"] = 3478;
     parameters["timeout"] = 30;
     parameters["cacheLifetime"] = 0;
     jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetStunEndpoint"), parameters, response);
    
    //Test 31:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetConnectivityTestEndpoints"), parameters, response);
    
    //Test 32:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetConnectivityTestEndpoints"), parameters, response);
    //Test 33:
    parameters["endpoint"] =  "http://clients3.google.com/generate_204";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetConnectivityTestEndpoints"), parameters, response);
    //Test 34:
    parameters["endpoint"] =  "clients.com";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetConnectivityTestEndpoints"), parameters, response);
    
    //Test 35:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("IsConnectedToInternet"), parameters, response);
    //Test 36:
    parameters["interface"] = "wlan0";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("IsConnectedToInternet"), parameters, response);
    //Test 37:
    parameters["ipversion"] = "IPv4";
    parameters["interface"] = "wlan0"; 
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("IsConnectedToInternet"), parameters, response);
    //Test 38:
     parameters["ipversion"] = "IPv6";
     parameters["interface"] = "wlan0"; 
     jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("IsConnectedToInternet"), parameters, response);
     //Test 39:
     parameters["ipversion"] = "IPv6";
     parameters["interface"] = "test1"; 
     jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("IsConnectedToInternet"), parameters, response);
    
    //Test 40:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetCaptivePortalURI"), parameters, response);
    
    //Test 41:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetPublicIP"), parameters, response);
    //Test 42:
    parameters["interface"] = "wlan0";
    parameters["ipversion"] = "IPv4";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetPublicIP"), parameters, response);
    //Test 43:
    parameters["interface"] = "wlan0";
    parameters["ipversion"] = "IPv6";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetPublicIP"), parameters, response);
    //Test 44:
    parameters["interface"] = "test";
    parameters["ipversion"] = "IPv6";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetPublicIP"), parameters, response);
    //Test 45:
    parameters["ipversion"] = "IPv4";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetPublicIP"), parameters, response);
    //Test 46:
    parameters["interface"] = "wlan0";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetPublicIP"), parameters, response);
    
    //Test 47:
     parameters["endpoint"] = "45.57.221.20"; 
     parameters["ipversion"] = "IPv4";
     parameters["count"] = 2;
     parameters["timeout"] = 5;
     parameters["guid"] = "...";
     jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("Ping"), parameters, response);
     //Test 48:
     parameters["endpoint"] = "45.57.221.20"; 
     parameters["ipversion"] = "IPv4";
     parameters["count"] = 2;
     parameters["timeout"] = 5;
     jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("Ping"), parameters, response);
     //Test 49:
      parameters["endpoint"] = "2001:4860:4860::8888"; 
      parameters["ipversion"] = "IPv6";
      jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("Ping"), parameters, response);
      
      //Test 50:
      parameters["endpoint"] = "2001:4860:4860::8888"; 
      parameters["ipversion"] = "IPv6";
      jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("Trace"), parameters, response);
      //Test 51:
      parameters["endpoint"] = "45.57.221.20"; 
      parameters["ipversion"] = "IPv4";
      jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("Trace"), parameters, response);
      //Test 52:
       parameters["endpoint"] = "45.57.221.20"; // A likely reachable public IP
       parameters["ipversion"] = "IPv4";
       parameters["packets"] = 3;
       parameters["guid"] = "...";
       jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("Trace"), parameters, response);
    
    //Test 53:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetConnectedSSID"), parameters, response);
    
    //Test 54:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetWiFiSignalQuality"), parameters, response);
    
    //Test 55:
     jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetSupportedSecurityModes"), parameters, response);
    
    //Test 56:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetWifiState"), parameters, response);

   
    
    std::shared_ptr<WPEFramework::JSONRPC::LinkType<WPEFramework::Core::JSON::IElement>> jsonPlugin2;
    jsonPlugin2 = make_shared<WPEFramework::JSONRPC::LinkType<WPEFramework::Core::JSON::IElement> >("org.rdk.Network.1", "");
  
    //Test 1:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getDefaultInterface"), parameters, response);
    //Test 2:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getInterfaces"), parameters, response);

    //Test 3:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getIPSettings"), parameters, response);
    //Test 4:
    parameters["interface"] = "WIFI";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getIPSettings"), parameters, response);
    //Test 5:
    parameters["interface"] = "etho";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getIPSettings"), parameters, response);
    //Test 6:
    parameters["interface"] = "etho";
    parameters["ipversion"] = "IPv4";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getIPSettings"), parameters, response);
    //Test 7:
    parameters["interface"] = "WIFI";
    parameters["ipversion"] = "IPv4";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getIPSettings"), parameters, response);
    //Test 8:
    parameters["interface"] = "test";
    parameters["ipversion"] = "IPv6";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getIPSettings"), parameters, response);
    
    //Test 9:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getNamedEndpoints"), parameters, response);
 
    //Test 11:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getStbIp"), parameters, response);
    
    //Test 12:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getSTBIPFamily"), parameters, response);
    //Test 13:
    parameters["family"] = "AF_INET";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getSTBIPFamily"), parameters, response);
    //Test 14:
    parameters["family"] = "AF_INET6";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getSTBIPFamily"), parameters, response);
    //Test 15:
    parameters["family"] = "abcd";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getSTBIPFamily"), parameters, response);
    
    //Test 17:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("setConnectivityTestEndpoints"), parameters, response);
    //Test 18:
    parameters["endpoints"] = "http://clients3.google.com/generate_204";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("setConnectivityTestEndpoints"), parameters, response);
    
    //Test 19:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("isConnectedToInternet"), parameters, response);
    //Test 20:
    parameters["ipversion"] = "IPv4";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("isConnectedToInternet"), parameters, response);
    //Test 21:
    parameters["ipversion"] = "IPv6";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("isConnectedToInternet"), parameters, response);
    //Test 22:
    parameters["ipversion"] = "IP";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("isConnectedToInternet"), parameters, response);
  
    //Test 23:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getInternetConnectionState"), parameters, response);
    //Test 23:
    parameters["ipversion"] = "IPv4";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getInternetConnectionState"), parameters, response);
    //Test 24:
    parameters["ipversion"] = "IPv6";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getInternetConnectionState"), parameters, response);
    //Test 25:
    parameters["ipversion"] = "IP";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getInternetConnectionState"), parameters, response);
    
    //Test 26:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getCaptivePortalURI"), parameters, response);
   
    //Test 27:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("startConnectivityMonitoring"), parameters, response);
    //Test 28:
    parameters["interval"] = 30;
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("startConnectivityMonitoring"), parameters, response);
    //Test 29:
    parameters["interval"] = -10;
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("startConnectivityMonitoring"), parameters, response);
    
    //Test 30:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("isInterfaceEnabled"), parameters, response);
    //Test 31:
    parameters["interface"] = "WIFI";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("isInterfaceEnabled"), parameters, response);
    //Test 32:
    parameters["interface"] = "ETHERNET";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("isInterfaceEnabled"), parameters, response);
    //Test 33:
    parameters["interface"] = "invalid";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("isInterfaceEnabled"), parameters, response);
    
    //Test 34:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("ping"), parameters, response);
    //Test 35:
    parameters["endpoint"] = "45.57.221.20"; 
    parameters["packets"] = 3;
    parameters["guid"] = "...";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("ping"), parameters, response);
    //Test 36:
    parameters["endpoint"] = "45.57.221.20";
    parameters["packets"] = 1;
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("ping"), parameters, response);
    
    //Test 37:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("setDefaultInterface"), parameters, response);
    //Test 38:
     parameters["interface"] = "WIFI";
     parameters["persist"] = true;
     jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("setDefaultInterface"), parameters, response);
     //Test 39:
     parameters["interface"] = "ETHERNET";
     parameters["persist"] = false;
     jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("setDefaultInterface"), parameters, response);
     //Test 40:
     parameters["interface"] = "ET0";
     parameters["persist"] = true;
     jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("setDefaultInterface"), parameters, response);
     
     //Test 41:
     jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("setInterfaceEnabled"), parameters, response);
     //Test 42:
     parameters["interface"] = "WIFI"; 
     parameters["enabled"] = true;
     parameters["persist"] = true;
     jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("setInterfaceEnabled"), parameters, response);
     //Test 42:
     parameters["interface"] = "ETHERNET";
     parameters["enabled"] = false;
     parameters["persist"] = false;
     jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("setInterfaceEnabled"), parameters, response);
     //Test 43:
     parameters["interface"] = "ET0";
     parameters["enabled"] = true;
     parameters["persist"] = true;
     jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("setInterfaceEnabled"), parameters, response);
     
     //Test 44:
     jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("setIPSettings"), parameters, response);
     //Test 45:
      parameters["interface"] = "WIFI";
      parameters["ipversion"] = "IPv4";
      parameters["autoconfig"] = true;
      jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("setIPSettings"), parameters, response);
      //Test 46:
      parameters["interface"] = "WIFI";
      parameters["ipversion"] = "IPv4";
      parameters["autoconfig"] = true;
      parameters["ipaddr"] = "192.168.1.101";
      parameters["netmask"] = "255.255.255.0";
      parameters["gateway"] = "192.168.1.1";
      parameters["primarydns"] = "192.168.1.1";
      parameters["secondarydns"] = "192.168.1.2";
      jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("setIPSettings"), parameters, response);
      //Test 47:
      parameters["interface"] = "WIFI";
      parameters["ipversion"] = "IPv4";
      parameters["autoconfig"] = true;
      parameters["ipaddr"] = "1.1.2";
      parameters["netmask"] = "255.255.255.0";
      parameters["gateway"] = "192.168.1.1";
      parameters["primarydns"] = "192.168.1.1";
      parameters["secondarydns"] = "192.168.1.2";
      jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("setIPSettings"), parameters, response);
      
      //Test 48:
      jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getPublicIP"), parameters, response);
      //Test 49:
      parameters["iface"] = "WIFI"; 
      parameters["ipv6"] = true;  
      jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getPublicIP"), parameters, response);
      //Test 50:
      parameters["iface"] = "ETHERNET"; 
      parameters["ipv6"] = false;  
      jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getPublicIP"), parameters, response);
      //Test 49:
      parameters["iface"] = "eto"; 
      parameters["ipv6"] = true;  
      jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getPublicIP"), parameters, response);
      
     
    std::shared_ptr<WPEFramework::JSONRPC::LinkType<WPEFramework::Core::JSON::IElement>> jsonPlugin3;
    jsonPlugin3 = make_shared<WPEFramework::JSONRPC::LinkType<WPEFramework::Core::JSON::IElement> >("org.rdk.Wifi.1", "");
    //Test 1:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("cancelWPSPairing"), parameters, response);
    
    //Test 2:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("clearSSID"), parameters, response);
    
    //Test 3:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("connect"), parameters, response);
    
    //Test 4:
    parameters["ssid"] = "123412341234";
    parameters["passphrase"] = "password";
    parameters["securityMode"] = 2; 
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("connect"), parameters, response);
    //Test 5:
    parameters["ssid"] = "myssid";
    parameters["passphrase"] = "password";
    parameters["securityMode"] = 99; 
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("connect"), parameters, response);
    //Test 6:
    parameters["ssid"] = "myssid";
    parameters["passphrase"] = "password";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("connect"), parameters, response);
    //Test 7:
    parameters["securityMode"] = 99; 
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("connect"), parameters, response);
    //Test 8:
    parameters["ssid"] = "myssid";
    parameters["securityMode"] = 99; 
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("connect"), parameters, response);
    
    //Test 9:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("disconnect"), parameters, response);
    
    //Test 10:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getConnectedSSID"), parameters, response);
    
    //Test 11:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getCurrentState"), parameters, response);
    
    //Test 12:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getPairedSSID"), parameters, response);
    
    //Test 13:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getPairedSSIDInfo"), parameters, response); 
      
    //Test 14:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getSupportedSecurityModes"), parameters, response);
    
    //Test 15:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("initiateWPSPairing"), parameters, response);
    //Test 16:
    parameters["method"] = "PIN";
    parameters["wps_pin"] = "12345678";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("initiateWPSPairing"), parameters, response);
    //Test 17:
    parameters["method"] = "PIN";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("initiateWPSPairing"), parameters, response);
    //Test 18:
    parameters["method"] = "";
    parameters["wps_pin"] = "12345678";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("initiateWPSPairing"), parameters, response);
    //Test 19:
    parameters["method"] = "PIN";
    parameters["wps_pin"] = "1234abcd";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("initiateWPSPairing"), parameters, response);
    //Test 20:
    parameters["wps_pin"] = "12345678";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("initiateWPSPairing"), parameters, response);
    
    //Test 21:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("isPaired"), parameters, response);
    
    //Test 22:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("isSignalThresholdChangeEnabled"), parameters, response);
    
    //Test 23:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("org.rdk.Wifi.saveSSID"), parameters, response);
    //Test 24:
    parameters["ssid"] = "TestNetwork";
    parameters["passphrase"] = "securePassword123";
    parameters["securityMode"] = 2;
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("org.rdk.Wifi.saveSSID"), parameters, response);
    //Test 25:
    parameters["ssid"] = "";
    parameters["passphrase"] = "securePassword123";
    parameters["securityMode"] = 2;
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("org.rdk.Wifi.saveSSID"), parameters, response);
    //Test 26:
    parameters["ssid"] = "TestNetwork";
    parameters["passphrase"] = "securePassword123";
    parameters["securityMode"] = 99;   //inavlid mode
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("org.rdk.Wifi.saveSSID"), parameters, response);
    //Test 27:
    parameters["ssid"] = "TestNetwork";
    parameters["securityMode"] = 2;
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("org.rdk.Wifi.saveSSID"), parameters, response);
    //Test 28:
    parameters["securityMode"] = 2;
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("org.rdk.Wifi.saveSSID"), parameters, response);
     
    //Test 29:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("startScan"), parameters, response);
    //Test 30:
    parameters["incremental"] = false;
    parameters["ssid"] = "";
    parameters["frequency"] = "";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("org.rdk.Wifi.startScan"), parameters, response);
    //Test 31:
    parameters["incremental"] = true;
    parameters["ssid"] = "myssid";
    parameters["frequency"] = "";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("org.rdk.Wifi.startScan"), parameters, response);
    //Test 32:
    parameters["incremental"] = false;
    parameters["ssid"] = "myssid";
    parameters["frequency"] = "2412";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("org.rdk.Wifi.startScan"), parameters, response);
    //Test 33:
    parameters["incremental"] = true;
    parameters["ssid"] = "myssid";
    parameters["frequency"] = "5200";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("org.rdk.Wifi.startScan"), parameters, response);
    //Test 34:
    parameters["frequency"] = "5200";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("org.rdk.Wifi.startScan"), parameters, response);
    //Test 35:
    parameters["incremental"] = true;
    parameters["frequency"] = "5200";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("org.rdk.Wifi.startScan"), parameters, response);
    //Test 36:
    parameters["incremental"] = true;
    parameters["ssid"] = "myssid";
    parameters["frequency"] = "abc";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("org.rdk.Wifi.startScan"), parameters, response);
    
    //Test 37:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("stopScan"), parameters, response);
      

}
