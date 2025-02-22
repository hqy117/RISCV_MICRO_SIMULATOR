FROM fedora:41
# Install dependencies
RUN dnf update -y && dnf install -y \
    gcc gcc-c++ \
    openssl-devel \
    SDL-devel \
    libcurl-devel \
    wget \
    xz \
    git \
    vim \
    nano \
    perf \
    make
# Create working directory
WORKDIR /marss-riscv
# Clone MARSS-RISCV repository
RUN git clone https://github.com/bucaps/marss-riscv .
# Fix the missing header issue in ramulator
RUN sed -i '1i#include <cstdint>' /marss-riscv/src/ramulator/src/StatType.h
# Build the simulator (using XLEN=64)
WORKDIR /marss-riscv/src
RUN make
# Download and extract RISC-V images
WORKDIR /marss-riscv
RUN wget https://cs.binghamton.edu/~marss-riscv/marss-riscv-images.tar.gz && \
    tar -xvzf marss-riscv-images.tar.gz && \
    mkdir -p configs/riscv64-unknown-linux-gnu && \
    cp -r marss-riscv-images/riscv64-unknown-linux-gnu/* configs/riscv64-unknown-linux-gnu/ && \
    cd configs/riscv64-unknown-linux-gnu/ && \
    xz -d -k -T 0 riscv64.img.xz
WORKDIR /marss-riscv/src
