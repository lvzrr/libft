# LIBFT

An expanded version of 42's traditional **libft**,  
providing a more comprehensive standard library while strictly following **Norminette** guidelines.

---

## Overview

This project builds on top of the original libft assignment from 42 school,  
adding additional modules focused on safer and more flexible memory and data structure management,  
without deviating from the project's original coding standards.

It provides extended utilities for dynamic memory, strings, and arrays,  
plus a lightweight garbage collector inspired by modern programming languages.

---

## Extra Modules

### `t_string` — Safe Dynamic String Type

- Provides a **dynamically resizable string type** (`t_string`) for C.
- Safe operations for:
  - Appending strings or characters
  - Trimming
  - Substring insertion
  - Repetition
  - Search and indexing
- Designed to minimize memory leaks and buffer overflows compared to traditional C strings.

### `t_vec` — Safe Dynamic Array Type

- Generic **dynamic array structure** (`t_vec`) supporting **any type** via `void *` storage.
- Features:
  - Dynamic resizing (`push`, `pop`, `insert`)
  - Reserve and shrink-to-fit memory management
  - Clear and reuse vectors efficiently
- Inspired by C++ `std::vector` and Rust `Vec<T>`, but adapted for pure C.

### Lightweight Garbage Collector

- Memory allocations are **tracked internally** using a map-based structure.
- Provides automatic deallocation at program exit via a `__attribute__((destructor))` cleanup function.
- Inspired by Rust's **Drop trait**, providing a best-effort system for avoiding memory leaks.
- Still allows **manual freeing** if needed via `ft_free`.

---

## Goals

- Enhance libft with safe, dynamic data structures.
- Reduce the risk of manual memory management errors.
- Preserve Norminette compatibility for educational consistency.
- Explore modern memory management concepts within the constraints of C.

---

## Requirements

- CC/G++
- Make
- Linux or macOS environment (POSIX systems)

---

## Building

Clone the repository:

```bash
git clone https://github.com/yourusername/libft
cd libft
make (GC=0/1 depending if you want included garbage collection)
```
Test the repository:
```bash
make test
```
