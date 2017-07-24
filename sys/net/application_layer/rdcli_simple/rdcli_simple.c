/*
 * Copyright (C) 2017 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     net_rdcli_simple
 * @{
 *
 * @file
 * @brief       Simplified CoAP resource directory client implementation
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 *
 * @}
 */

#include <string.h>

#include "fmt.h"
#include "net/gcoap.h"
#include "net/rdcli_config.h"
#include "net/rdcli_common.h"
#include "net/rdcli_simple.h"

#define ENABLE_DEBUG    (0)
#include "debug.h"

#define BUFSIZE             (128U)      /* @todo adjust to reasonable size */

static coap_pkt_t pkt;
static uint8_t buf[BUFSIZE];

/* allocate an UDP endpoint to the RD server */
static const sock_udp_ep_t remote = {
    .family    = AF_INET6,
    .netif     = SOCK_ADDR_ANY_NETIF,
    .addr      = RDCLI_SERVER_ADDR ,
    .port      = RDCLI_SERVER_PORT
};

int rdcli_simple_register(void)
{
    char lt[11];

    /* build the initial CON packet */
    int res = gcoap_req_init(&pkt, buf, sizeof(buf), COAP_METHOD_POST,
                             "/.well-known/core");
    if (res < 0) {
        return res;
    }
    coap_hdr_set_type(pkt.hdr, COAP_TYPE_CON);


    /* extend the url with some query string options */
    res = gcoap_add_qstring(&pkt, "ep", rdcli_common_get_ep());
    if (res < 0) {
        return res;
    }
    size_t pos = fmt_u32_dec(lt, RDCLI_LT);
    lt[pos] = '\0';
    res = gcoap_add_qstring(&pkt, "lt", lt);
    if (res < 0) {
        return res;
    }

    /* finish, we don't have any payload */
    ssize_t len = gcoap_finish(&pkt, 0, COAP_FORMAT_TEXT);
    return (int)gcoap_req_send2(buf, len, &remote, NULL);
}
