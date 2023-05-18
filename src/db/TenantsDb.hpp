
#ifndef TenantDB_HPP
#define TenantDB_HPP

#include "dto/TenantsDto.hpp"
#include "oatpp-postgresql/orm.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient) //<- Begin Codegen


class TenantsDb : public oatpp::orm::DbClient {
public:

    TenantsDb(const std::shared_ptr<oatpp::orm::Executor>& executor)
    : oatpp::orm::DbClient(executor)
  {

    oatpp::orm::SchemaMigration migration(executor);
    migration.addFile(1 /* start from version 1 */, DATABASE_MIGRATIONS "/init.sql");
    migration.migrate(); // <-- run migrations. This guy will throw on error.

    auto version = executor->getSchemaVersion();
    OATPP_LOGD("BookingDb", "Migration - OK. Version=%d.", version);

  }

  QUERY(createTenat,
        "INSERT INTO Tenants"
        "(id, username, password, name, email, phone) VALUES "
        "(uuid_generate_v4(), :tenant.username, :tenant.password, :tenant.name, :tenant.email, :tenant.phone)"
        "RETURNING *;",
        PREPARE(true),
        PARAM(oatpp::Object<TenantsDto>, tenant))

  QUERY(updateTenant,
        "UPDATE Tenants "
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
        "SELECT * FROM Tenants WHERE id=:id;",
        PREPARE(true), //<-- user prepared statement!
        PARAM(oatpp::String, id))

  QUERY(getAllTenants,
        "SELECT * FROM Tenants LIMIT :limit OFFSET :offset;",
        PREPARE(true), //<-- user prepared statement!
        PARAM(oatpp::UInt32, offset),
        PARAM(oatpp::UInt32, limit))

  QUERY(deleteTenantById,
        "DELETE FROM Tenants WHERE id=:id;",
        PREPARE(true), //<-- user prepared statement!
        PARAM(oatpp::String, id))

};

#include OATPP_CODEGEN_END(DbClient) //<- End Codegen

#endif //EXAMPLE_POSTGRESQL_USERDB_HPP
