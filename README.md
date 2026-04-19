# FiscalFragment-SelicIndex

## Technologies:
 - **c++20**
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
### 3. Unit testing:

```bash
docker run --rm fiscalfragment-selic ./unit_tests
```
---
## Project Tasks:
- [x] Project Structure Basic Setup
    - [x] CMake Implementation
    - [x] Unit Testing Setup
    - [x] Docker Setup
    - [x] README
- [x] Selic api consumption(SelicClient)    
- [ ] to do...
