#ifndef __AVS_PROXY_CONFIG__
#define __AVS_PROXY_CONFIG__

#include <vector>

#include "Com.h"

using std::vector;

typedef struct
{
	pj_str_t ip;
	pj_uint16_t port;
	pj_uint32_t avs_id;
} avs_config_t;

class Config
{
public:
	pj_str_t config_file_name;
	pj_uint16_t proxy_id;
	pj_str_t local_ip;
	pj_uint16_t local_tcp_port;
	pj_uint16_t local_udp_port;
	pj_uint8_t  thread_cnt;
	vector<avs_config_t *> avs;
};

#endif
