<div align="center"><img src="https://github.com/ksyv/holbertonschool-web_front_end/blob/main/baniere_holberton.png"></div>

---

# 🐚 Simple Shell - README

## 📚 Resources

### 📖 Read or Watch

- Unix shell
- Thompson shell
- Ken Thompson
- Everything you need to know to start coding your own shell (concept page)

### 💡 man or help

- `sh` (Run `sh` as well)

---

## 🎯 Learning Objectives

At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

### 🧠 General

- Who designed and implemented the original Unix operating system
- Who wrote the first version of the UNIX shell
- Who invented the B programming language (the direct predecessor to the C programming language)
- Who is Ken Thompson
- How does a shell work
- What is a pid and a ppid
- How to manipulate the environment of the current process
- What is the difference between a function and a system call
- How to create processes
- What are the three prototypes of `main`
- How does the shell use the `PATH` to find programs
- How to execute another program with the `execve` system call
- How to suspend the execution of a process until one of its children terminates
- What is EOF / "end-of-file"

---

## 📌 Requirements

### ⚙️ General

- Allowed editors: `vi`, `vim`, `emacs`
- All files compiled on Ubuntu 20.04 LTS using gcc
- Compilation options: `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All files should end with a new line
- A `README.md` file is mandatory at the root of the project
- Code must follow the Betty style (checked with `betty-style.pl` and `betty-doc.pl`)
- No memory leaks allowed
- No more than 5 functions per file
- Header files must be include-guarded
- Use system calls only when necessary

### 🧑‍💻 GitHub

- One project repository per group
- Forking or cloning before the deadline may result in a 0% score

---

## 🧾 More Info

### 🖨️ Output

Your shell must have the same output as `/bin/sh` (error messages included), except for the name of the program printed in errors, which must match `argv[0]`.

#### ⚠️ Example of error with sh

```sh
julien@ubuntu:/# echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
```

#### ✅ Same error with your program hsh

```sh
julien@ubuntu:/# echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
```

---

## ✅ List of Allowed Functions and System Calls

- All functions from `string.h`
- `access`, `chdir`, `close`, `closedir`
- `execve`, `exit`, `_exit`, `fflush`, `fork`, `free`
- `getcwd`, `getline`, `getpid`, `isatty`, `kill`, `malloc`
- `open`, `opendir`, `perror`, `printf`, `fprintf`, `vfprintf`
- `sprintf`, `putchar`, `read`, `readdir`, `signal`
- `stat` (__xstat), `lstat` (__lxstat), `fstat` (__fxstat)
- `strtok`, `wait`, `waitpid`, `wait3`, `wait4`, `write`

---

## 🛠️ Compilation

Your shell will be compiled using:

```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

---

## 🧪 Testing

### 🖥️ Interactive Mode

```sh
julien@ubuntu:/# ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
julien@ubuntu:/#
```

### 📤 Non-interactive Mode

```sh
julien@ubuntu:/# echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
```

```sh
julien@ubuntu:/# cat test_ls_2
/bin/ls
/bin/ls
```

```sh
julien@ubuntu:/# cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
```

---

## 🧪 Checks

A checker will be released before the deadline. All students are encouraged to collaborate to build a test suite for normal and edge cases.

After the deadline, you must fork the repo (if it's not on your GitHub account) to be graded.
