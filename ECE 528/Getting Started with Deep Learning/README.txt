----- Docker ---------
docker build -t tensorflow-jupyter .
docker run --rm --network host -v "$(pwd)":/tf/notebooks -d tensorflow-jupyter bash -c "jupyter notebook --NotebookApp.token='' --NotebookApp.password='' --allow-root --no-browser --ip=192.168.1.91 --port=8888"

----- Additional Docker commands --------
docker ps
docker stop <container_id>
docker start <container_id>