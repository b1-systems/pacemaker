/*
 * Copyright (C) 2004 Andrew Beekhof <andrew@beekhof.net>
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef CRM_AIS__H
#define CRM_AIS__H

#include <crm/crm.h>
#include <glib.h>
#include <string.h>
#include <openais/ais_util.h>
#include <openais/ipc_gen.h>
#include <openais/saAis.h>
#include <crm/ais_common.h>

extern enum crm_ais_msg_types text2msg_type(const char *text);

extern gboolean send_ais_message(
    crm_data_t *msg, gboolean local,
    const char *node, enum crm_ais_msg_types dest);

extern gboolean send_ais_text(
    int type, const char *data, gboolean local,
    const char *node, enum crm_ais_msg_types dest);

extern gboolean init_ais_connection(
    gboolean (*dispatch)(int, gpointer),
    void (*ais_destroy)(gpointer));

extern void terminate_ais_connection(void);

extern int ais_fd_in;
extern int ais_fd_out;
extern GFDSource *ais_source;
extern enum crm_ais_msg_types crm_system_type;

extern char *get_ais_data(AIS_Message *msg);

#endif
