project('com.github.gauthamkrishna9991.lucerne', 'cpp',
  version : '0.1',
  default_options : [
    'warning_level=3',
    'cpp_std=c++17'
  ]
)

# SDL2 Dependency
sdl2 = dependency('sdl2')

exe = executable(
  'lucerne',
  [
    'main.cpp',
    'Game.cpp',
    'Game.hpp'
  ],
  dependencies : [
    sdl2
  ],
  install : true)

test('basic', exe)
