# Configure, make, install:

1. Start by configuring the local m4 env:
```sh
aclocal
```

2. Generate a template header for `configure`:
```sh
autoheader
```

3. Create configuration templates:
```sh
autoconf
```

4. Generate makefile based on Makefile.am:
```sh
automake --add-missing # pulls any needed dependencies
```

5. Configure the project build:
```sh
./configure
# can pass:
# --build=x86_64-pc-linux-gnu -> build machine spec.
# --host= -> spec of machine that will run the code, defaults to value of `--build`
# --target= -> target for which executable will generate code, defaults to value of `--host`
# --prefix="$HOME/.local" -> if you don't want to `make install` with `sudo`
```

6. Compile the project:
```sh
make
```

7. Install the executable
```sh
$ sudo make install # or without sudo if PREFIX doesn't require those premissions
```

