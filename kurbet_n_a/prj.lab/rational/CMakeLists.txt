add_library(rational rational.h rational.cpp)
# Добавление в проект библеотеки rational с заголовочным файлом rational.h и исходниками в rational.cpp
add_executable(test_rational  test_rational.cpp) # test-rational название исполняемого файла test-rational.cpp - местоположение функции main
# Добавление в проект исполняемого файла (для windows - .exe , для unix-подобных(MacOS/GNULinux/семейство BSD) bin файлы)
target_link_libraries(test_rational rational)
# Подключение библеотеки rational к файлу test_rational
