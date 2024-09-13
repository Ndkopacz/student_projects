import tensorflow as tf

def check_gpu_availability():
    gpus = tf.config.list_physical_devices('GPU')
    if gpus:
        return "GPU is available."
    else:
        return "GPU is not available."

if __name__ == "__main__":
    print(tf.__version__)
    result = check_gpu_availability()
    print(result)