


=================== GOALS =======================
CUDA Toolkit 12.2
GPU driver
cuDNN 8.9
Docker https://www.tensorflow.org/install/docker
-> tensorflow - 2.15.0-gpu-jupyter
-> karas
-> python
================================================
------------------ Driver ----------------------
sudo add-apt-repository ppa:graphics-drivers/ppa
sudo apt update
sudo apt install nvidia-driver-535
sudo reboot
nvidia-smi
------------------------------------------------
---------------- CUDA Toolkit 12.2 -------------
wget https://developer.download.nvidia.com/compute/cuda/repos/ubuntu2004/x86_64/cuda-ubuntu2004.pin 
sudo mv cuda-ubuntu2004.pin /etc/apt/preferences.d/cuda-repository-pin-600
wget https://developer.download.nvidia.com/compute/cuda/12.2.0/local_installers/cuda-repo-ubuntu2004-12-2-local_12.2.0-535.54.03-1_amd64.deb
sudo dpkg -i cuda-repo-ubuntu2004-12-2-local_12.2.0-535.54.03-1_amd64.deb
sudo cp /var/cuda-repo-ubuntu2004-12-2-local/cuda-*-keyring.gpg /usr/share/keyrings/
sudo apt-get update
sudo apt-get -y install cuda-toolkit-12-2
sudo apt-get install -y cuda-drivers


#disable gui
sudo systemctl set-default multi-user.target

# Put these in the ~/.bashrc and make sure to source it
export PATH=/usr/local/cuda-12.2/bin${PATH:+:${PATH}}
export LD_LIBRARY_PATH=/usr/local/cuda-12.2/lib64${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}

------------------------------------------------
---------------- cuDNN 8.9 ---------------------
#### Install ####
# On personal machine
Download cudnn 8.9.4 from https://developer.nvidia.com/rdp/cudnn-download
scp cudnn-linux-x86_64-8.9.4.25_cuda12-archive.tar.xz ndkopacz@192.168.1.91:/home/ndkopacz/

# On server
tar -xf cudnn-linux-x86_64-8.9.4.25_cuda12-archive.tar.xz 
sudo cp cudnn-linux-x86_64-8.9.4.25_cuda12-archive/include/cudnn*.h /usr/local/cuda/include/
cp -P cudnn-linux-x86_64-8.9.4.25_cuda12-archive/lib/libcudnn* /usr/local/cuda/lib64/
sudo chmod a+r /usr/local/cuda/include/cudnn*.h /usr/local/cuda/lib64/libcudnn*

#### Check Install ####
# On personal Machine 
download "Local installer for Ubuntu20.04 x86_64 (Deb)" from https://developer.nvidia.com/rdp/cudnn-download
scp cudnn-local-repo-ubuntu2004-8.9.4.25_1.0-1_amd64.deb ndkopacz@192.168.1.91:/home/ndkopacz/

# On Server
cd /home/ndkopacz/
sudo apt install libfreeimage3 libfreeimage-dev
ls -l #To verify the .deb file is available
mkdir deb
mv cudnn-local-repo-ubuntu2004-8.9.4.25_1.0-1_amd64.deb deb/
cd deb
ar x cudnn-local-repo-ubuntu2004-8.9.4.25_1.0-1_amd64.deb
ls -l # Verify that a new data.tar.xz is available
tar -xf data.tar.xz
cd var/cudnn-local-repo-ubuntu2004-8.9.4.25/
ar x libcudnn8-samples_8.9.4.25-1+cuda12.2_amd64.deb
tar -xf data.tar.xz 
cd usr/src/cudnn_samples_v8/
cd mnistCUDNN
make clean
make # if this returns compilation errors use ./mnistCUDNN instead
---------------------------------------------------

IT DOESN"T FUCKING WORK

sudo apt-get update
sudo apt-get install -y nvidia-container-toolkit
sudo systemctl restart docker

Okay it works now

-------------------NVM IT DOESN"T-------------------------------
failed call to cuInit: CUDA_ERROR_COMPAT_NOT_SUPPORTED_ON_DEVICE: forward compatibility was attempted on non supported HW
...
libcuda reported version is: 545.23.6
kernel reported version is: 535.183.1
...
kernel version 535.183.1 does not match DSO version 545.23.6 -- cannot find working devices in this configuration

// -> This error means a mismatch of nvidia drivers. I have 535 and it wants 545
# Remove all existing NVIDIA drivers to prevent conflicts
sudo apt-get purge nvidia-*

# Broken Installs
sudo dpkg --force-all -P nvidia-firmware-535-535.54.03 nvidia-kernel-common-535 nvidia-compute-utils-535
sudo apt --fix-broken install


sudo apt update
sudo apt install nvidia-driver-545
sudo reboot

--------------- Mother fucker that moved me to cuda 12.3 -------------------------------
# Please work
sudo apt-get -y install cuda-toolkit-12-2


----- Current State -------
##############################
# nvidia-smi
NVIDIA-SMI 560.35.03              Driver Version: 560.35.03      CUDA Version: 12.6

cuDNN 8.9.4 (probably)

#nvcc --version
Cuda compilation tools, release 12.2, V12.2.14

# dpkg -l | grep -i nvidia-container-toolkit
ii  nvidia-container-toolkit              1.16.1-1                          amd64        NVIDIA Container toolkit
ii  nvidia-container-toolkit-base         1.16.1-1                          amd64        NVIDIA Container Toolkit Base

################################
# Running the docker container (From "/home/ndkopacz/code/student_projects/ECE 528/Getting Started with Deep Learning")
docker build -t testing1_container:latest -f Dockerfile1 .
docker run --rm --network host --gpus all -v "$(pwd)":/tf/notebooks --name testing1 -d testing1_container:latest bash -c "jupyter notebook --NotebookApp.token='' --NotebookApp.password='' --allow-root --no-browser --ip=192.168.1.91 --port=8888"


# TensorFlow base image 2.15.0-gpu-jupyter
-> nvidia-smi returns same values
-> nvcc returns V12.3.103 (WRONG!? should be 12.2 right?)
-> When running 01-keras-mnist-baseline.ipynb we are getting errors
  -> E external/local_xla/xla/stream_executor/cuda/cuda_dnn.cc:9261] Unable to register cuDNN factory: Attempting to register factory for plugin cuDNN when one has already been registered
    -> Multiple installations or versions of CUDA libraries cuDNN?
  -> 2024-09-23 15:13:17.825576: I external/local_xla/xla/stream_executor/cuda/cuda_executor.cc:901] successful NUMA node read from SysFS had negative value (-1), but there must be at least one NUMA node, so returning NUMA node zero. See more at https://github.com/torvalds/linux/blob/v6.0/Documentation/ABI/testing/sysfs-bus-pci#L344-L355
    -> Unknown Error
################################
