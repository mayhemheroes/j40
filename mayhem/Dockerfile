FROM debian:bookworm as builder

RUN apt update && \
    DEBIAN_FRONTEND=noninteractive apt install build-essential clang -y

ADD . /j40
WORKDIR /j40/fuzz

RUN make

FROM debian:bookworm
COPY --from=builder /j40/fuzz/j40_fuzz /