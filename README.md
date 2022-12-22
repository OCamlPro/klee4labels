# Klee for labels

## Installation

### Using Docker

If you have docker, you can simply build the tool with:
```sh
$ docker build . --tag klee4labels
```

Then, run the docker image with:
```sh
$ xhost +; docker run -it --rm -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix klee4labels; xhost -
```

(Commands `xhost` and arguments `-e DISPLAY...` and `-v ...` enable
programs launched within the docker container to use the X11 display.)

Once in the shell, the tool can be run on test files included in the
source tree with
```sh
$ klee4labels path/to/file.c
```

### Manual Installation

You need the OCaml packet manager `opam` version >= 2.
Then, you can install the package with
```sh
$ opam init
$ opam install .
```

#### Additional dependencies
##### Klee
You need llvm & klee installed on your device. We recommend using
Klee version 3.0 (build revision 667ce0f1ef33c32fbe2d1836fc1b334066e244ca) and
LLVM v12.0.0.

##### Matplotlib
Statistics of each analysis can be printed as charts.
You can install it with `pip`.

```sh
$ pip install -U matplotlib
```

## Usage

### Running the tool

The tool performs three analyses as per the paper:
- the ignore version, where the program is given as is, without any
  treatment on the coverage labels;
- the naive version, where each coverage label is replaced with an
  empty conditional branch;
- the optimized version.

It will save the analysis results within the `_results` directory.  Once
installed with opam, you may just call:

```sh
$ klee4labels test/power/WM.c
```


```
klee4labels FILE [OPTIONS]

  --debug Activates debug messages.
  --timeout Sets klee timeout (default: 10). 0 means no timeout.
  --bfs-search Uses the bfs search mode for klee. If this mode is set with a klee timeout, labels will be set as covered if they are coverable but may not be associated to actual tests.
```

### Showing Statistics

If you have the `matplotlib` library installed, you can display a comparative chart with

```sh
$ python _result/PROJECT_NAME/graph.py
```

Once you have started the analysis on several files, you can wrap up all the results into one single chart with

```sh
$ merge_graph
```

This will create a `_result/global_chart.py` that you can display with

```sh
$ python _result/global_chart.py
```
