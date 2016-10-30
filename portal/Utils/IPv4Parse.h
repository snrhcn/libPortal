#ifndef IPV4PARSE_H_
#define IPV4PARSE_H_

typedef struct ipv4_parse_ctx
{
	unsigned char m_state[4] [256];
	unsigned short m_index[4];

} ipv4_parse_ctx;

/*
 * ipv4_parse_ctx_init()
 *
 *
 */

int ipv4_parse_ctx_init (ipv4_parse_ctx *ctx, char *range);

/*
 * ipv4_parse_next_addr()
 *
 *
 */

int ipv4_parse_next (ipv4_parse_ctx *ctx, unsigned int *addr);

#endif /* IPV4PARSE_H_ */
