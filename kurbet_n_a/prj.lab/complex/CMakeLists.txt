add_library(complex complex.h complex.cpp)
# Добавление в проект библеотеки complex с заголовочным файлом complex.h и исходниками в complex.cpp
add_executable(test_complex  test_complex.cpp) # complex название исполняемого файла test-complex.cpp - местоположение функции main
# Добавление в проект исполняемого файла (для windows - .exe , для unix-подобных(MacOS/GNULinux/семейство BSD) bin файлы)
target_link_libraries(test_complex complex)
# Подключение библеотеки complex к файлу test-complex
