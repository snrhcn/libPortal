#ifndef IPOPTIONLAYER_H_
#define IPOPTIONLAYER_H_

#include "../Layer.h"

namespace Portal {

    class IPOptionLayer: public Layer {

        void ParseLayerData(ParseInfo* info);

    public:

    	IPOptionLayer() { /* */ };

    	struct ExtraInfo {
    		/* Next layer on the top of the options */
    		Layer* next_layer;
    		/* Remaining option length */
    		int optlen;
    	};

        virtual void SetCopyFlag(const word& value) = 0;

        virtual void SetClass(const word& value) = 0 ;

        virtual void SetOption(const word& value) = 0;

        virtual void SetLength(const byte& value) = 0;

        virtual word  GetCopyFlag() const = 0;

        virtual word  GetClass() const = 0;

        virtual word  GetOption() const = 0;

        virtual byte  GetLength() const = 0;

        /* Build IP options from first byte */
        static IPOptionLayer* Build(int opt);

        ~IPOptionLayer() { /* Destructor */ };

    };

}


#endif /* IPOPTIONLAYER_H_ */
