# FiscalFragment-SelicIndex

## Project Objective Description:

This project aims to provide a streamlined and transparent way to access Brazil’s Selic interest rate data through consumption of the official API, with parameters controlled by a lightweight configuration layer written in Lua (compliance.lua). By externalizing the request parameters into a domain‑specific script, the system ensures flexibility, maintainability, and ease of use for both technical and non‑technical stakeholders.

## Technologies:
 - **C++20**
 - **CMake**

## CMake Dependencies:
 - **gtest** – for unit testing  
 - **nlohmann/json** – JSON parsing and serialization  
 - **CPR (libcurl wrapper)** – HTTP client with SSL support  
 - **Sol2** – Lua bindings for C++  
 - **Lua** – scripting integration  

---
### 1. Build the Docker image:
Make sure you are in the project root (where the `Dockerfile` is located):

```bash
docker build -t fiscalfragment-selic .
```
---
### 2. Run with Docker:

```bash
docker run --rm fiscalfragment-selic
```
---
### 3. Cpp testing:

```bash
docker run --rm fiscalfragment-selic ./test_main
```
---
### 3. Lua integrity testing:

```bash
docker run --rm fiscalfragment-selic ./test_lua
```
---
## Project Tasks:
- [x] Project Structure Basic Setup
    - [x] CMake Implementation
    - [x] Unit Testing Setup
    - [x] Docker Setup
    - [x] README
- [x] Selic api consumption(SelicClient)
- [x] Parameterized Lua scripting(DSL)
- [ ] to do...
