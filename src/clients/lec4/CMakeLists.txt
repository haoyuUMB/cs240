add_executable(lec4_array array.c)
add_executable(lec4_char_array character_array.c)
add_executable(lec4_sw switch.c)

aux_source_directory(. ALL)
message(STATUS hello ${ALL})
foreach (file ${ALL})
    message(STATUS ${file})
endforeach ()


