
#ifndef BookingDB_HPP
#define BookingDB_HPP

#include "dto/TenantsDto.hpp"
#include "dto/LandlordsDto.hpp"
#include "dto/PropertysDto.hpp"
#include "dto/BookingsDto.hpp"

#include "oatpp-postgresql/orm.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient)


class BookingDb : public oatpp::orm::DbClient {
public:

    BookingDb(const std::shared_ptr<oatpp::orm::Executor>& executor)
    : oatpp::orm::DbClient(executor)
  {

    oatpp::orm::SchemaMigration migration(executor);
    migration.addFile(1 /* start from version 1 */, DATABASE_MIGRATIONS "/init.sql");
    migration.migrate(); // <-- run migrations. This guy will throw on error.

    auto version = executor->getSchemaVersion();
    OATPP_LOGD("BookingDb", "Migration - OK. Version=%d.", version);

  }

    QUERY(createTenat,
        "INSERT INTO tenants"
        "(id, username, password, name, email, phone) VALUES "
        "(uuid_generate_v4(), :tenant.username, :tenant.password, :tenant.name, :tenant.email, :tenant.phone)"
        "RETURNING *;",
        PREPARE(true),
        PARAM(oatpp::Object<TenantsDto>, tenant))

    QUERY(updateTenant,
        "UPDATE tenants "
        "SET "
        " username=:tenant.username, "
        " email=:tenant.email, "
        " password=:tenant.password, "
        " name=:tenant.name,"
        " phone=:tenant.phone "
        "WHERE "
        " id=:tenant.id "
        "RETURNING *;",
        PREPARE(true), //<-- user prepared statement!
        PARAM(oatpp::Object<TenantsDto>, tenant))

    QUERY(getTenantById,
        "SELECT * FROM tenants WHERE id=:id;",
        PREPARE(true), //<-- user prepared statement!
        PARAM(oatpp::String, id))

    QUERY(getAllTenants,
        "SELECT * FROM tenants LIMIT :limit OFFSET :offset;",
        PREPARE(true), //<-- user prepared statement!
        PARAM(oatpp::UInt32, offset),
        PARAM(oatpp::UInt32, limit))

    QUERY(deleteTenantById,
        "DELETE FROM tenants WHERE id=:id;",
        PREPARE(true), //<-- user prepared statement!
        PARAM(oatpp::String, id))

