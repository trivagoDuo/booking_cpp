
#ifndef BookingDB_HPP
#define BookingDB_HPP

#include "dto/TenantsDto.hpp"
#include "dto/LandlordsDto.hpp"
#include "dto/PropertysDto.hpp"
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
        " name=:tenant.name"
        " phone:=tenant.name"
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
          " password=:tenant.password, "
          " name=:landlord.name"
          " phone:=landlord.name"
          "WHERE "
          " id=:landlord.id "
          "RETURNING *;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::Object<LandlordsDto>, landlord))

    QUERY(getLandlordById,
          "SELECT * FROM landlords WHERE id=:id;",
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


};

#include OATPP_CODEGEN_END(DbClient) //<- End Codegen

#endif
