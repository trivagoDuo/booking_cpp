
#include "LandlordsService.hpp"

oatpp::Object<LandlordsDto> LandlordsService::createLandlord(const oatpp::Object<LandlordsDto>& dto) {

    auto dbResult = m_database->createLandlor(dto);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<LandlordsDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
    return result[0];

}

oatpp::Object<LandlordsDto> LandlordsService::updateLandlord(const oatpp::Object<LandlordsDto>& dto) {

    auto dbResult = m_database->updateLandlor(dto);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<LandlordsDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
    return result[0];

}

oatpp::Object<LandlordsDto> LandlordsService::getLandlordById(const oatpp::String& id) {

    auto dbResult = m_database->getLandlordById(id);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Landlord not found");

    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<LandlordsDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

    return result[0];

}

oatpp::Object<PageDto<oatpp::Object<LandlordsDto>>> LandlordsService::getAllLandlords(const oatpp::UInt32& offset, const oatpp::UInt32& limit) {

    oatpp::UInt32 countToFetch = limit;

    if(limit > 10) {
        countToFetch = 10;
    }

    auto dbResult = m_database->getAllLandlords(offset, countToFetch);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

    auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<LandlordsDto>>>();

    auto page = PageDto<oatpp::Object<LandlordsDto>>::createShared();
    page->offset = offset;
    page->limit = countToFetch;
    page->count = items->size();
    page->items = items;

    return page;

}

oatpp::Object<StatusDto> LandlordsService::deleteLandlordById(const oatpp::String& LandlordId) {
    auto dbResult = m_database->deleteLandlordById(LandlordId);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = "Tenant was successfully deleted";
    return status;
}