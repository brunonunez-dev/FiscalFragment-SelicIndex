#   Build (Ubuntu)
FROM ubuntu:22.04 AS builder

#   Dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    curl \
    unzip \
    xz-utils \
    pkg-config \
    liblua5.3-dev \
    libssl-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . .

#   Compile
RUN cmake -S . -B build -DCMAKE_BUILD_TYPE=Release \
    && cmake --build build --target FiscalFragment-SelicIndex \
    && cmake --build build --target unit_tests

#   Running Container
FROM debian:bookworm-slim AS runtime

#   Minimal runtime
RUN apt-get update && apt-get install -y --no-install-recommends \
    liblua5.3-0 \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

#   Copy
COPY --from=builder /app/build/FiscalFragment-SelicIndex .
COPY --from=builder /app/build/unit_tests .
COPY --from=builder /app/scripts ./scripts


CMD ["./FiscalFragment-SelicIndex"]