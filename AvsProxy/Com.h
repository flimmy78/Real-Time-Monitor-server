#ifndef __AVS_PROXY_COM__
#define __AVS_PROXY_COM__

#include <event.h>
#include <memory>
#include <pjlib.h>
#include <pjmedia.h>
#include "command.h"

typedef uint32_t room_id_t;

#define MAX_STORAGE_SIZE           1024
#define MAX_TRANSMISSION_UNIT_SIZE 1500
#define IP_HEADER_SIZE             20
#define UDP_HEADER_SIZE            8
#define MAX_UDP_DATA_SIZE (MAX_TRANSMISSION_UNIT_SIZE - IP_HEADER_SIZE - UDP_HEADER_SIZE)

#define RETURN_VAL_IF_FAIL(_macro_exp_, _macro_ret_) do { \
	if ( !(_macro_exp_) ) return (_macro_ret_); \
} while(0)

#define RETURN_IF_FAIL(_macro_exp_) do { \
	if ( !(_macro_exp_) ) return; \
} while(0)

class Noncopyable
{
public:
	Noncopyable() {}

private:
	Noncopyable(const Noncopyable &) {}
	Noncopyable &operator=(const Noncopyable &) {}
};

pj_status_t pj_open_tcp_serverport(pj_str_t *ip, pj_uint16_t port, pj_sock_t &sock);
pj_status_t pj_open_udp_transport(pj_str_t *ip, pj_uint16_t port, pj_sock_t &sock);

/**
 * Convert 64-bit value from network byte order to host byte order.
 *
 * @param netlonglong   64-bit network value.
 * @return	            64-bit host value.
 */
pj_uint64_t pj_ntohll(pj_uint64_t netlonglong);

/**
 * Convert 64-bit value from host byte order to network byte order.
 *
 * @param hostlonglong  64-bit host value.
 * @return	            64-bit network value.
 */
pj_uint64_t pj_htonll(pj_uint64_t hostlonglong);

#endif
