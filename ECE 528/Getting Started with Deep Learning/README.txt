----- Docker ---------
docker build -t tensorflow-jupyter .
docker run -p 8888:8888 -v $(pwd):/tf/notebooks tensorflow-jupyter

----- Additional Docker commands --------
docker ps
docker stop <container_id>
docker start <container_id>