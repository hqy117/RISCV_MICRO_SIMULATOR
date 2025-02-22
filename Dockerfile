FROM ubuntu:22.04

# Avoid interactive prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Install dependencies including linux-tools-generic for perf
RUN apt-get update && apt-get install -y \
    build-essential \
    libssl-dev \
    libsdl1.2-dev \
    libcurl4-openssl-dev \
    wget \
    xz-utils \
    git \
    vim \
    nano \
    linux-tools-generic

# Create working directory
WORKDIR /marss-riscv

# Clone MARSS-RISCV repository
RUN git clone https://github.com/bucaps/marss-riscv .

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