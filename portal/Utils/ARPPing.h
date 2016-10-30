#ifndef ARPPING_H_
#define ARPPING_H_

#include <string>
#include <map>
#include "../Portal.h"
#include "../Utils/PortalUtils.h"

std::map<std::string,std::string> ARPPingSend(const std::string& ip_net, const std::string& iface, size_t send_count);

std::map<std::string,std::string> ARPPingSendRcv(const std::string& ip_net, const std::string& iface, size_t send_count);

#endif /* ARPPING_H_ */
