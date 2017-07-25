/*
 * Copyright (C) 2017 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @defgroup    net_rdcli_common Shared Functionality for CoAP RD Clients
 * @ingroup     net_rdcli
 * @{
 *
 * @file
 * @brief       Shared CoAP RD client functions
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 */

#ifndef RDCLI_COMMON_H
#define RDCLI_COMMON_H

#include "net/rdcli_config.h"

#ifdef __cplusplus
extern "C" {
#endif

extern char rdcli_ep[];

/**
 * @brief   Generate unique endpoint id (ep)
 */
void rdcli_common_init(void);

/**
 * @brief   Initiate the node registration by sending an empty push
 */
static inline const char *rdcli_common_get_ep(void)
{
    return (const char *)rdcli_ep;
}

#ifdef __cplusplus
}
#endif

#endif /* RDCLI_COMMON_H */
/** @} */
