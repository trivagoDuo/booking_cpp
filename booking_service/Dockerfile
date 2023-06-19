FROM ubuntu:22.04 AS builder
LABEL authors="sirok1"
#Designating the work area
WORKDIR /app
#Updating repositories
RUN apt-get update
#Setting Dependencies
RUN apt-get install -y make git cmake build-essential postgresql-server-dev-all
#Copying a project into a container
COPY . .
#Installing dependencies
CMD ["./utility/install-oatpp-modules.sh"]
#Build
RUN cmake . && \
    make && \
    mkdir build && \
    cp booking_cpp-exe /build

FROM sirok1/alpine-cmake:1.0.0 AS prod
LABEL authors="sirok1"
WORKDIR /prod
COPY --from=build/booking_service /app/build ./
CMD ["./booking_cpp-exe"]