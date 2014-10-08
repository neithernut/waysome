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

#include <errno.h>

#include "compositor/buffer.h"

ws_buffer_type_id WS_OBJECT_TYPE_ID_BUFFER = {
    .type = {
        .supertype  = &WS_OBJECT_TYPE_ID_OBJECT,
        .typestr    = "ws_buffer",

        .hash_callback = NULL,

        .init_callback = NULL,
        .deinit_callback = NULL,
        .log_callback = NULL,
        .run_callback = NULL,
        .cmp_callback = NULL,
    },
    .get_data = NULL,
    .get_width = NULL,
    .get_height = NULL,
    .get_stride = NULL,
    .get_format = NULL,
    .begin_access = NULL,
    .end_access = NULL,
};

int
ws_buffer_init(
    struct ws_buffer* self
) {
    if (!self) {
        return -EINVAL;
    }

    ws_object_init(&self->obj);
    self->obj.id = &WS_OBJECT_TYPE_ID_BUFFER.type;

    return 0;
}


void*
ws_buffer_data(
    struct ws_buffer* self
) {
    ws_buffer_type_id* type = (ws_buffer_type_id*) &self->obj.id;
    if (!(type && type->get_data)) {
        return NULL;
    }
    return type->get_data(self);
}

int32_t
ws_buffer_width(
    struct ws_buffer* self
) {
    ws_buffer_type_id* type = (ws_buffer_type_id*) &self->obj.id;
    if (!(type && type->get_width)) {
        return 0;
    }
    return type->get_width(self);
}

int32_t
ws_buffer_height(
    struct ws_buffer* self
) {
    ws_buffer_type_id* type = (ws_buffer_type_id*) &self->obj.id;
    if (!(type && type->get_height)) {
        return 0;
    }
    return type->get_height(self);
}

int32_t
ws_buffer_stride(
    struct ws_buffer* self
) {
    ws_buffer_type_id* type = (ws_buffer_type_id*) &self->obj.id;
    if (!(type && type->get_stride)) {
        return 0;
    }
    return type->get_stride(self);
}

uint32_t
ws_buffer_format(
    struct ws_buffer* self
) {
    ws_buffer_type_id* type = (ws_buffer_type_id*) &self->obj.id;
    if (!(type && type->get_format)) {
        return 0;
    }
    return type->get_format(self);
}

