# source files
#   - main.cpp
#   - Game.cpp
#   - Game.hpp
#   - TextureManager.cpp
#   - TextureManager.hpp
#   - GameObject.cpp
#   - GameObject.hpp
initial_src = [
    'main.cpp',
    'Game.cpp',
    'Game.hpp',
    'GameObject.cpp',
    'GameObject.hpp',
    'TextureManager.cpp',
    'TextureManager.hpp'
]

# include and link dirs
lucerne_include_dirs = []
lucerne_link_dirs = []

# including utils
subdir('utils')

# final source list
src = []

# for each source file, add the path
foreach src_file : initial_src
    # the 'src/' folder, so that meson would
    # properly call the source file
    src += 'src/' + src_file
endforeach
