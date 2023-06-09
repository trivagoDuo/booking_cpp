
#ifndef TenantsSERVICE_HPP
#define TenantsSERVICE_HPP

#include "db/BookingDb.hpp"
#include "dto/conf/PageDto.hpp"
#include "dto/conf/StatusDto.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"

class TenantsService {
private:
  typedef oatpp::web::protocol::http::Status Status;
private:
  OATPP_COMPONENT(std::shared_ptr<BookingDb>, m_database); // Inject database component
public:

  oatpp::Object<TenantsDto> createTenant(const oatpp::Object<TenantsDto>& dto);
  oatpp::Object<TenantsDto> updateTenant(const oatpp::Object<TenantsDto>& dto);
  oatpp::Object<TenantsDto> getTenantById(const oatpp::String& id);
  oatpp::Object<PageDto<oatpp::Object<TenantsDto>>> getAllTenants(const oatpp::UInt32& offset, const oatpp::UInt32& limit);
  oatpp::Object<StatusDto> deleteTenantById(const oatpp::String& id);
  oatpp::Object<BookingsDto> getBookingByTenatIdWihtTenant(const oatpp::String& id);

};

#endif
