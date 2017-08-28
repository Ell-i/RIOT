/*
 * Copyright (C) 2017 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @defgroup    net_rdcli_simple Simple CoAP Resource Directory Registration
 * @ingroup     net_rdcli
 * @{
 *
 * @file
 * @brief       Interface for a simple CoAP RD registration
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 */

#ifndef RDCLI_SIMPLE_H
#define RDCLI_SIMPLE_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Initiate the node registration by sending an empty push
 */
int rdcli_simple_register(void);

/**
 * @brief   Spawn a new thread that registers the node and updates the
 *          registration with all responding RDs using the simple registration
 *          process
 */
void rdcli_simple_run(void);

#ifdef __cplusplus
}
#endif

#endif /* RDCLI_SIMPLE_H */
/** @} */