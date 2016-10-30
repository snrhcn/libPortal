## LibPortal 
AUTOMAKE_OPTIONS = subdir-objects

ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS}

lib_LTLIBRARIES = libPortal.la

libPortal_la_SOURCES = Portal/Layer.cpp \
						Portal/Payload.cpp \
						Portal/Packet.cpp \
						Portal/PacketDecoder.cpp \
						Portal/InitPortal.cpp \
						Portal/Utils/PrintMessage.cpp \
						Portal/Utils/BitHandling.cpp \
						Portal/Utils/IPResolver.cpp \
						Portal/Utils/IPv4Parse.cpp \
						Portal/Utils/RawSocket.cpp \
						Portal/Utils/PortalUtils.cpp \
						Portal/Utils/PacketContainer.cpp \
						Portal/Utils/ARPPing.cpp \
						Portal/Utils/ARPSpoofing.cpp \
						Portal/Utils/ARPSpoofingReply.cpp \
						Portal/Utils/ARPSpoofingRequest.cpp \
						Portal/Utils/Sniffer.cpp \
						Portal/Utils/TCPConnection.cpp \
						Portal/Fields/FieldContainer.cpp \
						Portal/Fields/FieldInfo.cpp \
						Portal/Fields/IPAddress.cpp \
						Portal/Fields/IPv6Address.cpp \
						Portal/Fields/MACAddress.cpp \
						Portal/Fields/NumericFields.cpp \
						Portal/Protocols/RawLayer.cpp \
						Portal/Protocols/EthernetConstructor.cpp \
						Portal/Protocols/EthernetPortal.cpp \
						Portal/Protocols/Dot1QConstructor.cpp \
						Portal/Protocols/Dot1QPortal.cpp \
						Portal/Protocols/ARPConstructor.cpp \
						Portal/Protocols/ARPPortal.cpp \
						Portal/Protocols/IPConstructor.cpp \
						Portal/Protocols/IPPortal.cpp \
						Portal/Protocols/IPOptionLayer.cpp \
						Portal/Protocols/IPOptionConstructor.cpp \
						Portal/Protocols/IPOptionPortal.cpp \
						Portal/Protocols/IPOptionPadConstructor.cpp \
						Portal/Protocols/IPOptionPadPortal.cpp \
						Portal/Protocols/IPOptionTracerouteConstructor.cpp \
						Portal/Protocols/IPOptionTraceroutePortal.cpp \
						Portal/Protocols/IPOptionPointerConstructor.cpp \
						Portal/Protocols/IPOptionPointerPortal.cpp \
						Portal/Protocols/UDPConstructor.cpp \
						Portal/Protocols/UDPPortal.cpp \
						Portal/Protocols/TCPConstructor.cpp \
						Portal/Protocols/TCPPortal.cpp \
						Portal/Protocols/TCPOptionLayer.cpp \
						Portal/Protocols/TCPOptionConstructor.cpp \
						Portal/Protocols/TCPOptionPortal.cpp \
						Portal/Protocols/TCPOptionPadConstructor.cpp \
						Portal/Protocols/TCPOptionPadPortal.cpp \
						Portal/Protocols/TCPOptionMaxSegSizeConstructor.cpp \
						Portal/Protocols/TCPOptionMaxSegSizePortal.cpp \
						Portal/Protocols/TCPOptionTimestampConstructor.cpp \
						Portal/Protocols/TCPOptionTimestampPortal.cpp \
						Portal/Protocols/TCPOptionWindowScaleConstructor.cpp \
						Portal/Protocols/TCPOptionWindowScalePortal.cpp \
						Portal/Protocols/TCPOptionMPTCPConstructor.cpp \
						Portal/Protocols/TCPOptionMPTCPPortal.cpp \
						Portal/Protocols/ICMPConstructor.cpp \
						Portal/Protocols/ICMPPortal.cpp \
						Portal/Protocols/ICMPExtensionConstructor.cpp \
						Portal/Protocols/ICMPExtensionPortal.cpp \
						Portal/Protocols/ICMPExtensionMPLSConstructor.cpp \
						Portal/Protocols/ICMPExtensionMPLSPortal.cpp \
						Portal/Protocols/ICMPExtensionObjectConstructor.cpp \
						Portal/Protocols/ICMPExtensionObjectPortal.cpp \
						Portal/Protocols/DNSConstructor.cpp \
						Portal/Protocols/DNSPortal.cpp \
						Portal/Protocols/DNSQuery.cpp \
						Portal/Protocols/DNSAnswer.cpp \
						Portal/Protocols/DHCPConstructor.cpp \
						Portal/Protocols/DHCPPortal.cpp \
						Portal/Protocols/DHCPOptions.cpp \
						Portal/Protocols/SLLConstructor.cpp \
						Portal/Protocols/SLLPortal.cpp \
						Portal/Protocols/IPv6Constructor.cpp \
						Portal/Protocols/IPv6Portal.cpp \
						Portal/Protocols/IPv6FragmentationHeaderPortal.cpp \
						Portal/Protocols/IPv6FragmentationHeaderConstructor.cpp \
						Portal/Protocols/IPv6RoutingHeaderPortal.cpp \
						Portal/Protocols/IPv6RoutingHeaderConstructor.cpp \
						Portal/Protocols/IPv6SegmentRoutingHeaderPortal.cpp \
						Portal/Protocols/IPv6SegmentRoutingHeaderConstructor.cpp \
						Portal/Protocols/IPv6MobileRoutingHeaderPortal.cpp \
						Portal/Protocols/IPv6MobileRoutingHeaderConstructor.cpp \
						Portal/Protocols/IPLayer.cpp \
						Portal/Protocols/NullLoopbackConstructor.cpp \
						Portal/Protocols/NullLoopbackPortal.cpp \
						Portal/Protocols/ICMPv6LayerConstructor.cpp \
						Portal/Protocols/ICMPv6LayerPortal.cpp \
						Portal/Protocols/ICMPv6Constructor.cpp \
						Portal/Protocols/ICMPv6Portal.cpp \
						Portal/Protocols/ICMPLayer.cpp

