# Start with a base image that includes Python 3.9
FROM python:3.9-slim

# Set environment variables to avoid Python buffering issues
ENV PYTHONUNBUFFERED=1

# Install necessary system dependencies for TensorFlow
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    libssl-dev \
    libffi-dev \
    libhdf5-dev \
    wget \
    && rm -rf /var/lib/apt/lists/*

# Install Jupyter and other required Python libraries
RUN pip install --upgrade pip && \
    pip install \
    jupyterlab \
    pandas \
    seaborn \
    tensorflow==2.15.0 \
    keras

# Create a directory for the Jupyter notebooks
WORKDIR /workspace

# Expose the port Jupyter will run on
EXPOSE 8888

# Start Jupyter Notebook
CMD ["bash", "-c", "jupyter notebook --NotebookApp.token='' --NotebookApp.password='' --allow-root --no-browser --ip=0.0.0.0 --port=8888"]
