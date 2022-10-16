set ( CMAKE_CXX_STANDARD 11 )
SET ( TARGET message_book )
SET ( SRCS main.cpp message.cpp )

ADD_EXECUTABLE( ${TARGET} ${SRCS} )