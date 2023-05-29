FROM node:19
LABEL authors="sirok1"
WORKDIR /app

COPY . .
RUN npm i
RUN npm run build
CMD ["npm", "start"]