FROM ubuntu:latest
LABEL authors="sirok1"

WORKDIR /app

RUN apt-get update

RUN apt-get install -y make git cmake build-essential postgresql-server-dev-all && \
    git clone https://github.com/oatpp/oatpp.git && \
    mkdir "oatpp/build"
WORKDIR "oatpp/build"
RUN apt-get install -y gcc && \
    cmake .. && \
    make install
WORKDIR "../.."
RUN git clone https://github.com/oatpp/oatpp-swagger.git && \
    mkdir "oatpp-swagger/build"
WORKDIR "oatpp-swagger/build"
RUN cmake .. && \
    make install
WORKDIR "../.."
RUN git clone https://github.com/oatpp/oatpp-postgresql.git && \
    mkdir "oatpp-postgresql/build"
WORKDIR "oatpp-postgresql/build"
RUN cmake .. && \
    make install

WORKDIR "../.."
COPY . .
RUN mkdir "build" && \
    make

ENTRYPOINT ["top", "-b"]