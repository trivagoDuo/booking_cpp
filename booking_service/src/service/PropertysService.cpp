
#include "PropertysService.hpp"

oatpp::Object<PropertysDto> PropertysService::createProperty(const oatpp::Object<PropertysDto> &dto) {

    auto dbResult = m_database->createProperty(dto);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<PropertysDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
    return result[0];

}

oatpp::Object<PropertysDto> PropertysService::updateProperty(const oatpp::Object<PropertysDto> &dto) {

    auto dbResult = m_database->updateProperty(dto);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<PropertysDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
    return result[0];

}

oatpp::Object<PropertysDto> PropertysService::getPropertyById(const oatpp::String &id) {

    auto dbResult = m_database->getPropertyById(id);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Property not found");

    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<PropertysDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

    return result[0];

}

oatpp::Object<PropertysDto> PropertysService::getPropertyByLandlordId(const oatpp::String &id) {

    auto dbResult = m_database->getPropertyByLandlordId(id);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Property not found");

    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<PropertysDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

    return result[0];

}

oatpp::Object<PropertysDto> PropertysService::getPropertyByAddreess(const oatpp::String &address) {

    auto dbResult = m_database->getPropertyByAddreess(address);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Property not found");

    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<PropertysDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

    return result[0];

}
oatpp::Object<PropertysDto> PropertysService::getPropertyByCity(const oatpp::String &city) {

    auto dbResult = m_database->getPropertyByCity(city);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Property not found");

    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<PropertysDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

    return result[0];

}
oatpp::Object<PropertysDto> PropertysService::getPropertyByPrice(const oatpp::Float64 &price) {

    auto dbResult = m_database->getPropertyByPrice(price);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Property not found");

    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<PropertysDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

    return result[0];

}
oatpp::Object<PropertysDto> PropertysService::getPropertyByState(const oatpp::String &state) {

    auto dbResult = m_database->getPropertyByState(state);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Property not found");

    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<PropertysDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

    return result[0];

}


oatpp::Object<PageDto<oatpp::Object<PropertysDto>>> PropertysService::getAllPropertys(const oatpp::UInt32& offset, const oatpp::UInt32& limit) {

    oatpp::UInt32 countToFetch = limit;

    if(limit > 10) {
        countToFetch = 10;
    }

    auto dbResult = m_database->getAllPropertys(offset, countToFetch);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

    auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<PropertysDto>>>();

    auto page = PageDto<oatpp::Object<PropertysDto>>::createShared();
    page->offset = offset;
    page->limit = countToFetch;
    page->count = items->size();
    page->items = items;

    return page;

}

oatpp::Object<StatusDto> PropertysService::deletePropertydById(const oatpp::String& id) {
    auto dbResult = m_database->deletePropertyById(id);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = "Property was successfully deleted";
    return status;
}

oatpp::Object<BookingsDto> PropertysService::getBookingByPropertyIdWithProperty(const oatpp::String &id) {

    auto dbResult = m_database-> getBookingByPropertyIdWithProperty(id);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Bookings not found");

    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<BookingsDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

    return result[0];

}