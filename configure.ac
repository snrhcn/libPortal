## LibPortal:

AC_INIT([libPortal], [0.3], [rh.ver0.85@gmail.com], [Portal],
        [http://github.com/snrhcn/libPortal/])
AC_PREREQ([2.59])
AM_INIT_AUTOMAKE([1.10 -Wall no-define])

AC_CONFIG_HEADERS([config.h Portalconfig.h])
AC_PROG_CXX
LT_INIT([disable-static])

AC_CHECK_TYPE(u_int32_t, uint32_t)
AC_CHECK_TYPE(u_int64_t, uint64_t)
AC_CHECK_TYPE(u_int16_t, uint16_t)
AC_CHECK_TYPE(u_int8_t, uint8_t)
AC_CHECK_TYPE(size_t)
AC_CANONICAL_HOST

## Checks for libpcap
AC_MSG_CHECKING(for libpcap)
AC_ARG_WITH(libpcap,
[  --with-libpcap=DIR      use libpcap in DIR],
[ case "$withval" in
  yes|no)
     AC_MSG_RESULT(no)
     ;;
  *)
     AC_MSG_RESULT($withval)
     if test -f $withval/pcap.h -a -f $withval/libpcap.a; then
        owd=`pwd`
        if cd $withval; then withval=`pwd`; cd $owd; fi
	PCAPINC="-I$withval -I$withval/bpf"
	PCAPLIB="-L$withval -lpcap"
     elif test -f $withval/include/pcap.h -a \
	       -f $withval/include/net/bpf.h -a \
	       -f $withval/lib/libpcap.a; then
	owd=`pwd`
	if cd $withval; then withval=`pwd`; cd $owd; fi
	PCAPINC="-I$withval/include"
	PCAPLIB="-L$withval/lib -lpcap"
     else
        AC_ERROR(pcap.h, net/bpf.h, or libpcap.a not found in $withval)
     fi
     ;;
  esac ],
[ if test -f ${prefix}/include/pcap.h; then
     PCAPINC="-I${prefix}/include"
     PCAPLIB="-L${prefix}/lib -lpcap"
  elif test -f /usr/include/pcap/pcap.h; then
     PCAPINC="-I/usr/include/pcap"
     PCAPLIB="-lpcap"
  elif test -f /usr/include/pcap.h; then
     PCAPLIB="-lpcap"
  else
     AC_MSG_RESULT(no)
     AC_ERROR(libpcap not found)
  fi
  AC_MSG_RESULT(yes) ]
)
AC_SUBST(PCAPINC)
AC_SUBST(PCAPLIB)
AC_CHECK_LIB([pcap], [pcap_set_immediate_mode],
      [AC_DEFINE([HAVE_PCAP_SET_IMMEDIATE_MODE], [1],
         [Define to 1 if pcap_set_immediate_mode is defined])])
AC_CHECK_LIB(pthread, pthread_create)
AC_CHECK_LIB(rt,clock_gettime)

case "${host_os}" in
  darwin*)
    AC_CHECK_LIB(resolv,res_9_ns_put16)
    AC_CHECK_LIB(resolv,res_9_ns_name_compress)
    ;;
  *)
    AC_CHECK_LIB(resolv,ns_put16)
    AC_CHECK_LIB(resolv,ns_name_compress)
    ;;
esac

AC_CHECK_FUNCS(ether_aton_r)
AC_CHECK_FUNCS(inet_network)

AC_SUBST([Portal_SO_VERSION], [0:2:0])
AC_SUBST([Portal_API_VERSION], [0.2])

AC_CONFIG_FILES([Makefile
                 Portal.pc:Portal.pc.in])
AC_OUTPUT
