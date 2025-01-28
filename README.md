# RISCV_SIMULATOR
This repository is for ECE201
# RISC-V Development Environment Setup Guide
## Prerequisites
Before starting, ensure you have:
- A computer with administrative privileges
- Internet connection
- Terminal/Command Prompt access
## Docker Installation
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
### For macOS:
1. Download Docker Desktop for Mac from [Docker's official Docs](https://docs.docker.com/desktop/setup/install/mac-install/)
2. Double-click the .dmg file
3. Drag Docker to your Applications folder
4. Start Docker from your Applications folder
5. Verify installation by opening Terminal and running:
   ```bash
   docker --version
   ```
### For Windows:
Please refer to [Docker's official Docs](https://docs.docker.com/desktop/setup/install/windows-install/)
## Setting Up RISC-V Development Environment
### Pull the RISC-V Development Image
```bash
docker pull qhou3/riscv-micro
```
### Run the Container
```bash
docker run -it qhou3/riscv-micro
```
To mount a local directory (recommended for persistent work):
```bash
docker run -it -v /path/to/local/directory:/work qhou3/riscv-micro /bin/bash
```
## Basic Usage
### Start the Simulator
Make sure you are under ```/marss-riscv/src``` directory
1. In-order processor
   ```bash
   ./marss-riscv -ctrlc -rw ../configs/riscv64_inorder_soc.cfg
   ```
2. Out-of-order processor
   ```bash
   ./marss-riscv -ctrlc -rw ../configs/riscv64_outoforder_soc.cfg
   ```
3. Once in RISC-V environment, set up: (should be automatically done, manully just in case)
   ```bash
   export PYTHONPATH=/usr/lib64/python2.7/site-packages/
   env-update
   ```

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
   gcc -o example example.c
   ```
3. Run the program:
   ```bash
   ./example
   ```
   The output should be:
   ```bash
   Hello RISC-V World!
   ```
   as well as performance information.
   
### Configuring the Simulator
1. Press ```ctrl+c``` to exit the simulator
2. Go to ```/marss-riscv/configs``` directory
3. Edit the following config files as you wish:
   Either:
   ```bash
   configs/riscv64_inorder_soc.cfg
   ```
   ([View In-Order Configuration File](riscv64_inorder_soc.cfg))
   
   or:
   ```bash
   configs/riscv64_outoforder_soc.cfg
   ```
   ([View Out-of-Order Configuration File](riscv64_outoforder_soc.cfg))
5. [Restart the Simulator](#start-the-simulator)

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
