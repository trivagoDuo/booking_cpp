# booking_cpp <img src="https://github.com/trivagoDuo/booking_cpp_userver/raw/dev/frontend/public/Logo.png" align='right' width="30%">

Booking service for hotels, rooms and private homes like booking.com, trivago, etc. With
personal accounts for the buyer, seller and administrators of the platform, with different variants of calculation (both at check-in and online)

## Stack

- ### Backend
    - C ++
      The prerequisite for the creation of this project
    - [oatpp](https://oatpp.io/)
      Ready service solution, to spend time only on writing the logic of the service, writing handlers and work with the database
    - [next.js](https://nextjs.org/)
      Read more in the frontend
- ### Frontend
    - [Next.js](https://nextjs.org/)
      Setting up over React with the backend, the choice fell on this particular framework because of the preender on the server side
      (for indexing by search engines), improved work with React components (will be detected only those components that need to be displayed),
      as well as the presence of routing, improved optimization and support for integration with other frameworks
    - [Eslint](https://eslint.org/)
      For fast refactoring according to predefined rules and for detecting errors while writing code
    - [Redux toolkit](https://redux-toolkit.js.org/)
      An improved version of Redux, which solves some of its problems, is a tool for managing data state and UI in JavaScript applications with a large number of entities.
    - [Tailwind](https://tailwindcss.com/)
      Offers pre-designed widgets for building a site from scratch with quick UI development, while Bootstrap comes with a set of pre-styled
      adaptive mobile components that have a defined UI set.


## Engines

It is possible to run on Linux and with Docker

## Run
### Docker dependencies 
```
docker pull ubuntu
docker pull postgres
docker pull node
```
### docker-compose
```
docker-compose up --build
```
## License
[GNU General Public License v3.0](./LICENSE)

Permissions of this strong copyleft license are conditioned on making available complete source code of
licensed works and modifications, which include larger works using a licensed work, under the same license.
Copyright and license notices must be preserved. Contributors provide an express grant of patent rights.