#!/usr/bin/bash

# install admin
echo "This install requires admin (sudo) privileges.";

# install all dependencies
sudo dnf install libpng-devel zlib-devel SDL2_image-devel SDL2-devel -y;

# if the install succeeded:
if [ $? == 0 ]; then
    # install succeeded
    echo "Install Successful.";
else
    # install unsuccessful
    echo "Install Unsuccessful, try installing dependencies from meson.build file.";
fi
