#ifndef TCPOPTIONLAYER_H_
#define TCPOPTIONLAYER_H_

#include "../Layer.h"
#include "TCP.h"

namespace Portal {

    class TCPOptionLayer: public Layer {

    protected:
    	void ParseLayerData(ParseInfo* info);

    public:

        TCPOptionLayer() { /* */ };

    	struct ExtraInfo {
    		/* Next layer on the top of the options */
    		Layer* next_layer;
    		/* Remaining option length */
    		int optlen;
			/* The Length of TCP header in internet words */
			size_t header_len;
    	};

        virtual void SetKind(const byte& value) = 0;

        virtual void SetLength(const byte& value) = 0;

        virtual byte  GetKind() const = 0;

        virtual byte  GetLength() const = 0;

        /* Build TCP options from first byte */
        static TCPOptionLayer* Build(int opt, ParseInfo *info);

        ~TCPOptionLayer() { /* Destructor */ };

    };

}


#endif /* TCPOPTIONLAYER_H_ */