## Instruct libtool to include ABI version information in the generated shared
## library file (.so).  The library ABI version is defined in configure.ac, so
## that all version information is kept in one place.
libPortal_la_LDFLAGS = -version-info $(Portal_SO_VERSION)
libPortal_la_LIBADD = $(PCAPLIB) $(LNETLIB)

## Define the list of public header files and their install location.  The
## nobase_ prefix instructs Automake to not strip the directory part from each
## filename, in order to avoid the need to define separate file lists for each
## installation directory.  This only works if the directory hierarchy in the
## source tree matches the hierarchy at the install location, however.
Portal_includedir = $(includedir)
nobase_Portal_include_HEADERS =Portal.h \
								Portal/Portal.h \
								Portal/Layer.h \
								Portal/Payload.h \
								Portal/Packet.h \
								Portal/Types.h \
								Portal/InitPortal.h \
								Portal/Fields/BitsField.h \
								Portal/Fields/BytesField.h \
								Portal/Fields/FieldContainer.h \
								Portal/Fields/Field.h \
								Portal/Fields/FieldInfo.h \
								Portal/Fields/IPAddress.h \
								Portal/Fields/IPv6Address.h \
								Portal/Fields/MACAddress.h \
								Portal/Fields/NumericFields.h \
								Portal/Fields/StringField.h \
								Portal/Utils/BitHandling.h \
								Portal/Utils/IPResolver.h \
								Portal/Utils/IPv4Parse.h \
								Portal/Utils/PrintMessage.h \
								Portal/Utils/RawSocket.h \
								Portal/Utils/PortalUtils.h \
								Portal/Utils/PacketContainer.h \
								Portal/Utils/ARPPing.h \
								Portal/Utils/ARPSpoofing.h \
								Portal/Utils/Sniffer.h \
								Portal/Utils/TCPConnection.h \
								Portal/Protocols/RawLayer.h \
								Portal/Protocols/Ethernet.h \
								Portal/Protocols/Dot1Q.h \
								Portal/Protocols/ARP.h \
								Portal/Protocols/IP.h \
								Portal/Protocols/IPOption.h \
								Portal/Protocols/IPOptionLayer.h \
								Portal/Protocols/IPOptionPad.h \
								Portal/Protocols/IPOptionTraceroute.h \
								Portal/Protocols/IPOptionPointer.h \
								Portal/Protocols/UDP.h \
								Portal/Protocols/TCP.h \
								Portal/Protocols/TCPOption.h \
								Portal/Protocols/TCPOptionLayer.h \
								Portal/Protocols/TCPOptionPad.h \
								Portal/Protocols/TCPOptionMaxSegSize.h \
								Portal/Protocols/TCPOptionMPTCP.h \
								Portal/Protocols/TCPOptionTimestamp.h \
								Portal/Protocols/TCPOptionWindowScale.h \
								Portal/Protocols/ICMP.h \
								Portal/Protocols/ICMPExtension.h \
								Portal/Protocols/ICMPExtensionMPLS.h \
								Portal/Protocols/ICMPExtensionObject.h \
								Portal/Protocols/DNS.h \
								Portal/Protocols/DHCP.h \
								Portal/Protocols/DHCPOptions.h \
								Portal/Protocols/SLL.h \
								Portal/Protocols/IPv6.h \
								Portal/Protocols/IPv6FragmentationHeader.h \
								Portal/Protocols/IPv6RoutingHeader.h \
								Portal/Protocols/IPv6SegmentRoutingHeader.h \
								Portal/Protocols/IPv6MobileRoutingHeader.h \
								Portal/Protocols/IPLayer.h \
								Portal/Protocols/NullLoopback.h \
						        Portal/Protocols/ICMPv6Layer.h \
						        Portal/Protocols/ICMPv6.h \
						        Portal/Protocols/ICMPLayer.h

Portal_libincludedir = $(libdir)/Portal-$(Portal_API_VERSION)/include
nodist_Portal_libinclude_HEADERS = Portalconfig.h

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = Portal.pc

AM_CPPFLAGS = $(PCAPINC)
AM_CXXFLAGS = -ansi -pedantic -Wall

dist_noinst_SCRIPTS = autogen.sh
