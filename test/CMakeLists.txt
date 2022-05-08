add_executable(bitrot bitrot.c)
target_link_libraries(bitrot utils)

add_executable(byteswap byteswap.c)
target_link_libraries(byteswap utils)

add_executable(byteorder byteorder.c)
target_link_libraries(byteorder utils)

add_executable(sha1 sha1.c)
target_link_libraries(sha1 utils)

add_executable(base64_encode base64_encode.c)
target_link_libraries(base64_encode utils)

add_executable(base64_decode base64_decode.c)
target_link_libraries(base64_decode utils)
