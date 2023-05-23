
#include "TenantsService.hpp"

oatpp::Object<TenantsDto> TenantsService::createTenant(const oatpp::Object<TenantsDto>& dto) {

  auto dbResult = m_database->createTenat(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<TenantsDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  return result[0];

}

oatpp::Object<TenantsDto> TenantsService::updateTenant(const oatpp::Object<TenantsDto>& dto) {

  auto dbResult = m_database->updateTenant(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<TenantsDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  return result[0];

}

oatpp::Object<TenantsDto> TenantsService::getTenantById(const oatpp::String& id) {

  auto dbResult = m_database->getTenantById(id);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Tenant not found");

  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<TenantsDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

  return result[0];

}

oatpp::Object<BookingsDto> TenantsService::getBookingByTenatIdWihtTenant(const oatpp::String &id) {}(const oatpp::String& id) {

    auto dbResult = m_database->getBookingByTenatIdWihtTenant(id);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Bookings not found");

    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<BookingsDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

    return result[0];

}
oatpp::Object<PageDto<oatpp::Object<TenantsDto>>> TenantsService::getAllTenants(const oatpp::UInt32& offset, const oatpp::UInt32& limit) {

  oatpp::UInt32 countToFetch = limit;

  if(limit > 10) {
    countToFetch = 10;
  }

  auto dbResult = m_database->getAllTenants(offset, countToFetch);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

  auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<TenantsDto>>>();

  auto page = PageDto<oatpp::Object<TenantsDto>>::createShared();
  page->offset = offset;
  page->limit = countToFetch;
  page->count = items->size();
  page->items = items;

  return page;

}

oatpp::Object<StatusDto> TenantsService::deleteTenantById(const oatpp::String& tenantId) {
  auto dbResult = m_database->deleteTenantById(tenantId);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto status = StatusDto::createShared();
  status->status = "OK";
  status->code = 200;
  status->message = "Tenant was successfully deleted";
  return status;
}