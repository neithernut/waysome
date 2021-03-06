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

#include "objects/message/message.h"

/*
 *
 * Internal constants
 *
 */


/**
 * Type information for ws_wayland_obj type
 */
ws_object_type_id WS_OBJECT_TYPE_ID_MESSAGE = {
    .supertype  = &WS_OBJECT_TYPE_ID_OBJECT,
    .typestr    = "ws_message",

    .hash_callback = NULL,
    .deinit_callback = NULL,
    .cmp_callback = NULL,
    .uuid_callback = NULL,

    .function_table = NULL,
};

/*
 *
 * Interface implementations
 *
 */

int
ws_message_init(
    struct ws_message* self,
    size_t id
) {
    ws_object_init(&self->obj);
    self->obj.id = &WS_OBJECT_TYPE_ID_MESSAGE;
    self->id = id;

    // what could possibly go wrong?
    return 0;
}

size_t
ws_message_get_id(
    struct ws_message* self
) {
    return self->id;
}
