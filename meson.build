# project name: com.github.gauthamkrishna9991.lucerne
# language/type of project: cpp
# version: 0.1
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


# get all source files from src
subdir('src')

# create an executable
# name: lucerne
# source: 
#   src (from 'src' directory), check that later
#   check meson.build file in that directory for more information
# dependencies:
#   - sdl2
#   - libpng16
#   - zlib
#   - sdl2_image
# is it installable?: yes
exe = executable(
  'lucerne',
  src,
  dependencies : [
    sdl2,
    libpng16,
    zlib,  
    sdl2_image
  ],
  install : true
)

test('basic', exe)
