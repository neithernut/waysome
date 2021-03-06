/*
 * waysome - wayland based window manager
 *
 * Copyright in alphabetical order:
 *
 * Copyright (C) 2014-2015 Julian Ganz
 * Copyright (C) 2014-2015 Manuel Messner
 * Copyright (C) 2014-2015 Marcel Müller
 * Copyright (C) 2014-2015 Matthias Beyer
 * Copyright (C) 2014-2015 Nadja Sommerfeld
 *
 * This file is part of waysome.
 *
 * waysome is free software: you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation, either version 2.1 of the License, or (at your option)
 * any later version.
 *
 * waysome is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with waysome. If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @addtogroup compositor "Compositor"
 *
 * @{
 */

/**
 * @addtogroup compositor_wayland "Compositor wayland"
 *
 * @{
 */

#ifndef __WS_WL_SHELL_SURFACE_H__
#define __WS_WL_SHELL_SURFACE_H__

#include "compositor/wayland/abstract_shell_surface.h"
#include "objects/wayland_obj.h"

/**
 * Waysome's implementation of wl_surface
 *
 * This struct represents a surface
 *
 * @extends ws_wayland_obj
 */
struct ws_shell_surface {
    struct ws_abstract_shell_surface shell; //!< @public: The shell members
};

/**
 * Variable which holds type information about the wl_surface type
 */
extern ws_object_type_id WS_OBJECT_TYPE_ID_SHELL_SURFACE;

/**
 * Create a new surface
 *
 * @memberof ws_shell_surface
 *
 * create a new surface without any bufers attached to it
 */
struct ws_shell_surface*
ws_shell_surface_new(
    struct wl_client* client, //!< client requesting the surface creation
    struct ws_surface* surface, //!< surface to attach
    uint32_t serial //!< id of the newly created surface
);

/**
 * Set the position of a ws_shell_surface
 *
 * @memberof ws_shell_surface
 *
 * @return zero on success, else negative errno.h number
 */
int
ws_shell_surface_set_pos(
    struct wl_resource* resource,
    int32_t x,
    int32_t y
);

#endif // __WS_WL_SHELL_SURFACE_H__

/**
 * @}
 */

/**
 * @}
 */

