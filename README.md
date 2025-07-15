
# C++ Contest Template Generator CLI

A lightweight command-line tool written in C++17 that generates skeletal contest
source files tailored for Codeforces or AtCoder. It lets you toggle debug
macros, mathematics helpers, and graph utilities on demand.

## Build

```bash
make      # requires g++
```

## Usage

```bash
./gen_template <output.cpp> [--platform <cf|atcoder>] [--debug|--no-debug] [--math|--no-math] [--graph|--no-graph]
```

Flags default to `--platform cf`, `--no-debug`, `--no-math`, `--no-graph`.

Examples:

```bash
# Minimal Codeforces template
./gen_template mysol.cpp

# AtCoder template with maths and debugging
./gen_template a.cpp --platform atcoder --debug --math

# Codeforces template with graph helpers only
./gen_template g.cpp --graph
```
