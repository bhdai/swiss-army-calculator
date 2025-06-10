FROM ubuntu:latest

RUN apt-get -y update && \
    apt-get install -y build-essential

WORKDIR /calculator_app
COPY ./ ./
RUN make clean; make
ENTRYPOINT ["./calculator"]
CMD []
