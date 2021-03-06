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
 * @addtogroup objects "Classes"
 *
 * @{
 */

/**
 * @addtogroup objects_messages "Message classes"
 *
 * @{
 */

#ifndef __WS_OBJECTS_REPLY_H__
#define __WS_OBJECTS_REPLY_H__

#include "objects/message/message.h"


/**
 * Replay message type
 *
 * This is a purely abstract reply message type, from which the value reply and
 * the error reply are derived.
 *
 * @extends ws_message
 */
struct ws_reply {
    struct ws_message m; //!< @protected base class
};

/**
 * Variable which holds the type information about the ws_reply type
 */
extern ws_object_type_id WS_OBJECT_TYPE_ID_REPLY;

#endif // __WS_OBJECTS_REPLY_H__

/**
 * @}
 */

/**
 * @}
 */

