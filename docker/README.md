# Building and running:

1. Create a network for containers to speak over:
```sh
$ docker network create nc-net
```

2. Build image:
```sh
$ docker build -t nc-test .
```

3. Make scripts executable:
```sh
$ chmod a+x nc-clt.sh nc-srv.sh
```

4. Bring-up __named__ server container:
```sh
$ docker run -it --name nc-server --network nc-net -v "$(pwd)":/app nc-test ./nc-srv.sh
```
Arguments:
`-it` -> request interactive tty;
`--name` -> make container named so it can be resolved via nc-net internal DNS
`--network` -> attach to nc-net network (bridge type)
`-v` -> bind-mount the current working directory (scripts must be placed there)
`nc-test` -> docker image to use
`./nc-srv.sh` -> what to execute on attach

5. Bring up __named__ client container:
```sh
$ docker run -it --name nc-server --network nc-net -v "$(pwd)":/app nc-test ./nc-clt.sh
```

Et voila! You can type text into each of the containers env and see it appear in other, like a chat.

Troubleshooting:

1. Execute same docker run command, but with `bash` instead of `nc-clt.sh` / `nc-srv.sh`
2. Run `ping nc-client` or `ping nc-server`, since containers are named, the IPs will be resolved by internal DNS.
3. If ping fails - verify your network on both containers: `ip a` and compare against output of `docker network inspect
   nc-net`. Check whether both containers are mentioned in nc-net inspection output and whether IP addresses match.
