# File defines
set(sfinder_core_SOURCE_DIR ${sfinder_SOURCE_DIR}/src)

file(GLOB sfinder_core_SRC
        ${sfinder_core_SOURCE_DIR}/*/*.cpp
        ${sfinder_core_SOURCE_DIR}/*/*.hpp
        ${sfinder_core_SOURCE_DIR}/*/*/*.cpp
        ${sfinder_core_SOURCE_DIR}/*/*/*.hpp
        )