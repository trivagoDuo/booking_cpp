FROM node:19 AS builder
LABEL authors="sirok1"
WORKDIR /app
COPY . .
RUN npm i
CMD ["npx", "next", "telemetry", "disable"]
RUN npm run build

FROM sirok1/alpine-node:1.0.0 AS prod
LABEL authors="sirok1"
WORKDIR /prod
COPY --from=build/webapp_service /app ./
CMD ["npm", "start"]