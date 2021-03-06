/*
Copyright (C) 2014 Eaton

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

/*! \file   assetcr.h
    \brief  Basic create functions for assets
    \author Alena Chernikava <AlenaChernikava@eaton.com>
*/

#ifndef SRC_DB_ASSETS_ASSETCR_H_
#define SRC_DB_ASSETS_ASSETCR_H_

#include <tntdb/connect.h>

#include "dbtypes.h"
#include "db/dbhelpers.h"

#include "db/assetdef.h"

namespace persist {

db_reply_t
    insert_into_asset_ext_attribute
        (tntdb::Connection &conn,
         const char   *value,
         const char   *keytag,
         a_elmnt_id_t  asset_element_id,
         bool          read_only);


db_reply_t
    insert_into_asset_ext_attributes
        (tntdb::Connection &conn,
         zhash_t      *attributes,
         a_elmnt_id_t  asset_element_id,
         bool          read_only);

/**
 *  \brief Multi value insert for extended attributes
 *
 *  \param[in]  conn - database connection
 *  \param[in]  element_id - asset element id
 *  \param[in]  attributes - zhash_t of attributes
 *  \param[in]  read_only - set if attribute is read only or not
 *  \param[out] err       - error message in case of errors
 */
int
    insert_into_asset_ext_attributes
        (tntdb::Connection &conn,
         a_elmnt_id_t element_id,
         zhash_t* attributes,
         bool read_only,
         std::string &err);


db_reply_t
    insert_asset_element_into_asset_group
        (tntdb::Connection &conn,
         a_elmnt_id_t group_id,
         a_elmnt_id_t asset_element_id);


db_reply_t
    insert_into_asset_link
        (tntdb::Connection &conn,
         a_elmnt_id_t    asset_element_src_id,
         a_elmnt_id_t    asset_element_dest_id,
         a_lnk_tp_id_t   link_type_id,
         const a_lnk_src_out_t src_out,
         const a_lnk_dest_in_t dest_in);


db_reply_t
    insert_into_asset_element
        (tntdb::Connection &conn,
         const char      *element_name,
         a_elmnt_tp_id_t  element_type_id,
         a_elmnt_id_t     parent_id,
         const char      *status,
         a_elmnt_pr_t     priority,
         a_dvc_tp_id_t    subtype_id,
         const char      *asset_tag,
         bool update);

db_reply_t
    insert_into_asset_links
        (tntdb::Connection       &conn,
         std::vector <link_t> const &links);


db_reply_t
    insert_element_into_groups
        (tntdb::Connection &conn,
         std::set <a_elmnt_id_t> const &groups,
         a_elmnt_id_t                   asset_element_id);


db_reply_t
    insert_into_monitor_asset_relation
        (tntdb::Connection &conn,
         m_dvc_id_t   monitor_id,
         a_elmnt_id_t element_id);

db_reply_t
    insert_into_monitor_device
        (tntdb::Connection &conn,
         m_dvc_tp_id_t device_type_id,
         const char* device_name);

} // end namespace

#endif // SRC_DB_ASSETS_ASSETCR_H_
