/*
 * gtkimcocoa
 * Copyright (C) 2013 Takuro Ashie <ashie@clear-code.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "gtkimcontextcocoa.h"

struct _GtkIMContextCocoaPrivate
{
};

/* GObject class functions */
static void gtk_im_context_cocoa_class_init (GtkIMContextCocoaClass *class);
static void gtk_im_context_cocoa_init       (GtkIMContextCocoa      *context_cocoa);
static void gtk_im_context_cocoa_dispose    (GObject *obj);
static void gtk_im_context_cocoa_finalize   (GObject *obj);

static void gtk_im_context_cocoa_set_property (GObject      *object,
					       guint         prop_id,
					       const GValue *value,
					       GParamSpec   *pspec);
static void gtk_im_context_cocoa_get_property (GObject      *object,
					       guint         prop_id,
					       GValue       *value,
					       GParamSpec   *pspec);

/* GtkIMContext class functions */
static void gtk_im_context_cocoa_set_client_window   (GtkIMContext *context,
						      GdkWindow    *client_window);
static gboolean gtk_im_context_cocoa_filter_keypress (GtkIMContext   *context,
						      GdkEventKey    *event);
static void gtk_im_context_cocoa_reset               (GtkIMContext   *context);
static void gtk_im_context_cocoa_get_preedit_string  (GtkIMContext   *context,
						      gchar         **str,
						      PangoAttrList **attrs,
						      gint           *cursor_pos);
static void gtk_im_context_cocoa_focus_in            (GtkIMContext   *context);
static void gtk_im_context_cocoa_focus_out           (GtkIMContext   *context);
static void gtk_im_context_cocoa_set_cursor_location (GtkIMContext   *context,
						      GdkRectangle   *area);
static void gtk_im_context_cocoa_set_use_preedit     (GtkIMContext   *context,
						      gboolean        use_preedit);

GType gtk_type_im_context_cocoa = 0;
static GObjectClass *parent_class;

void
gtk_im_context_cocoa_register_type (GTypeModule *type_module)
{
  const GTypeInfo im_context_cocoa_info = {
    sizeof (GtkIMContextCocoaClass),
    (GBaseInitFunc) NULL,
    (GBaseFinalizeFunc) NULL,
    (GClassInitFunc) gtk_im_context_cocoa_class_init,
    NULL, /* class_finalize */
    NULL, /* class_data */
    sizeof (GtkIMContextCocoa),
    0,
    (GInstanceInitFunc) gtk_im_context_cocoa_init,
  };

  gtk_type_im_context_cocoa =
    g_type_module_register_type (type_module,
                                 GTK_TYPE_IM_CONTEXT,
                                 "GtkIMContextCocoa", &im_context_cocoa_info, 0);
}

static void
gtk_im_context_cocoa_class_init (GtkIMContextCocoaClass *class)
{
  GtkIMContextClass *im_context_class = GTK_IM_CONTEXT_CLASS (class);
  GObjectClass *gobject_class = G_OBJECT_CLASS (class);

  parent_class = g_type_class_peek_parent (class);

  gobject_class->finalize     = gtk_im_context_cocoa_finalize;
  gobject_class->dispose      = gtk_im_context_cocoa_dispose;
  gobject_class->set_property = gtk_im_context_cocoa_set_property;
  gobject_class->get_property = gtk_im_context_cocoa_get_property;

  im_context_class->set_client_window   = gtk_im_context_cocoa_set_client_window;
  im_context_class->filter_keypress     = gtk_im_context_cocoa_filter_keypress;
  im_context_class->reset               = gtk_im_context_cocoa_reset;
  im_context_class->get_preedit_string  = gtk_im_context_cocoa_get_preedit_string;
  im_context_class->focus_in            = gtk_im_context_cocoa_focus_in;
  im_context_class->focus_out           = gtk_im_context_cocoa_focus_out;
  im_context_class->set_cursor_location = gtk_im_context_cocoa_set_cursor_location;
  im_context_class->set_use_preedit     = gtk_im_context_cocoa_set_use_preedit;
}

static void
gtk_im_context_cocoa_init (GtkIMContextCocoa *context_cocoa)
{
}

static void
gtk_im_context_cocoa_dispose (GObject *obj)
{
  if (G_OBJECT_CLASS (parent_class)->dispose)
    G_OBJECT_CLASS (parent_class)->dispose (obj);
}

static void
gtk_im_context_cocoa_finalize (GObject *obj)
{
  if (G_OBJECT_CLASS (parent_class)->finalize)
    G_OBJECT_CLASS (parent_class)->finalize (obj);
}

static void
gtk_im_context_cocoa_set_property (GObject      *object,
				   guint         prop_id,
				   const GValue *value,
				   GParamSpec   *pspec)
{
}

static void
gtk_im_context_cocoa_get_property (GObject    *object,
				   guint       prop_id,
				   GValue     *value,
				   GParamSpec *pspec)
{
}

GtkIMContext *
gtk_im_context_cocoa_new (void)
{
  return g_object_new (GTK_TYPE_IM_CONTEXT_COCOA, NULL);
}

static void
gtk_im_context_cocoa_set_client_window (GtkIMContext *context,
					GdkWindow    *client_window)
{
}

static gboolean
gtk_im_context_cocoa_filter_keypress (GtkIMContext *context,
				      GdkEventKey  *event)
{
  return FALSE;
}

static void
gtk_im_context_cocoa_reset (GtkIMContext *context)
{
}

static void
gtk_im_context_cocoa_get_preedit_string (GtkIMContext   *context,
					 gchar         **str,
					 PangoAttrList **attrs,
					 gint           *cursor_pos)
{
}

static void
gtk_im_context_cocoa_focus_in (GtkIMContext *context)
{
}

static void
gtk_im_context_cocoa_focus_out (GtkIMContext *context)
{
}

static void
gtk_im_context_cocoa_set_cursor_location (GtkIMContext *context,
					  GdkRectangle *area)
{
}

static void
gtk_im_context_cocoa_set_use_preedit (GtkIMContext *context,
				      gboolean      use_preedit)
{
}