    QUERY(getBookingByTenatIdWihtTenant,
          "SELECT * FROM tenants JOIN bookings ON tenants.id = bookings.tenant_id WHERE tenants.id=:id;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::String, id))

    /*
     * Landlord query
     */

    QUERY(createLandlor,
          "INSERT INTO landlords"
          "( id, username, password, name, email, phone) VALUES "
          "( uuid_generate_v4(), :landlord.username, :landlord.password, :landlord.name, :landlord.email, :landlord.phone)"
          "RETURNING *;",
          PREPARE(true),
          PARAM(oatpp::Object<LandlordsDto>, landlord))

    QUERY(updateLandlor,
          "UPDATE landlords "
          "SET "
          " username=:landlord.username, "
          " email=:landlord.email, "
          " password=:landlord.password, "
          " name=:landlord.name,"
          " phone=:landlord.phone "
          "WHERE "
          " id=:landlord.id "
          "RETURNING *;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::Object<LandlordsDto>, landlord))

    QUERY(getLandlordById,
          "SELECT * FROM landlords WHERE id=:id;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::String, id))

    QUERY(getPropertyByLandlordIdWithLandlord,
          "SELECT * FROM landlords JOIN property ON landlords.id = property.landlord_id WHERE landlords.id=:id;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::String, id))


    QUERY(getAllLandlords,
          "SELECT * FROM landlords LIMIT :limit OFFSET :offset;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::UInt32, offset),
          PARAM(oatpp::UInt32, limit))

    QUERY(deleteLandlordById,
          "DELETE FROM landlords WHERE id=:id;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::String, id))

    QUERY(getBookingByLandlordIdWihtLandlord,
          "SELECT * FROM landlords JOIN bookings ON landlords.id = bookings.landlord_id WHERE landlords.id=:id;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::String, id))
    /*
    * Property query
    */


    QUERY(createProperty,
          "INSERT INTO property"
          "( id, landlord_id, address, city, state, country, zipcode, price_per_month, image_url, announcement_text) VALUES "
          "( uuid_generate_v4(), :property.landlord_id, :property.address, :property.city, :property.state, :property.country, :property.zipcode, :property.price_per_month, :property.image_url, :property.announcement_text)"
          "RETURNING *;",
          PREPARE(true),
          PARAM(oatpp::Object<PropertysDto>, property))

    QUERY(updateProperty,
          "UPDATE property "
          "SET "
          " address=:property.address, "
          " city=:property.city, "
          " state=:property.state, "
          " country=:property.country, "
          " zipcode=:property.zipcode,"
          " price_per_month=:property.price_per_month,"
          " image_url=:property.image_url,"
          " announcement_text=:property.announcement_text "
          "WHERE "
          " id=:property.id "
          "RETURNING *;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::Object<PropertysDto>, property))

    QUERY(getPropertyById,
          "SELECT * FROM property WHERE id=:id;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::String, id))

    QUERY(getPropertyByLandlordId,
          "SELECT * FROM property WHERE landlord_id=:id;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::String, id))

    QUERY(getPropertyByCity,
          "SELECT * FROM property WHERE city=:city;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::String, city))

    QUERY(getPropertyByState,
          "SELECT * FROM property WHERE state=:state;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::String, state))

    QUERY(getPropertyByPrice,
          "SELECT * FROM property WHERE price_per_month=:price_per_month;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::Float64, price_per_month))

    QUERY(getPropertyByAddreess,
          "SELECT * FROM property WHERE address=:address;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::String, address))

    QUERY(getAllPropertys,
          "SELECT * FROM property LIMIT :limit OFFSET :offset;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::UInt32, offset),
          PARAM(oatpp::UInt32, limit))

    QUERY(deletePropertyById,
          "DELETE FROM property WHERE id=:id;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::String, id))

    QUERY(getBookingByPropertyIdWithProperty,
          "SELECT * FROM property JOIN bookings ON property.id = bookings.house_id WHERE property.id=:id;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::String, id))

    /*
    * Bookings query
    */
    QUERY(createBooking,
          "INSERT INTO bookings"
          "( id, house_id, tenant_id, landlord_id, start_date, end_date, total_cost) VALUES "
          "( uuid_generate_v4(), :booking.house_id, :booking.tenant_id, :booking.landlord_id,:booking.start_date, :booking.end_date , :booking.total_cost) "
          "RETURNING  * ;",
          PREPARE(true),
          PARAM(oatpp::Object<BookingsDto>, booking))

    QUERY(updateBooking,
          "UPDATE bookings "
          "SET "
          " start_date=:booking.start_date, "
          " end_date=:booking.end_date, "
          " total_cost=:booking.total_cost "
          "WHERE "
          " id=:booking.id "
          "RETURNING *;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::Object<BookingsDto>, booking))

    QUERY(getBookingById,
          "SELECT * FROM bookings WHERE id=:id;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::String, id))

    QUERY(getBookingByPropertyId,
          "SELECT * FROM bookings WHERE house_id=:id;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::String, id))

    QUERY(getBookingByLandlordId,
          "SELECT * FROM bookings WHERE landlord_id=:id;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::String, id))

    QUERY(getBookingByTenatId,
          "SELECT * FROM bookings WHERE tenant_id=:id;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::String, id))

    QUERY(getAllBookings,
          "SELECT * FROM bookings LIMIT :limit OFFSET :offset;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::UInt32, offset),
          PARAM(oatpp::UInt32, limit))
    QUERY(deleteBookingById,
          "DELETE FROM bookings WHERE id=:id;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::String, id))
    QUERY(CheckBooking,
          "SELECT * FROM bookings WHERE house_id=:id and to_date(start_date,'YYYY-MM-DD') <= to_date(:startDate,'YYYY-MM-DD')   and to_date(end_date,'YYYY-MM-DD') >= to_date(:endDate,'YYYY-MM-DD')",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::String, id),
          PARAM(oatpp::String, startDate),
          PARAM(oatpp::String, endDate))

};

#include OATPP_CODEGEN_END(DbClient) //<- End Codegen

#endif
