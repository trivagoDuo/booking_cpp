
#ifndef TenantsSERVICE_HPP
#define TenantsSERVICE_HPP

#include "db/TenantsDb.hpp"
#include "dto/PageDto.hpp"
#include "dto/StatusDto.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"

class TenantsService {
private:
  typedef oatpp::web::protocol::http::Status Status;
private:
  OATPP_COMPONENT(std::shared_ptr<TenantsDb>, m_database); // Inject database component
public:

  oatpp::Object<TenantsDto> createTenant(const oatpp::Object<TenantsDto>& dto);
  oatpp::Object<TenantsDto> updateTenant(const oatpp::Object<TenantsDto>& dto);
  oatpp::Object<TenantsDto> getTenantById(const oatpp::String& id);
  oatpp::Object<PageDto<oatpp::Object<TenantsDto>>> getAllTenants(const oatpp::UInt32& offset, const oatpp::UInt32& limit);
  oatpp::Object<StatusDto> deleteTenantById(const oatpp::String& id);

};

#endif
