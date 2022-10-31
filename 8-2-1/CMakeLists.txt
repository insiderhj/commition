set ( CMAKE_CXX_STANDARD 11 )
SET ( TARGET draw_shape )
SET ( SRCS main.cpp shapes.cpp )

ADD_EXECUTABLE( ${TARGET} ${SRCS} )