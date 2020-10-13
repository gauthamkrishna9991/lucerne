project('com.github.gauthamkrishna9991.lucerne', 'cpp',
  version : '0.1',
  default_options : [
    'warning_level=3',
    'cpp_std=c++17'
  ]
)

# SDL2 Dependency
sdl2 = dependency('sdl2')
# libpng16 dependency
libpng16 = dependency('libpng16')
# zlib dependency
zlib = dependency('zlib')
# SDL2 image dependency
sdl2_image = dependency('SDL2_image')

exe = executable(
  'lucerne',
  [
    'main.cpp',
    'Game.cpp',
    'Game.hpp'
  ],
  dependencies : [
    sdl2,
    libpng16,
    zlib,  
    sdl2_image
  ],
  install : true)

test('basic', exe)
