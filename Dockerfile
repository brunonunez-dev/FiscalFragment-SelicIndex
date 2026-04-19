FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    build-essential cmake git curl unzip xz-utils pkg-config \
    liblua5.3-dev libssl-dev libssl3 zlib1g ca-certificates \
    && rm -rf /var/lib/apt/lists/*


WORKDIR /app


COPY . .


RUN cmake -S . -B build -DCMAKE_BUILD_TYPE=Release \
    && cmake --build build --target FiscalFragment-SelicIndex \
    && cmake --build build --target unit_tests


WORKDIR /app/build


CMD ["./FiscalFragment-SelicIndex"]
