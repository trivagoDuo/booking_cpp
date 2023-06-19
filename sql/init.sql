CREATE EXTENSION IF NOT EXISTS "uuid-ossp";
CREATE TABLE IF NOT EXISTS landlords (
                                         id varchar (256) PRIMARY KEY,
                                         username text NOT NULL,
                                         password text NOT NULL,
                                         name text NOT NULL,
                                         email text NOT NULL,
                                         phone text NOT NULL

);

CREATE TABLE IF NOT EXISTS property (
                                      id varchar (256) PRIMARY KEY,
                                      landlord_id varchar (256) NOT NULL REFERENCES landlords (id),
                                      address text NOT NULL,
                                      city text NOT NULL,
                                      state text NOT NULL,
                                      announcement_text text,
                                      country text NOT NULL,
                                      zipcode text NOT NULL,
                                      price_per_month float NOT NULL,
                                      image_url text NOT NULL
);

CREATE TABLE IF NOT EXISTS tenants (
                                       id varchar (256) PRIMARY KEY,
                                       username text NOT NULL,
                                       password text NOT NULL,
                                       name text NOT NULL,
                                       email text NOT NULL,
                                       phone text NOT NULL
);


CREATE TABLE IF NOT EXISTS bookings (
                                        id varchar (256) PRIMARY KEY,
                                        house_id varchar (256) NOT NULL REFERENCES property (id),
                                        tenant_id varchar (256) NOT NULL REFERENCES tenants (id),
                                        landlord_id varchar (256) NOT NULL REFERENCES landlords (id),
                                        start_date date NOT NULL,
                                        end_date date NOT NULL,
                                        total_cost float NOT NULL
);