set (CMAKE_CXX_STANDARD 11)
SET ( TARGET sorted_array )
SET ( SRCS main.cpp sorted.cpp )

ADD_EXECUTABLE( ${TARGET} ${SRCS} )