#
# CMakeLists.txt - The sources CMake file
#
# Copyright (c) 2010 Paul Giblock <pgib/at/users.sourceforge.net>
#
# This file is part of Unison - http://unison.sourceforge.net/
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public
# License as published by the Free Software Foundation; either
# version 2 of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public
# License along with this program (see COPYING); if not, write to the
# Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
# Boston, MA 02110-1301 USA.
#

set(UNISON_BUFFER_LENGTH "1024" CACHE STRING
    "Audio buffer length. A work-around until runtime change is supported.")

set(UNISON_SRCS
    Command.cpp
    Commander.cpp
    Node.cpp
    Patch.cpp
    PooledBufferProvider.cpp
    Port.cpp
    PortConnect.cpp
    PortDisconnect.cpp
    Processor.cpp
    SampleBuffer.cpp
    Scheduler.cpp
    SpinLock.cpp
)

set(UNISON_MOC_HEADERS
    Backend.hpp
)

set(UNISON_INCLUDES
    AudioBuffer.hpp
    Backend.hpp
    BackendPort.hpp
    Buffer.hpp
    BufferProvider.hpp
    Command.hpp
    ControlBuffer.hpp
    FastRandom.hpp
    Node.hpp
    Patch.hpp
    Plugin.hpp
    PooledBufferProvider.hpp
    Port.hpp
    ProcessingContext.hpp
    Processor.hpp
    RingBuffer.hpp
    SampleBuffer.hpp
    SpinLock.hpp
    types.hpp
)

qt4_wrap_cpp(UNISON_MOC_SRCS ${UNISON_MOC_HEADERS})

include_directories(.. ${PRG_INCLUDE_DIR} ${PROJECT_SOURCE_DIR})

add_library(unison SHARED ${UNISON_MOC_SRCS} ${UNISON_SRCS})

target_link_libraries(unison
    ${QT_LIBRARIES}
)

install(TARGETS unison LIBRARY
        DESTINATION lib/unison)

install(FILES ${UNISON_INCLUDES}
        DESTINATION include/unison/)

# build the tests
if(COMPILE_TESTS)
  add_subdirectory(tests)
endif(COMPILE_TESTS)

# add the tests
add_test(NAME TestRingBuffer COMMAND tests/TestRingBuffer)

# vim: tw=90 ts=8 sw=2 sts=2 et sta noai
