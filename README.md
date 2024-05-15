# <div align="center">MiniShell</div>


## Introduction

Minishell is a lightweight Unix-like shell meticulously crafted in C, offering users a fundamental command-line interface. Developed as part of the demanding 42 curriculum.

This project adheres to the stringent requirements and limitations of the 42 norm, which entails a restricted set of allowed library functions and the absence of constructs like 'for' loops. Consequently, we constructed most components from scratch, embracing a low-level approach. Our guiding reference throughout this endeavor was [Bash](https://www.gnu.org/software/bash/).

Minishell was a collaborative effort with a peer, and myself. We collectively tackled the project, ensured a comprehensive understanding of each facet, and conducted knowledge-sharing sessions to enhance our grasp of the intricate workings.

## Key Features

- **Comprehensive Shell Commands:** Minishell boasts support for a wide array of essential shell commands, including `ls`, `cd`, `pwd`, `echo`, and `exit`.

- **Piping and Stream Redirection:** Seamlessly chain commands using pipes (`|`) and manage input and output streams with redirection operators (`>`, `>>`, `<`).

- **Environment and Shell Variables:** Manipulate environment variables like `PATH` and define user-specific variables using `export`, `set`, and `unset`.

- **Inhibitors Handling:** Minishell efficiently deals with inhibitors, both single (`' '`) and double (`" "`) quotation marks.

- **History Management:** The shell diligently records all executed commands, allowing users to navigate command history using arrow keys.

## Getting Started

### Prerequisites

To run Minishell, ensure you have the following prerequisites:

- C compiler (e.g., GCC)
- Unix-like operating system (Linux or macOS)

### Installation

1. Clone the Minishell repository:

```shell
git clone https://github.com/HYYPNNOSS/BashClone.git
```

2. Build the Minishell executable:

 ```
cd BashClone
make
 ```

## Usage

Run Minishell:
```
./minishell
```
You are now ready to explore Minishell's capabilities. Experiment with basic shell commands, piping, and redirection. Minishell is rigorously designed to be robust, free from crashes (e.g., segmentation faults or bus errors), memory leaks, freezes, or infinite loops. If you encounter any such issues, please report them to us promptly.
