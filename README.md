# cv

```
$ conda env create -f environment.yaml 
```

## testenv

```
$ conda activate cv
$ cd testenv
$ mkdir build
$ cd build
$ cmake ../
$ make all
$ ./bin/testenv
...
...
$ mkdir glogs
$ ./bin/main
```
