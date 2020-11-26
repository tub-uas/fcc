#!/bin/sh

# Determine if apt-get is available
if [ -n "$(command -v apt-get)" ]; then
# Install dependencies
apt-get update && apt-get install --yes --no-install-recommends \
    git \
    build-essential \
    cmake \
    libssl-dev \
    libasio-dev \
    libtinyxml2-dev \
    openjdk-8-jre-headless
else
    echo -e "The following dependencies need to be installed before installing FastRTPS\n" \
        "git\n" \
        "g++\n" \
        "cmake\n" \
        "libssl-dev\n" \
        "libasio-dev\n" \
        "libtinyxml2-dev\n" \
        "java-8-jre-headless\n"
    read -p "Do you want to continue [y / n]?" -n 1 -r
    if [[ $REPLY =~ ^[Nn]$ ]]; then 
        echo -e "\n"
        exit 0
    fi
fi

# Needed for foonathan_memory repo
export GIT_SSL_NO_VERIFY=1

# Create build directories
mkdir -p build

if [ -d src/fastcdr ]; then
    mkdir -p build/fastcdr
    cd build/fastcdr
    cmake ../../src/fastcdr
    make -j8 install
    cd ../..
fi

if [ -d src/foonathan_memory_vendor ]; then
    mkdir -p build/foonathan_memory_vendor
    cd build/foonathan_memory_vendor
    cmake ../../src/foonathan_memory_vendor -DCMAKE_INSTALL_PREFIX=/usr/local/ -DBUILD_SHARED_LIBS=ON
    make -j8 install
    cd ../..
fi

mkdir -p build/fastrtps
cd build/fastrtps
cmake ../../src/fastrtps
make -j8 install
cd ../..

mkdir -p /usr/local/share/fastrtpsgen/java
cp java/fastrtpsgen.jar /usr/local/share/fastrtpsgen/java
cp java/fastrtpsgen /usr/local/bin/
cp -r doc/ /usr/local/share/fastrtps/
