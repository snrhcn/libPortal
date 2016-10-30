#ifndef IPLAYER_H_
#define IPLAYER_H_

#include "../Layer.h"

namespace Portal {

    class IPLayer: public Layer {

    public:

    	enum { PROTO = 0xfff6 };

        IPLayer() { /* Constructor */ };

        virtual void SetSourceIP(const std::string& value) = 0;

        virtual void SetDestinationIP(const std::string& value) = 0;

        virtual std::string  GetSourceIP() const = 0;

        virtual std::string  GetDestinationIP() const = 0;

        virtual byte* GetRawSourceIP() const = 0;
        
        virtual byte* GetRawDestinationIP() const = 0;
        
        /* Method to build IP layer from the source address */
        static IPLayer* BuildSrc(const std::string& ip_src);

        /* Method to build IP layer from the destination address */
        static IPLayer* BuildDst(const std::string& ip_dst);

        /*
         * Method to build IP layer from the destination address and set the correct IP
         * on the source field (from the interface specified).
         */
        static IPLayer* BuildDst(const std::string& ip_dst, const std::string& iface);

        virtual ~IPLayer() { /* Destructor */ };

    };

}

#endif /* IPLAYER_H_ */
