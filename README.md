# RISCV_SIMULATOR
This repository is for ECE201
# RISC-V Development Environment Setup Guide

## Prerequisites

Before starting, ensure you have:
- A computer with administrative privileges
- Internet connection
- Terminal/Command Prompt access

## Docker Installation

### For Windows:
Soon
### For macOS:
Soon

### For Linux (Ubuntu/Debian):
1. Update package index:
   ```bash
   sudo apt-get update
   ```
2. Install Docker Engine:
   ```bash
   sudo apt-get install docker-ce docker-ce-cli containerd.io
   ```
3. Verify installation:
   ```bash
   sudo docker --version
   ```

## Setting Up RISC-V Development Environment

### Pull the RISC-V Development Image
```bash
docker pull qhou3/riscv-dev
```

### Run the Container
```bash
docker run -it qhou3/riscv-dev
```

To mount a local directory (recommended for persistent work):
```bash
docker run -it -v /path/to/local/directory:/workspace qhou3/riscv-dev
```

### Verifying the Environment
Once inside the container, verify the RISC-V toolchain:
```bash
riscv64-unknown-elf-gcc --version
```

## Example Usage
### Compiling a RISC-V Program
1. Create a simple C program (example.c):
   ```c
   #include <stdio.h>
   
   int main() {
       printf("Hello RISC-V World!\n");
       return 0;
   }
   ```

2. Compile the program:
   ```bash
   riscv64-unknown-elf-gcc example.c -o example 
   ```

3. Run the program:
   ```bash
   spike pk example
   ```

## Troubleshooting

### Common Issues

1. **Docker permission denied**
   ```bash
   sudo usermod -aG docker $USER
   newgrp docker
   ```

2. **Container not starting**
   - Ensure Docker service is running:
   ```bash
   sudo systemctl start docker
   ```

3. **Image pull failed**
   - Check internet connection
   - Try with sudo if on Linux
