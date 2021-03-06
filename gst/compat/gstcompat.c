/* GStreamer Lightweight Playback Plugins
 * Copyright (C) 2013-2014 LG Electronics, Inc.
 *     Author : Jeongseok Kim <jeongseok.kim@lge.com>
 *              Wonchul Lee <wonchul86.lee@lge.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <string.h>
#include <gst/gst.h>

#include "gstfcbin.h"
#include "gstfakevdec.h"
#include "gstfakeadec.h"
#include "gststreamiddemux.h"

static gboolean
plugin_init (GstPlugin * plugin)
{
  if (!gst_element_register (plugin, "fakevdec", GST_RANK_PRIMARY,
          GST_TYPE_FAKEVDEC))
    return FALSE;

  if (!gst_element_register (plugin, "fakeadec", GST_RANK_PRIMARY,
          GST_TYPE_FAKEADEC))
    return FALSE;

  if (!gst_element_register (plugin, "fcbin", GST_RANK_PRIMARY,
          GST_TYPE_FC_BIN))
    return FALSE;

  if (!gst_element_register (plugin, "streamiddemux", GST_RANK_PRIMARY,
          gst_streamid_demux_get_type ()))
    return FALSE;

  return TRUE;
}

GST_PLUGIN_DEFINE (GST_VERSION_MAJOR,
    GST_VERSION_MINOR,
    lpcompat,
    "Lightweight Compatiblity Plugin Library",
    plugin_init, PACKAGE_VERSION, "LGPL", PACKAGE_NAME, PACKAGE_BUGREPORT)
