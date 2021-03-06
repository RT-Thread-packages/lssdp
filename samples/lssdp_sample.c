/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: MIT License
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-05-11     SummerGift   first version
 */

#include <stdio.h>
#include <string.h>
#include "lssdp_service.h"

#define DBG_SECTION_NAME  "lssdp example"
#define DBG_LEVEL         DBG_INFO
#include <rtdbg.h>

// lssdp service add example
static int lssdp_add_example(void)
{
    struct lssdp_service service =
    {
        .name                        = "service name",                  // local service name
        .info.search_target          = "urn:rt-thread:service:ssdp",    // search name in network
        .info.unique_service_name    = "unique service name",           // unique service name
        .info.sm_id                  = "700000123",                     // device id
        .info.device_type            = "RT-Thread device",              // device type
        .info.suffix                 = ":5555",                         // service port
    };

    if (lssdp_service_add(&service) != 0)
    {
        LOG_E("service %s add failed!", service.name);
    }

    return RT_EOK;
}
MSH_CMD_EXPORT(lssdp_add_example, lssdp add service example);

// lssdp service del example
static int lssdp_del_example(void)
{
    struct lssdp_service service = {
        .name = "service name",
    };

    lssdp_service_del(&service);

    return RT_EOK;
}
MSH_CMD_EXPORT(lssdp_del_example, lssdp del service example);
