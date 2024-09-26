----- Docker ---------
docker build -t ece528_a2:latest .
docker run --rm --network host --gpus all -v "$(pwd)":/tf/notebooks --name ece528_a2 -d ece528_a2:latest bash -c "jupyter notebook --NotebookApp.token='' --NotebookApp.password='' --allow-root --no-browser --ip=192.168.1.91 --port=8888"
