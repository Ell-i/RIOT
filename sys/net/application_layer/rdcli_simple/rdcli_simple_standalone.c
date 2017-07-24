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
 * @brief       Standalone extension for the simple RD registration client
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 *
 * @}
 */

#include "log.h"
#include "thread.h"
#include "xtimer.h"
#include "net/rdcli_config.h"
#include "net/rdcli_simple.h"

#define STACKSIZE           (THREAD_STACKSIZE_DEFAULT)
#define PRIO                (THREAD_PRIORITY_MAIN - 1)
#define TNAME               "rdcli_simple"

char stack[STACKSIZE];

static void *reg_runner(void *arg)
{
    (void)arg;

    while (1) {
        int res = rdcli_simple_register();
        if (res < 0) {
            LOG_ERROR("[rdcli_simple] error: unable to trigger registration\n");
        }
        xtimer_usleep(RDCLI_UPDATE_INTERVAL * US_PER_SEC);
    }

    return NULL;    /* should never be reached */
}

void rdcli_simple_run(void)
{
    thread_create(stack, sizeof(stack), PRIO, 0, reg_runner, NULL, TNAME);
}
